#pragma once

#include "v3.h"

class ray
{

public:
	ray(){}
	ray(const point3& origin, const v3& direction): orig(origin), dir(direction) {}
	

	point3 origin() const { return orig; }
	v3 direction() const { return dir; }

	inline point3 at(double t) const {
	
		return orig + t * dir;
	}

public:
	point3 orig;
	v3 dir;

};

