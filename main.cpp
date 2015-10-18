// std includes
#include <iostream>
#include <vector>

// nbody includes
#include "macros.h"
#include "constants.h"
#include "vec3.h"
#include "particle.h"

int main(int argc, char *argv[])
{
    LOG("N-Body Simulation.");
    LOG("Simulated particles: " << SIMULATED_PARTICLES_AMOUNT);
    LOG("Simulated volume: " << SIMULATED_VOLUME);
    LOG("Simulated time: " << SIMULATED_TIME);
    LOG("Simulated time resolution: " << SIMULATED_TIME_RESOLUTION);

    LOG("Allocating memory for particles...");
    std::vector<Particle> list_particles_init;
    std::vector<Particle> list_particles_remv;
    list_particles_init.reserve(SIMULATED_PARTICLES_AMOUNT);
    list_particles_remv.reserve(SIMULATED_PARTICLES_AMOUNT);

    LOG("Populating the space with particles...");
    for (size_t i = 0; i < SIMULATED_PARTICLES_AMOUNT; i ++)
    {
        Particle p(Vector3(random_dis(-SIMULATED_VOLUME_SIZE_X, SIMULATED_VOLUME_SIZE_X), random_dis(-SIMULATED_VOLUME_SIZE_Y, SIMULATED_VOLUME_SIZE_Y), random_dis(-SIMULATED_VOLUME_SIZE_Z, SIMULATED_VOLUME_SIZE_Z)));
        p.set_mass(random_dis(1.0, SOLAR_MASS));
        list_particles_init.push_back(p);
    }

    LOG("Initializing simulation related variables...");
    double t = 0.0;
    const double dt = SIMULATED_TIME_RESOLUTION;
    const double tmax = SIMULATED_TIME;
    const double G = GRAVITATIONAL_CONSTANT;

    LOG("Running the simulation...");
    while (t < tmax)
    {
        for (auto &p1 : list_particles_init)
        {
            for (auto &p2 : list_particles_init)
            {
                // Get the memory address of both particles
                Particle *p1_pointer = &p1;
                Particle *p2_pointer = &p2;
                // Check if they are the same object
                if (p1_pointer == p2_pointer)
                {
                    continue;
                }
                // Get the vector from p1 to p2
                Vector3 r = p2.get_pos() - p1.get_pos();
                // Get the distance from p1 to p2
                double d = r.length();
                // Calculate the gravitational force on p2 due to p1
                Vector3 F = r.normalize() * (-G * (p1.get_mass() * p2.get_mass()) / (d * d));
                // Apply the force to p2
                p2.apply_force(F, t, dt);
            }
        }
        t += dt;
    }

    return 0;
}
