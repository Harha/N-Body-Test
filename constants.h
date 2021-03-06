#ifndef CONSTANTS_H
#define CONSTANTS_H

// Simulation related constants
#define SIMULATED_VOLUME_SIZE_X 512
#define SIMULATED_VOLUME_SIZE_Y 512
#define SIMULATED_VOLUME_SIZE_Z 512
#define SIMULATED_VOLUME (SIMULATED_VOLUME_SIZE_X * SIMULATED_VOLUME_SIZE_Y * SIMULATED_VOLUME_SIZE_Z)
#define SIMULATED_PARTICLES_AMOUNT 128
#define SIMULATED_TIME 10.0
#define SIMULATED_TIME_RESOLUTION 1.0 * std::pow(10, -3)

// Physics related constants
#define GRAVITATIONAL_CONSTANT 6.67408 * std::pow(10, -11)
#define SOLAR_MASS 1.98910 * std::pow(10, 30)

#endif // CONSTANTS_H
