#include <cstdint>
#include "mpir.h"

// simple 32bit integer LCG generator
// equivalent to e.g. minstd_rand with choice:
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

// simple 64bit integer LCG generator
// requires __uint128_t 128 bit integer type
template <uint64_t multiplier, uint64_t modulus> class LCG_int64 {

protected:
	// multiplying two 64 bit numbers requires up to 128 bits
	// to store the result
	__uint128_t state_vector;

public:
	LCG_int64(uint64_t seed) : state_vector(seed){};
	LCG_int64() : state_vector(1){}; // default seed if none specified
	uint64_t operator() () {
		state_vector = (state_vector * multiplier) % modulus;
		return state_vector;
	}

};

// arbitrarily large precision integer LCG generator using mpir library
class LCG_mpir {

protected:
	mpz_t state_vector;
	mpz_t multiplier;
	mpz_t modulus;

public:
	LCG_mpir(uintmax_t i_seed, uintmax_t i_mult, uintmax_t i_mod);
	LCG_mpir(const char *str_seed, const char *str_mult, const char *str_mod);
	~LCG_mpir();
	uintmax_t operator() ();
};