#pragma once

#define v3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class v3
{

public:
	v3() : e{ 0,0,0 } {}
	v3(double e0, double e1, double e2) : e{ e0,e1,e2 } {}

	inline double x() const { return e[0]; }
	inline double y() const { return e[1]; }
	inline double z() const { return e[2]; }

	v3 operator~() const { return v3(-e[0], -e[1], -e[2]); }

	double operator[](int i) const { return e[i]; }

	double& operator[](int i) { return e[i]; }

	v3& operator+=(const v3 &v) {
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];
		return *this;

	}

	v3& operator*=(const double v) {
		e[0] *= v;
		e[1] *= v;
		e[2] *= v;
		return *this;
	}

	v3& operator/=(const double t) {
		return *this *= 1 / t;
	}


	inline double length() const {
		return sqrt(length_squared());
	}

	inline double length_squared() const {
		return e[0] * e[0] + e[1] * e[1] * e[2] * e[2];
	}


public:

	double e[3];
};

using point3 = v3;
using color = v3;

inline std::ostream& operator<<(std::ostream& out, const v3& v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline v3 operator+(const v3& u, const v3& v) {
	return v3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline v3 operator-(const v3& u, const v3& v) {
	return v3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline v3 operator*(const v3& u, const v3& v) {
	return v3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline v3 operator*(double t, const v3& v) {
	return v3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline v3 operator*(const v3& v, double t) {
	return t * v;
}

inline v3 operator/(v3 v, double t) {
	return (1 / t) * v;
}

inline double dot(const v3& u, const v3& v) {
	return u.e[0] * v.e[0]
		+ u.e[1] * v.e[1]
		+ u.e[2] * v.e[2];
}

inline v3 cross(const v3& u, const v3& v) {
	return v3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
		u.e[2] * v.e[0] - u.e[0] * v.e[2],
		u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline v3 unit_vector(v3 v) {
	return v / v.length();
}
