#include <bits/stdc++.h>
using namespace std;

class Point
{

	// static int count;
	// test
private:
	int dim;
	double *val;
	static int count;

public:
	static const string comment;

	void setDim(int a);
	Point();
	Point(int);
	Point(int, double[]);
	Point(const Point &a); // copy
	~Point();			   // destructor
	int getDim() const;
	void setVal(int, double);
	double getVal(int) const;
	static int getCount(void)
	{
		return count;
	};
	void display()
	{
		cout << "(";
		for (int i = 0; i < dim - 1; i++)
			cout << val[i] << ",";
		cout << val[dim - 1] << ")" << endl;
	}
	const Point &operator=(const Point &a);
};

int Point ::count = 0;
const string Point ::comment = "fuck";

void Point ::setDim(int a)
{
	this->dim = a;
	this->val = new double[a];
	for (int i = 0; i < dim; i++)
		val[i] = 0;
}

Point ::Point()
{
	this->dim = 2;
	val = new double[2];
	val[0] = 0.0;
	val[1] = 0.0;
	count++;
}

Point ::Point(int a)
{
	this->dim = a;
	val = new double[a];
	for (int i = 0; i < sizeof(val); i++)
		val[i] = 0.0;
	count++;
}

Point ::Point(int a, double *b)
{
	this->dim = a;
	this->val = b;
	count++;
}
Point ::Point(const Point &a)
{

	this->setDim(a.getDim());
	for (int i = 0; i < this->getDim(); i++)
		this->setVal(i, a.getVal(i));
	count++;
}

Point ::~Point()
{
	count--;
}

int Point ::getDim() const
{
	return this->dim;
}

void Point ::setVal(int a, double b)
{
	this->val[a] = b;
}

double Point ::getVal(int a) const
{
	return this->val[a];
}

ostream &operator<<(ostream &s, Point &p)
{
	s << "(";
	for (int i = 0; i < p.getDim() - 1; i++)
		s << p.getVal(i) << ",";
	s << p.getVal(p.getDim() - 1) << ")" << endl;
	return s;
}

istream &operator>>(istream &s, Point &p)
{
	double temp;
	s >> temp;
	p.setDim(temp);
	for (int i = 0; i < p.getDim(); i++)
	{
		s >> temp;
		p.setVal(i, temp);
	}
	return s;
}

const Point &Point ::operator=(const Point &a)
{

	this->setDim(a.getDim());

	for (int i = 0; i < this->getDim(); i++)
		this->setVal(i, a.getVal(i));

	return *this;
}

Point operator+(Point &p, Point &p2)
{
	Point temp;
	if (p.getDim() != p2.getDim())
		return temp;
	temp.setDim(p.getDim());
	for (int i = 0; i < p.getDim(); i++)
		temp.setVal(i, p.getVal(i) + p2.getVal(i));
	return temp;
}

const Point &operator+=(Point &p, Point &p2)
{
	if (p.getDim() != p2.getDim())
		return p;
	p = p + p2;
	return p;
}

Point operator++(Point &a)
{
	for (int i = 0; i < a.getDim(); i++)
		a.setVal(i, a.getVal(i) + 1);
	return a;
}

Point operator*(Point &a, double b)
{
	for (int i = 0; i < a.getDim(); i++)
		a.setVal(i, a.getVal(i) * b);
	return a;
}

double operator-(const Point p, const Point p2)
{
	if (p.getDim() != p2.getDim())
		return 0.0;
	double ans = 0;
	for (int i = 0; i < p.getDim(); i++)
	{
		ans += (p.getVal(i) - p2.getVal(i)) * (p.getVal(i) - p2.getVal(i));
	}
	return sqrt(ans);
}

bool operator==(const Point &a, const Point &b)
{
	if (a.getDim() != b.getDim())
		return false;
	for (int i = 0; i < a.getDim(); i++)
	{
		if (a.getVal(i) != b.getVal(i))
			return false;
	}
	return true;
}

Point operator!(const Point &a)
{
	Point temp;
	temp = a;
	for (int i = 0; i < temp.getDim(); i++)
		temp.setVal(i, -temp.getVal(i));
	return temp;
}

int main()
{

	Point p1(3);
	double d[3] = {1, 2, 3};
	Point p2(3, d);
	Point p3(p2);
	cout << p1 << p2;
	p1 += p2;
	cout << p1;
	cout << "Point p1 is :";
	p1.display();
	cout << "Point p2 is :" << p2 << endl;
	cout << "Point p3 is :" << p3 << endl;

	if (p2 == p3)
		cout << "same\n";
	else
		cout << "diff\n";

	cout << "the value 3 - 1 " << p3.getVal(1) << "\n";
	p3.setVal(1, 99);
	if (p2 == p3)
		cout << "same\n";
	else
		cout << "diff\n";

	Point p4;
	// cin>>p4;
	// cout<<p4;
	Point p5 = p2 + p3;
	cout << "+" << p5;
	p5 += p2;
	p5 = p2 * 1.5;
	cout << p5;
	double qq = p2 - p3;
	cout << qq;
	p5 = !p4;
	cout << p5;
	cout << Point::getCount() << "\n";
	cout << Point ::comment << "\n";

	return 0;
}