#include <cstdint>
#include "mpir.h"

// simple 32bit integer LCG generator
// equivalent to e.g. minstd_rand with:
// multiplier = 48271, modulus = 2147483647
template <uint32_t multiplier, uint32_t modulus> class LCG_int32 {

protected:
	// multiplying two 32 bit numbers requires up to 64 bits
	// to store the result
	uint64_t state_vector;

public:
	LCG_int32(uint32_t seed) : state_vector(seed){};
	LCG_int32() : state_vector(1){}; // default seed if none specified
	uint32_t operator() () {
		state_vector = (state_vector * multiplier) % modulus;
		return state_vector;
	}

};


// arbitrarily large precision integer LCG generator using mpir library
class LCG_mpir {

// todo

};