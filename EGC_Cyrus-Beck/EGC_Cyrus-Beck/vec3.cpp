#include "vec3.h"

namespace egc {
	vec3& vec3::operator =(const vec3 &srcVector) {
		x = srcVector.x;
		y = srcVector.y;
		z = srcVector.z;

		return *this;
	}

    vec3 vec3::operator +(const vec3& srcVector) const
    {
        vec3 aux;
        aux.x = this->x + srcVector.x;
        aux.y = this->y + srcVector.y;
        aux.z = this->z + srcVector.z;
        return aux;
    }
    vec3& vec3::operator +=(const vec3& srcVector)
    {
        this->x = this->x + srcVector.x;
        this->y = this->y + srcVector.y;
        this->z = this->z + srcVector.z;
        return *this;
    }
    vec3 vec3::operator *(float scalarValue) const
    {
        vec3 aux;
        aux.x = this->x * scalarValue;
        aux.y = this->y * scalarValue;
        aux.z = this->z * scalarValue;
        return aux;
    }
    vec3 vec3::operator -(const vec3& srcVector) const
    {
        vec3 aux;
        aux.x = this->x - srcVector.x;
        aux.y = this->y - srcVector.y;
        aux.z = this->z - srcVector.z;
        return aux;
    }
    vec3& vec3::operator -=(const vec3& srcVector)
    {
        this->x = this->x - srcVector.x;
        this->y = this->y - srcVector.y;
        this->z = this->z - srcVector.z;
        return *this;
    }
    vec3 vec3::operator -() const
    {
        vec3 aux;
        aux.x = this->x * -1;
        aux.y = this->y * -1;
        aux.z = this->z * -1;
        return aux;
    }
    float vec3::length() const
    {
        return (float)sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }
    vec3& vec3::normalize()
    {
        vec3 v;
        v.x = this->x / this->length();
        v.y = this->y / this->length();
        v.z = this->z / this->length();
        return v;
    }

    float dotProduct(const vec3& v1, const vec3& v2)
    {
        return (float)(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
    }
    vec3 crossProduct(const vec3& v1, const vec3& v2)
    {
        vec3 aux;
        aux.x = v1.y * v2.z - v1.z * v2.y;
        aux.y = -(v1.x * v2.z - v1.z * v2.x);
        aux.z = v1.x * v2.y - v1.y * v2.x;
        return aux;
    }
};

