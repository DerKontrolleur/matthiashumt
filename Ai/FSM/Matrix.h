#pragma once

#include "Globals.h"
#include "Vector.h"

template <typename temp>
struct Matrix3X3
{
public:
	temp a11, a12, a13;
	temp a21, a22, a23;
	temp a31, a32, a33;

public:
	inline Matrix3X3() : a11(0), a12(0), a13(0), a21(0), a22(0), a23(0), a31(0), a32(0), a33(0) {}
	inline Matrix3X3(const temp& t) : a11(t), a12(t), a13(t), a21(t), a22(t), a23(t), a31(t), a32(t), a33(t) {}
	inline Matrix3X3(const temp& b11, const temp& b12, const temp& b13, const temp& b21, const temp& b22, const temp& b23, const temp& b31, const temp& b32, const temp& b33) : a11(b11), a12(b12), a13(b13), a21(b21), a22(b22), a23(b23), a31(b31), a32(b32), a33(b33) {}

	inline void Set(const temp& t) {a11 = t, a12 = t, a13 = t, a21 = t, a22 = t, a23 = t, a31 = t, a32 = t, a33 = t}
	inline void Set(const temp& b11, const temp& b12, const temp& b13, const temp& b21, const temp& b22, const temp& b23, const temp& b31, const temp& b32, const temp& b33) {a11 = b11, a12 = b12, a13 = b13, a21 = b21, a22 = b22, a23 = b23, a31 = b31, a32 = b32, a33 = b33}

	inline Matrix3X3(const Matrix3X3<temp>& m)
	{
		this->a11 = m.a11;
		this->a12 = m.a12;
		this->a13 = m.a13; 
		this->a21 = m.a21;
		this->a22 = m.a22;
		this->a23 = m.a23;
		this->a31 = m.a31; 
		this->a32 = m.a32; 
		this->a33 = m.a33;
	}

	inline Matrix3X3<temp>& operator=(const Matrix3X3<temp>& m)
	{
		if(this == &m)
			return *this;

		this->a11 = m.a11;
		this->a12 = m.a12;
		this->a13 = m.a13; 
		this->a21 = m.a21;
		this->a22 = m.a22;
		this->a23 = m.a23;
		this->a31 = m.a31; 
		this->a32 = m.a32; 
		this->a33 = m.a33;

		return *this;
	}

	inline Matrix3X3<temp>& operator*(const temp& t)
	{
		return Matrix3X3<temp>
			(
				t * this->a11;
				t * this->a12;
				t * this->a13; 
				t * this->a21;
				t * this->a22;
				t * this->a23;
				t * this->a31; 
				t * this->a32; 
				t * this->a33;
			);
	}

	inline void operator*=(const temp& t)
	{
		this->a11 *= t;
		this->a12 *= t;
		this->a13 *= t; 
		this->a21 *= t;
		this->a22 *= t;
		this->a23 *= t;
		this->a31 *= t; 
		this->a32 *= t; 
		this->a33 *= t;
	}

	inline Vector3D<temp>& operator*(const Vector3D<temp>& v)
	{
		return Vector3D<temp>
			(
				v.X = this->a11 * v.X + this->a12 * v.Y + this->a13 * v.Z; 

				v.Y = this->a21 * v.X + this->a22 * v.Y + this->a23 * v.Z;

				v.Z = this->a21 * v.X +  this->a22 * v.Y +  this->a23 * v.Z;
			);
	}

	inline temp GetDeterminant()
	{
		return a11*a22*a33 + a12*a23*a31 + a13*a21*a32 - a31*a22*a13 - a32*a23*a11 - a33*a21*a12;
	}

	inline void Transpose()
	{
		Matrix3X3<temp> temp(*this);

		this->a12 = temp.a21;
		this->a13 = temp.a31;
		this->a21 = temp.a12;
		this->a23 = temp.a32;
		this->a31 = temp.a13; 
		this->a32 = temp.a23; 
	}
};

