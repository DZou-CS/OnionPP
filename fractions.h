#pragma once
#ifndef fractions_
#define fractions_
#include <ostream>
#include <string>

class _fractions_
{
private:
	int numerator_; int denominator_;
public:
	fractions_::_fractions_() {};
	fractions_::_fractions_(int n, int d) 
	{
		numerator_ = n;
		denominator_ = d;
	}

	
	friend _fractions_& operator+ (const _fractions_& f1,const _fractions_& f2) {
		_fractions_ tmp(((f1.numerator_ * f2.denominator_) + (f2.numerator_ * f1.denominator_)), f1.denominator_ * f2.denominator_);
		return tmp;
	}

	friend _fractions_& operator- (const _fractions_& f1, const _fractions_& f2) {
		_fractions_ tmp(((f1.numerator_ * f2.denominator_) - (f2.numerator_ * f1.denominator_)), f1.denominator_ * f2.denominator_);
		return tmp;
	}
	
	friend _fractions_& operator* (const _fractions_& f1, const _fractions_& f2) {
		_fractions_ tmp(((f1.numerator_ * f2.denominator_) * (f2.numerator_ * f1.denominator_)), f1.denominator_ * f2.denominator_);
		return tmp;
	}
	//flip numerator and denominator of f1 then multiple them with f2
	friend _fractions_& operator/ (const _fractions_& f1, const _fractions_& f2) {
		_fractions_ tmp(((f1.denominator_ * f2.denominator_) * (f2.numerator_ * f1.numerator_)), f1.denominator_ * f2.denominator_);
		return tmp;
	}

/*    //not working, copied a template online
	friend ostream&  operator<< (ostream& out,const _fractions_& f){
		 out <<  (f.numerator_, f.denominator_);
		return out;
	}
*/
};

#endif // !fractions_
