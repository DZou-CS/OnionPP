#pragma once
#ifndef fractions_
#define fractions_
#include <iostream>
#include <cmath>

class _fractions_
{
private:
	int numerator_; int denominator_;
	char div_symbol;
public:
	fractions_::_fractions_() {};
	fractions_::_fractions_(int n, int d)
	{
		numerator_ = n;
		denominator_ = d;
	}
	bool integrity_check() {
		if (denominator_ == 0) {
			std::cerr << "error /0!" << std::endl;
			return false;
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	friend _fractions_& operator+ (const _fractions_& f1,const _fractions_& f2) {
		_fractions_ tmp(((f1.numerator_ * f2.denominator_) + (f2.numerator_ * f1.denominator_)), f1.denominator_ * f2.denominator_);
		return tmp;
	}

	friend _fractions_& operator- (const _fractions_& f1, const _fractions_& f2) {
		_fractions_ tmp(((f1.numerator_ * f2.denominator_) - (f2.numerator_ * f1.denominator_)), f1.denominator_ * f2.denominator_);
		return tmp;
	}
	
	friend _fractions_& operator* (const _fractions_& f1, const _fractions_& f2) {
		_fractions_ tmp((f1.numerator_ * f2.numerator_), (f1.denominator_ * f2.denominator_));
		return tmp;
	}
	//flip numerator and denominator of f1 then multiple them with f2
	friend _fractions_& operator/ (const _fractions_& f1, const _fractions_& f2) {
		_fractions_ tmp(((f1.denominator_ * f2.denominator_) * (f2.numerator_ * f1.numerator_)), f1.denominator_ * f2.denominator_);
		return tmp;
	}

	_fractions_& operator= (const _fractions_& f) {
		_fractions_ tmp(f.numerator_, f.denominator_);
		return tmp;
	}

	//

	friend std::ostream& operator<< (std::ostream& cout, const _fractions_& f) {
		cout << f.numerator_ << "/" << f.denominator_;
		return cout;
	 }
	std::istream& operator>> (std::istream& cin) {
		cin >> numerator_ >> div_symbol >> denominator_;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void reduce(_fractions_& fraction) {
		std::cout << "reduced :";
		if (fraction.numerator_ > fraction.denominator_) {
			int whole_number;
			whole_number = (fraction.numerator_ / fraction.denominator_);
			_fractions_ x((fraction.numerator_ - fraction.denominator_), fraction.denominator_);
			std::cout << whole_number << "(" << x << ")" << std::endl;
		}
		if (fraction.numerator_ < fraction.denominator_) {
			int new_numerator; int new_denominator;
			for (int i = 1; i == fraction.numerator_; i++) {
				std::cout << "running loop" << std::endl;
				if ((fraction.numerator_ % i == 0) && (fraction.denominator_ % i == 0)) {
					new_numerator = fraction.numerator_ / i;
					new_denominator = fraction.denominator_ / i;
					_fractions_ x(new_numerator, new_denominator);
					std::cout << x << std::endl;
				}
			}
		}
		if (fraction.numerator_ == fraction.denominator_) {
			std::cout << 1 << std::endl;
		}
	}
};

#endif // !fractions_

