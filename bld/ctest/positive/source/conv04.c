#include "fail.h"

void check_add( float result, unsigned line )
{
    if( result != 21 ) fail(line);
}

void check_subtract( double result, unsigned line )
{
    if( result != 13 ) fail(line);
}

void check_multiply( unsigned long int result, unsigned line )
{
    if( result != 68 ) fail(line);
}

void check_divide( char result, unsigned line )
{
    if( result != 4 ) fail(line);
}


signed char sc1;
unsigned char uc1;
char c1;
signed short ss1;
unsigned short us1;
short s1;
signed int si1;
unsigned int ui1;
int i1;
signed long int sli1;
unsigned long int uli1;
long int li1;
float f1;
double d1;
long double ld1;

signed char sc2;
unsigned char uc2;
char c2;
signed short ss2;
unsigned short us2;
short s2;
signed int si2;
unsigned int ui2;
int i2;
signed long int sli2;
unsigned long int uli2;
long int li2;
float f2;
double d2;
long double ld2;

int main( void )
{
    li1 = 17;
    c2 = 4;
    check_add( li1 + c2, __LINE__ );
    check_subtract( li1 - c2, __LINE__ );
    check_multiply( li1 * c2, __LINE__ );
    check_divide( li1 / c2, __LINE__ );
    li1 = 17;
    ss2 = 4;
    check_add( li1 + ss2, __LINE__ );
    check_subtract( li1 - ss2, __LINE__ );
    check_multiply( li1 * ss2, __LINE__ );
    check_divide( li1 / ss2, __LINE__ );
    li1 = 17;
    us2 = 4;
    check_add( li1 + us2, __LINE__ );
    check_subtract( li1 - us2, __LINE__ );
    check_multiply( li1 * us2, __LINE__ );
    check_divide( li1 / us2, __LINE__ );
    li1 = 17;
    s2 = 4;
    check_add( li1 + s2, __LINE__ );
    check_subtract( li1 - s2, __LINE__ );
    check_multiply( li1 * s2, __LINE__ );
    check_divide( li1 / s2, __LINE__ );
    li1 = 17;
    si2 = 4;
    check_add( li1 + si2, __LINE__ );
    check_subtract( li1 - si2, __LINE__ );
    check_multiply( li1 * si2, __LINE__ );
    check_divide( li1 / si2, __LINE__ );
    li1 = 17;
    ui2 = 4;
    check_add( li1 + ui2, __LINE__ );
    check_subtract( li1 - ui2, __LINE__ );
    check_multiply( li1 * ui2, __LINE__ );
    check_divide( li1 / ui2, __LINE__ );
    li1 = 17;
    i2 = 4;
    check_add( li1 + i2, __LINE__ );
    check_subtract( li1 - i2, __LINE__ );
    check_multiply( li1 * i2, __LINE__ );
    check_divide( li1 / i2, __LINE__ );
    li1 = 17;
    sli2 = 4;
    check_add( li1 + sli2, __LINE__ );
    check_subtract( li1 - sli2, __LINE__ );
    check_multiply( li1 * sli2, __LINE__ );
    check_divide( li1 / sli2, __LINE__ );
    li1 = 17;
    uli2 = 4;
    check_add( li1 + uli2, __LINE__ );
    check_subtract( li1 - uli2, __LINE__ );
    check_multiply( li1 * uli2, __LINE__ );
    check_divide( li1 / uli2, __LINE__ );
    li1 = 17;
    li2 = 4;
    check_add( li1 + li2, __LINE__ );
    check_subtract( li1 - li2, __LINE__ );
    check_multiply( li1 * li2, __LINE__ );
    check_divide( li1 / li2, __LINE__ );
    li1 = 17;
    f2 = 4;
    check_add( li1 + f2, __LINE__ );
    check_subtract( li1 - f2, __LINE__ );
    check_multiply( li1 * f2, __LINE__ );
    check_divide( li1 / f2, __LINE__ );
    li1 = 17;
    d2 = 4;
    check_add( li1 + d2, __LINE__ );
    check_subtract( li1 - d2, __LINE__ );
    check_multiply( li1 * d2, __LINE__ );
    check_divide( li1 / d2, __LINE__ );
    li1 = 17;
    ld2 = 4;
    check_add( li1 + ld2, __LINE__ );
    check_subtract( li1 - ld2, __LINE__ );
    check_multiply( li1 * ld2, __LINE__ );
    check_divide( li1 / ld2, __LINE__ );
    f1 = 17;
    sc2 = 4;
    check_add( f1 + sc2, __LINE__ );
    check_subtract( f1 - sc2, __LINE__ );
    check_multiply( f1 * sc2, __LINE__ );
    check_divide( f1 / sc2, __LINE__ );
    f1 = 17;
    uc2 = 4;
    check_add( f1 + uc2, __LINE__ );
    check_subtract( f1 - uc2, __LINE__ );
    check_multiply( f1 * uc2, __LINE__ );
    check_divide( f1 / uc2, __LINE__ );
    f1 = 17;
    c2 = 4;
    check_add( f1 + c2, __LINE__ );
    check_subtract( f1 - c2, __LINE__ );
    check_multiply( f1 * c2, __LINE__ );
    check_divide( f1 / c2, __LINE__ );
    f1 = 17;
    ss2 = 4;
    check_add( f1 + ss2, __LINE__ );
    check_subtract( f1 - ss2, __LINE__ );
    check_multiply( f1 * ss2, __LINE__ );
    check_divide( f1 / ss2, __LINE__ );
    f1 = 17;
    us2 = 4;
    check_add( f1 + us2, __LINE__ );
    check_subtract( f1 - us2, __LINE__ );
    check_multiply( f1 * us2, __LINE__ );
    check_divide( f1 / us2, __LINE__ );
    f1 = 17;
    s2 = 4;
    check_add( f1 + s2, __LINE__ );
    check_subtract( f1 - s2, __LINE__ );
    check_multiply( f1 * s2, __LINE__ );
    check_divide( f1 / s2, __LINE__ );
    f1 = 17;
    si2 = 4;
    check_add( f1 + si2, __LINE__ );
    check_subtract( f1 - si2, __LINE__ );
    check_multiply( f1 * si2, __LINE__ );
    check_divide( f1 / si2, __LINE__ );
    f1 = 17;
    ui2 = 4;
    check_add( f1 + ui2, __LINE__ );
    check_subtract( f1 - ui2, __LINE__ );
    check_multiply( f1 * ui2, __LINE__ );
    check_divide( f1 / ui2, __LINE__ );
    f1 = 17;
    i2 = 4;
    check_add( f1 + i2, __LINE__ );
    check_subtract( f1 - i2, __LINE__ );
    check_multiply( f1 * i2, __LINE__ );
    check_divide( f1 / i2, __LINE__ );
    f1 = 17;
    sli2 = 4;
    check_add( f1 + sli2, __LINE__ );
    check_subtract( f1 - sli2, __LINE__ );
    check_multiply( f1 * sli2, __LINE__ );
    check_divide( f1 / sli2, __LINE__ );
    f1 = 17;
    uli2 = 4;
    check_add( f1 + uli2, __LINE__ );
    check_subtract( f1 - uli2, __LINE__ );
    check_multiply( f1 * uli2, __LINE__ );
    check_divide( f1 / uli2, __LINE__ );
    f1 = 17;
    li2 = 4;
    check_add( f1 + li2, __LINE__ );
    check_subtract( f1 - li2, __LINE__ );
    check_multiply( f1 * li2, __LINE__ );
    check_divide( f1 / li2, __LINE__ );
    f1 = 17;
    f2 = 4;
    check_add( f1 + f2, __LINE__ );
    check_subtract( f1 - f2, __LINE__ );
    check_multiply( f1 * f2, __LINE__ );
    check_divide( f1 / f2, __LINE__ );
    f1 = 17;
    d2 = 4;
    check_add( f1 + d2, __LINE__ );
    check_subtract( f1 - d2, __LINE__ );
    check_multiply( f1 * d2, __LINE__ );
    check_divide( f1 / d2, __LINE__ );
    f1 = 17;
    ld2 = 4;
    check_add( f1 + ld2, __LINE__ );
    check_subtract( f1 - ld2, __LINE__ );
    check_multiply( f1 * ld2, __LINE__ );
    check_divide( f1 / ld2, __LINE__ );
    d1 = 17;
    sc2 = 4;
    check_add( d1 + sc2, __LINE__ );
    check_subtract( d1 - sc2, __LINE__ );
    check_multiply( d1 * sc2, __LINE__ );
    check_divide( d1 / sc2, __LINE__ );
    d1 = 17;
    uc2 = 4;
    check_add( d1 + uc2, __LINE__ );
    check_subtract( d1 - uc2, __LINE__ );
    check_multiply( d1 * uc2, __LINE__ );
    check_divide( d1 / uc2, __LINE__ );
    d1 = 17;
    c2 = 4;
    check_add( d1 + c2, __LINE__ );
    check_subtract( d1 - c2, __LINE__ );
    check_multiply( d1 * c2, __LINE__ );
    check_divide( d1 / c2, __LINE__ );
    d1 = 17;
    ss2 = 4;
    check_add( d1 + ss2, __LINE__ );
    check_subtract( d1 - ss2, __LINE__ );
    check_multiply( d1 * ss2, __LINE__ );
    check_divide( d1 / ss2, __LINE__ );
    d1 = 17;
    us2 = 4;
    check_add( d1 + us2, __LINE__ );
    check_subtract( d1 - us2, __LINE__ );
    check_multiply( d1 * us2, __LINE__ );
    check_divide( d1 / us2, __LINE__ );
    d1 = 17;
    s2 = 4;
    check_add( d1 + s2, __LINE__ );
    check_subtract( d1 - s2, __LINE__ );
    check_multiply( d1 * s2, __LINE__ );
    check_divide( d1 / s2, __LINE__ );
    d1 = 17;
    si2 = 4;
    check_add( d1 + si2, __LINE__ );
    check_subtract( d1 - si2, __LINE__ );
    check_multiply( d1 * si2, __LINE__ );
    check_divide( d1 / si2, __LINE__ );
    d1 = 17;
    ui2 = 4;
    check_add( d1 + ui2, __LINE__ );
    check_subtract( d1 - ui2, __LINE__ );
    check_multiply( d1 * ui2, __LINE__ );
    check_divide( d1 / ui2, __LINE__ );
    d1 = 17;
    i2 = 4;
    check_add( d1 + i2, __LINE__ );
    check_subtract( d1 - i2, __LINE__ );
    check_multiply( d1 * i2, __LINE__ );
    check_divide( d1 / i2, __LINE__ );
    d1 = 17;
    sli2 = 4;
    check_add( d1 + sli2, __LINE__ );
    check_subtract( d1 - sli2, __LINE__ );
    check_multiply( d1 * sli2, __LINE__ );
    check_divide( d1 / sli2, __LINE__ );
    d1 = 17;
    uli2 = 4;
    check_add( d1 + uli2, __LINE__ );
    check_subtract( d1 - uli2, __LINE__ );
    check_multiply( d1 * uli2, __LINE__ );
    check_divide( d1 / uli2, __LINE__ );
    d1 = 17;
    li2 = 4;
    check_add( d1 + li2, __LINE__ );
    check_subtract( d1 - li2, __LINE__ );
    check_multiply( d1 * li2, __LINE__ );
    check_divide( d1 / li2, __LINE__ );
    d1 = 17;
    f2 = 4;
    check_add( d1 + f2, __LINE__ );
    check_subtract( d1 - f2, __LINE__ );
    check_multiply( d1 * f2, __LINE__ );
    check_divide( d1 / f2, __LINE__ );
    d1 = 17;
    d2 = 4;
    check_add( d1 + d2, __LINE__ );
    check_subtract( d1 - d2, __LINE__ );
    check_multiply( d1 * d2, __LINE__ );
    check_divide( d1 / d2, __LINE__ );
    d1 = 17;
    ld2 = 4;
    check_add( d1 + ld2, __LINE__ );
    check_subtract( d1 - ld2, __LINE__ );
    check_multiply( d1 * ld2, __LINE__ );
    check_divide( d1 / ld2, __LINE__ );
    ld1 = 17;
    sc2 = 4;
    check_add( ld1 + sc2, __LINE__ );
    check_subtract( ld1 - sc2, __LINE__ );
    check_multiply( ld1 * sc2, __LINE__ );
    check_divide( ld1 / sc2, __LINE__ );
    ld1 = 17;
    uc2 = 4;
    check_add( ld1 + uc2, __LINE__ );
    check_subtract( ld1 - uc2, __LINE__ );
    check_multiply( ld1 * uc2, __LINE__ );
    check_divide( ld1 / uc2, __LINE__ );
    ld1 = 17;
    c2 = 4;
    check_add( ld1 + c2, __LINE__ );
    check_subtract( ld1 - c2, __LINE__ );
    check_multiply( ld1 * c2, __LINE__ );
    check_divide( ld1 / c2, __LINE__ );
    ld1 = 17;
    ss2 = 4;
    check_add( ld1 + ss2, __LINE__ );
    check_subtract( ld1 - ss2, __LINE__ );
    check_multiply( ld1 * ss2, __LINE__ );
    check_divide( ld1 / ss2, __LINE__ );
    ld1 = 17;
    us2 = 4;
    check_add( ld1 + us2, __LINE__ );
    check_subtract( ld1 - us2, __LINE__ );
    check_multiply( ld1 * us2, __LINE__ );
    check_divide( ld1 / us2, __LINE__ );
    ld1 = 17;
    s2 = 4;
    check_add( ld1 + s2, __LINE__ );
    check_subtract( ld1 - s2, __LINE__ );
    check_multiply( ld1 * s2, __LINE__ );
    check_divide( ld1 / s2, __LINE__ );
    ld1 = 17;
    si2 = 4;
    check_add( ld1 + si2, __LINE__ );
    check_subtract( ld1 - si2, __LINE__ );
    check_multiply( ld1 * si2, __LINE__ );
    check_divide( ld1 / si2, __LINE__ );
    ld1 = 17;
    ui2 = 4;
    check_add( ld1 + ui2, __LINE__ );
    check_subtract( ld1 - ui2, __LINE__ );
    check_multiply( ld1 * ui2, __LINE__ );
    check_divide( ld1 / ui2, __LINE__ );
    ld1 = 17;
    i2 = 4;
    check_add( ld1 + i2, __LINE__ );
    check_subtract( ld1 - i2, __LINE__ );
    check_multiply( ld1 * i2, __LINE__ );
    check_divide( ld1 / i2, __LINE__ );
    ld1 = 17;
    sli2 = 4;
    check_add( ld1 + sli2, __LINE__ );
    check_subtract( ld1 - sli2, __LINE__ );
    check_multiply( ld1 * sli2, __LINE__ );
    check_divide( ld1 / sli2, __LINE__ );
    ld1 = 17;
    uli2 = 4;
    check_add( ld1 + uli2, __LINE__ );
    check_subtract( ld1 - uli2, __LINE__ );
    check_multiply( ld1 * uli2, __LINE__ );
    check_divide( ld1 / uli2, __LINE__ );
    ld1 = 17;
    li2 = 4;
    check_add( ld1 + li2, __LINE__ );
    check_subtract( ld1 - li2, __LINE__ );
    check_multiply( ld1 * li2, __LINE__ );
    check_divide( ld1 / li2, __LINE__ );
    ld1 = 17;
    f2 = 4;
    check_add( ld1 + f2, __LINE__ );
    check_subtract( ld1 - f2, __LINE__ );
    check_multiply( ld1 * f2, __LINE__ );
    check_divide( ld1 / f2, __LINE__ );
    ld1 = 17;
    d2 = 4;
    check_add( ld1 + d2, __LINE__ );
    check_subtract( ld1 - d2, __LINE__ );
    check_multiply( ld1 * d2, __LINE__ );
    check_divide( ld1 / d2, __LINE__ );
    ld1 = 17;
    ld2 = 4;
    check_add( ld1 + ld2, __LINE__ );
    check_subtract( ld1 - ld2, __LINE__ );
    check_multiply( ld1 * ld2, __LINE__ );
    check_divide( ld1 / ld2, __LINE__ );
    _PASS;
}