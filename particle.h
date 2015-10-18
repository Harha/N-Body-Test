#ifndef PARTICLE_H
#define PARTICLE_H

// std includes

// nbody includes
#include "constants.h"
#include "vec3.h"

class Particle
{
public:
    Particle(Vector3 pos = Vector3(0, 0, 0), Vector3 vel = Vector3(0, 0, 0), Vector3 acc = Vector3(0, 0, 0), double mass = SOLAR_MASS) : m_pos(pos), m_vel(vel), m_acc(acc), m_mass(mass)
    {

    }

    void apply_force(const Vector3 &f, const double t, const double dt)
    {
        m_acc += f / m_mass;
        m_vel += m_acc * dt;
        m_pos += m_vel * dt;
    }

    void set_mass(const float mass)
    {
        m_mass = mass;
    }

    Vector3 get_pos() const
    {
        return m_pos;
    }

    Vector3 get_vel() const
    {
        return m_vel;
    }

    Vector3 get_acc() const
    {
        return m_acc;
    }

    double get_mass() const
    {
        return m_mass;
    }

private:
    Vector3 m_pos;
    Vector3 m_vel;
    Vector3 m_acc;
    double m_mass;
};

#endif // PARTICLE_H