template <typename temp>
inline ostream& operator<<(ostream& os, const Matrix3X3<temp>& t)
{
	os << "a11: " << t.a11 << " a12: " << t.a12 << " a13: " << t.a13 << endl
		<< "a21: " << t.a21 << " a22: " << t.a22 << " a23: " << t.a23 << endl
		<< "a31: " << t.a31 << " a32: " << t.a32 << " a33: " << t.a33;

	return os;
}

template <typename temp>
inline ostream& operator<<(ostream& os, const Matrix3X3<temp>* t)
{
	os << "a11: " << t->a11 << " a12: " << t->a12 << " a13: " << t->a13 << endl
		<< "a21: " << t->a21 << " a22: " << t->a22 << " a23: " << t->a23 << endl
		<< "a31: " << t->a31 << " a32: " << t->a32 << " a33: " << t->a33;

	return os;
}


template <typename temp>
struct Matrix2X2
{
public:
	temp a11, a12;
	temp a21, a22;

public:
	inline Matrix2X2() : a11(0), a12(0), a21(0), a22(0) {}
	inline Matrix2X2(const temp& t) : a11(t), a12(t), a21(t), a22(t) {}
	inline Matrix2X2(const temp& b11, const temp& b12, const temp& b21, const temp& b22) : a11(b11), a12(b12), a21(b21), a22(b22) {}

	inline void Set(const temp& t) {a11 = t, a12 = t, a21 = t, a22 = t}
	inline void Set(const temp& b11, const temp& b12, const temp& b21, const temp& b22) {a11 = b11, a12 = b12, a21 = b21, a22 = b22}


	inline Matrix2X2(const Matrix2X2<temp>& m)
	{
		this->a11 = m.a11;
		this->a12 = m.a12;
		this->a21 = m.a21;
		this->a22 = m.a22;
	}

	inline Matrix2X2<temp>& operator=(const Matrix2X2<temp>& m)
	{
		if(this == &m)
			return *this;

		this->a11 = m.a11;
		this->a12 = m.a12;
		this->a21 = m.a21;
		this->a22 = m.a22;

		return *this;
	}

	inline Matrix2X2<temp>& operator*(const temp& t)
	{
		return Matrix2X2<temp>
			(
				t * this->a11;
				t * this->a12;
				t * this->a21;
				t * this->a22;
			);
	}

	inline void operator*=(const temp& t)
	{
		this->a11 *= t;
		this->a12 *= t;
		this->a21 *= t;
		this->a22 *= t;
	}

	inline Matrix2X2<temp>& operator*(const Vector2D<temp>& v)
	{
		return Vector3D
			(
				v.X = this->a11 * v.X + this->a12 * v.Y; 
				v.Y = this->a21 * v.X + this->a22 * v.Y;
			);
	}

	inline temp GetDeterminant()
	{
		return a11*a22 - a12*a21;
	}

	inline void Transpose()
	{
		Matrix2X2<temp> temp(*this);

		this->a12 = temp.a21;
		this->a21 = temp.a12;
	}

	inline void Inverse()
	{
		temp determinant = this->GetDeterminant(); 

		if(determinant != 0)
		{
			this->a12 *= -1;
			this->a21 *= -1;
			*this *= (1/determinant);
		}
		else
			cout << "Matrix not inversible" << endl;
	}
};

template <typename temp>
inline ostream& operator<<(ostream& os, const Matrix2X2<temp>& t)
{
	os << "a11: " << t.a11 << " a12: " << t.a12 << endl
		<< "a21: " << t.a21 << " a22: " << t.a22;

	return os;
}

template <typename temp>
inline ostream& operator<<(ostream& os, const Matrix2X2<temp>* t)
{
	os << "a11: " << t.a11 << " a12: " << t.a12 << endl
		<< "a21: " << t.a21 << " a22: " << t.a22;

	return os;
}

/*const Matrix2X2<double>* Rotate(int degree)
{
	return &Matrix2X2<double>(cos(degree), -sin(degree), sin(degree), cos(degree));
}*/