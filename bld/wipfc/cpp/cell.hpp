/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2009-2018 The Open Watcom Contributors. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  A single cell (part of a page)
*
* Cells are written in document order
* The local dictionary can be empty, but not text
*
****************************************************************************/

#ifndef CELL_INCLUDED
#define CELL_INCLUDED

#include <cstdio>
#include <vector>
#include "dataenc.hpp"
#include "element.hpp"


class OutFile;

class Cell : public DataEncode {
    typedef STD1::uint8_t   byte;
    typedef STD1::uint16_t  word;
    typedef STD1::uint32_t  dword;

public:
    Cell( std::size_t m) : _maxDictSize( m ) { };
    ~Cell() { };

    enum Data {
        END_PARAGRAPH   = 0xFA,
        CENTER          = 0xFB,
        TOGGLE_SPACING  = 0xFC,
        LINE_BREAK      = 0xFD,
        SPACE           = 0xFE,
        ESCAPE          = 0xFF
    };

    //add a word to the local dictionary
    void addTextToLD( word index );
    //get a Local Dictionary index for a word
    byte LDIndex( word index );
    //set the cell's index (position in the list of cells)
    void setIndex( std::size_t i ) { _index = i; };
    std::size_t index() const { return _index; };
    //is the local dictionary full (time for a new cell)?
    bool dictFull() const { return _localDictionary.size() == _maxDictSize; };
    //add an element to this cell's list
    void addElement( Element* element ) { _elements.push_back( element ); };
    //build the encoded text
    void build( OutFile* out );
    //write the cell to the file
    dword write( OutFile* out ) const;
    OutFile* out() { return _out; };
private:
    Cell( const Cell& rhs );                //no copy
    Cell& operator=( const Cell& rhs );     //no assignment

    std::vector< word >     _localDictionary;   //indexes into global dictionary
    typedef std::vector< word >::iterator LDIter;
    typedef std::vector< word >::const_iterator ConstLDIter;
    std::vector< Element* > _elements;          //elements in this cell
    typedef std::vector< Element* >::iterator ElementIter;
    typedef std::vector< Element* >::const_iterator ConstElementIter;
    std::size_t             _maxDictSize;
    std::size_t             _index;             //index of this cell in cell array
    OutFile*                _out;
};

