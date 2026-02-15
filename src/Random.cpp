#include "Random.h"

int GetRandomInt(int min, int max) {
    std::random_device rd;  // Non-deterministic seed
    std::mt19937 gen(rd()); // Pseudo-random generator

    // Define the range
    std::uniform_int_distribution<> distrib(min, max); // 0 to 99

    // Generate a random number
    int randomNumber = distrib(gen);
    return randomNumber;

}