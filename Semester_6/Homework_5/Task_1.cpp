#include <iostream>

using namespace std;

class complex {
	double re, im;
public:
	complex(double re_ = 0, double im_ = 0) : re(re_), im(im_)
	{}
	double rePart()
	{
		return this->re;
	}
	double imPart()
	{
		return this->im;
	}
	complex& operator*= (complex z2)
	{
		double re1 = this->re;
		this->re = re1 * z2.re - this->im * z2.im;
		this->im = re1 * z2.im + this->im * z2.re;
		return *this;
	}
	
	friend complex operator* (complex z1, complex z2);
};
	complex operator*(complex z1, complex z2)
	{
		return z1 *= z2;
	}

int main()
{

	complex c1 = complex(2, 3);
	complex c2 = complex(4, 5);
	complex c3 = c1 * c2;
		cout << "c3 = " << c3.rePart() << " " << c3.imPart() << endl;
		cout << "c1 = " << c1.rePart() << " " << c1.imPart() << endl;
	c1*=c2;
	cout << "c1 = " << c1.rePart() << " " << c1.imPart();

	return 0;
}