/*
// EscSeq:
struct EscSeq {
    STD1::uint8_t esc;                  //=0xFF
    STD1::uint8_t size;                 //2 + optional arguments
    STD1::uint8_t type;
    //variable length data follows:
*/
/*
Type    Meaning
0x01:   unknown

0x02:   set left margin of current line
        Generated by: lm, li, dt, dd, dthd, ddhd
0x11:   set left margin and start new line
        Generated by: dd
0x12:   set left margin fit
        Generated by: dd if new margin >= dt margin
        Arguments:
            STD1::uint8_t margin; in spaces, 0 == no margin

0x03:   set right margin
        Generated by: rm
        Arguments:
            STD1::uint8_t margin; in spaces, 1 == no margin

0x04:   change style
        Generated by: hp#, ehp#
        Arguments:
            STD1::uint8_t style;
                0 returns to plain text
                1 italic            (same as :hp#.)
                2 bold              (same as :hp#.)
                3 bold italic       (same as :hp#.)
                4 underscored       (same as :hp#-1.)
                5 italic underscored(same as :hp#-1.)
                6 bold underscored  (same as :hp#-1.)
                7 bold italic underscored

0x05:   beginning of cross reference
        Generated by: link reftype=hd
        Arguments:
            STD1::uint16_t tocIndex;
            STD1::uint8_t flag1;
            STD1::uint8_t flag2;
        The optional flag bytes describe the size, position and
        characteristics of the window created when the cross-reference
        is followed.
        Flag1 bit 7: 'split' window
              bit 6: autolink
              bit 3: window controls specified
              bit 2: viewport ** 1
              bit 1: target size supplied
              bit 0: target position supplied
        Flag2 bit 0: ?
              bit 1: dependent
              bit 2: group supplied

0x06:   unknown

0x07:   link to footnote (:fn. tag)
        Generated by: link
        Arguments:
            STD1::uint16_t tocIndex;  // toc entry number of text

0x08:   end link hypertext
        Generated by: elink

0x09:   unknown

0x0A:   unknown

0x0B:   begin monospaced example (char graphics)
        Generated by: cgraphics, xmp

0x0C:   end monospace example (char graphics)
        Generated by: ecgraphics, exmp

0x0D:   special text colors
        Generated by: hp4, hp8, hp9, ehp4, ehp8, ehp9
        Arguments:
            STD1::uint8_t color
                0: default color
                1,2,3: same as :hp4,8,9.

0x0E:   Bitmap image (not hypergraphic)
        Generated by: artwork
        Arguments:
            STD1::uint8_t flag;
                4: runin
                3: fit (scale) to window
                2: align center
                1: align right
                0: align left (default)
            unsigned long bitmap_offset;
        Note: first bitmap always has offset 0

0x0F:   Image map
        Arguments:
            STD1::uint8_t subcode;
        Subcodes:
            DEFINE = 0; (define as hypergraphic)
                Generated by: artwork
                STD1::uint8_t align; (see above)
                unsigned long offset; (of bitmap)
            PT_HDREF = 1;
            PT_FNREF = 2;
                Define partial bitmap as hypergraphic link to footnote panel
                Generated by: link
                STD1::uint16_t index; (toc or resource to link to)
                STD1::uint16_t xorg;
                STD1::uint16_t yorg;
                STD1::uint16_t width;
                STD1::uint16_t height;
            PT_SPREF = 3;
            HDREF = 4;
            FNREF = 5;
                Define full bitmap as hypergraphic link to footnote panel
                Generated by: link
                STD1::uint16_t index; (toc or resource to link to)
            SPREF = 6;
            LAUNCH = 7;
                Define full bitmap as hypergraphic link to app
                Generated by: link
                STD1::uint8_t  reserved; (=0)
                char           launchString;
            PT_LAUNCH = 8;
                Define partial bitmap as hypergraphic link to app
                Generated by: link
                STD1::uint8_t  reserved; (=0)
                STD1::uint16_t xorg;
                STD1::uint16_t yorg;
                STD1::uint16_t width;
                STD1::uint16_t height;
                char           launchString;
            INFORM = 9;
                Define full bitmap as hypergraphic sending message to app
                Generated by: link
                STD1::uint16_t resNumber;
            PT_INFORM = 10;
                Define partial bitmap as hypergraphic sending message to app
                Generated by: link
                STD1::uint16_t resNumber;
                STD1::uint16_t xorg;
                STD1::uint16_t yorg;
                STD1::uint16_t width;
                STD1::uint16_t height;
            // ?? 11 ??
            EXTERN_PT_HDREF = 12;
                Define partial bitmap as hypergraphic
                Generated by: link
                STD1::uint16_t index; (toc or resource to link to)
                STD1::uint16_t xorg;
                STD1::uint16_t yorg;
                STD1::uint16_t width;
                STD1::uint16_t height;
            EXTERN_PT_SPREF = 13;
            EXTERN_HDREF = 14;
                Define full bitmap as hypergraphic link to panel
                Generated by: link
                STD1::uint16_t index; (toc or resource to link to)
            EXTERN_SPREF = 15;
            GLOBAL_HDREF = 16;
                Define full bitmap as hypergraphic linking to panel in external database
                Generated by: link
                STD1::uint16_t dbIndex;
                STD1::uint8_t  idSize;
                char           id[idSize]
            GLOBAL_PT_HDREF = 17;
                Define partial bitmap as hypergraphic linking to panel in external database
                Generated by: link
                STD1::uint16_t dbIndex;
                STD1::uint8_t  idSize;
                STD1::uint16_t xorg;
                STD1::uint16_t yorg;
                STD1::uint16_t width;
                STD1::uint16_t height;
                char           id[idSize]

0x10:   Start link to launch app
        Generated by: link, reftype=launch
        Arguments:
            STD1::uint8_t reserved;          //=0
            char launchString[size - 3];

0x13:   Set foreground color
        Generated by: color
0x14:   Set background color
        Generated by: color
        Arguments:
            STD1::uint8_t color;
                0 - default
                1 - blue
                2 - red
                3 - pink
                4 - green
                5 - cyan
                6 - yellow
                7 - neutral
                8 - dark gray
                9 - dark blue
               10 - dark red
               11 - dark pink
               12 - dark green
               13 - dark cyan
               14 - black
               15 - pale gray

0x15:   tutorial
        Generated by: h1 - h6
        Arguments:
            char name[size - 2]

0x16:   start link sending information to app
        Generated by: link reftype=inform
        Arguments:
            STD1::uint16_t resNumber;

0x17:   hide text
        Generated by: hide
        Arguments:
            STD1::uint8_t key[];
                key required to show text

0x18:   end of hidden text
        Generated by: ehide

0x19:   change font
        Generated by: font
        Arguments:
            STD1::uint8_t fontIndex;

0x1A:   begin :lines. sequence.
        Generated by: lines, fig
        Arguments:
            STD1::uint8_t alignment;
                1 = left
                2 = right
                4 = center

0x1B:   end :lines. sequence.
        Generated by: elines, efig

0x1C:   Set left margin to current position. Margin is reset at end of paragraph.
        Generated by: nt

0x1D:   Start external link by resource id
        Generated by: link
        Arguments:
            STD1::uint16_t resourceId;

0x1F:   Start external link in external database
        Generated by: link reftype=hd database=...
        Arguments:
            STD1::uint8_t dbIndex;
            STD1::uint8_t size;
            char          id[size];

0x20:   :ddf.
        Arguments:
            STD1::uint16_t res;
                value of res attribute

0x21:   :acviewport.
        Arguments:
            STD1::uint8_t    reserved, always 0
            STD1::uint8_t    bytes of text
            STD1::uint16_t   objectid
            STD1::uint8_t    length of objectname + 1
            char            length - 1 bytes of objectname
            STD1::uint8_t    length of dll name + 1
            char            length - 1 bytes of dll name
            STD1::uint8_t    length of objectinfo + 1
            char            length - 1 bytes of objectinfo
        Optional (if position or size specified):
            STD1::uint8_t    flag1 (bit1: origin, bit2: size) upper nibble always 0xC?
            STD1::uint8_t    flag2 always 0
            PanelOrigin     if flag1:bit1
            PanelSize       if flag1:bit2
*/

#endif //CELL_INCLUDED
