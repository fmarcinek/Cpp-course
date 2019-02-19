
#include "rational.h"

// Complete these methods:

#if 1 

int rational::gcd( int n1, int n2 ) {                
    while(n2 != 0)         
    {
        int c = n1 % n2;        
        n1 = n2;      
        n2 = c;            
    }
    return n1;    
}

void rational::normalize( ) {
	
	int x = rational::gcd(num,denum); 
	if (denum==0) {
	num=1;
	}
	if (num==0) {
	denum=1;
	}
	if (num!=0 && denum!=0) {
	num/=x;
	denum/=x;
	}
	if (denum<0) {
	num*=-1;
	denum*=-1;
	}

}
	
rational operator - ( rational r ) {
	r.num*=-1;
	return r;
}

rational operator + ( const rational& r1, const rational& r2 ) {
	int x = r1.num*r2.denum + r2.num*r1.denum;
	int y = r1.denum*r2.denum;
	return rational(x,y);
}

rational operator - ( const rational& r1, const rational& r2 ) {
	int x = r1.num*r2.denum - r2.num*r1.denum;
	int y = r1.denum*r2.denum;
	return rational(x,y);
}

rational operator * ( const rational& r1, const rational& r2 ) {
	int x = r1.num*r2.num;
	int y = r1.denum*r2.denum;
	return rational(x,y);
}

rational operator / ( const rational& r1, const rational& r2 ) {
	if (r2.num != 0 && r2.denum != 0) {return r1*rational(r2.denum,r2.num);}
	if (r2.denum==0) {return rational (0,1);}
	if (r2.num==0) {return rational (1,0);}
}
	

bool operator == ( const rational& r1, const rational& r2 ) {
	return r1.num==r2.num && r1.denum==r2.denum;
}

bool operator != ( const rational& r1, const rational& r2 ) {
	return !(r1==r2);
}

std::ostream& operator << ( std::ostream& stream, const rational& r ) {
	return stream << r.num << "/" << r.denum;
}

#endif

