#ifndef VEC3_H
#define VEC3_H

// std includes
#include <string>

// nbody includes
#include "math.h"

class Vector3
{
public:
    double x, y, z;

    Vector3(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z) { }

    std::string toString() const
    {
        char buffer[255];
        snprintf(buffer, 255, "vec3[%+.4f %+.4f %+.4f]", x, y, z);
        return std::string(buffer);
    }

    bool operator==(const Vector3 &other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Vector3 &other) const
    {
        return !(*this == other);
    }

    Vector3 &operator+=(const Vector3 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vector3 &operator+=(const double d)
    {
        x += d;
        y += d;
        z += d;
        return *this;
    }

    Vector3 &operator-=(const Vector3 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vector3 &operator-=(const double d)
    {
        x -= d;
        y -= d;
        z -= d;
        return *this;
    }

    Vector3 &operator*=(const double d)
    {
        x *= d;
        y *= d;
        z *= d;
        return *this;
    }

    Vector3 &operator/=(const double d)
    {
        x /= d;
        y /= d;
        z /= d;
        return *this;
    }

    Vector3 operator+(const Vector3 &other) const
    {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 operator+(const double d) const
    {
        return Vector3(x + d, y + d, z + d);
    }

    Vector3 operator-(const Vector3 &other) const
    {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3 operator-(const double d) const
    {
        return Vector3(x - d, y - d, z - d);
    }

    Vector3 operator*(const double d) const
    {
        return Vector3(x * d, y * d, z * d);
    }

    Vector3 operator/(const double d) const
    {
        return Vector3(x / d, y / d, z / d);
    }

    double length() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3 normalize() const
    {
        double l = 1.0 / length();
        return Vector3(x * l, y * l, z * l);
    }

    static double dot(const Vector3 &l, const Vector3 &r)
    {
        return l.x * r.x + l.y * r.y + l.z * r.z;
    }

    static Vector3 cross(const Vector3 &l, const Vector3 &r)
    {
        return Vector3(l.y * r.z - r.y * l.z, l.z * r.x - r.z * l.x, l.x * r.y - r.x * l.y);
    }

};

#endif // VEC3_H
