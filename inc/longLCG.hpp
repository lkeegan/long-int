#include <cstdint>
#include "mpir.h"

// simple 32bit integer LCG generator
// equivalent to e.g. minstd_rand with multiplier = 48271, modulus = 2147483647
template <unsigned int multiplier, unsigned int modulus> class LCG_int32 {

protected:
	unsigned long int state_vector = 1;

public:
	LCG_int32(unsigned int seed) : state_vector(seed){};
	LCG_int32() : state_vector(1){}; // default seed if none specified
	unsigned int operator() () {
		state_vector = (state_vector * multiplier) % modulus;
		return state_vector;
	}

};


// arbitrarily large precision integer LCG generator using mpir library
class LCG_mpir {

// todo

};