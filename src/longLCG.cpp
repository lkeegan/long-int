#include "longLCG.hpp"

/*
LCG_minstd_rand::LCG_minstd_rand(unsigned int seed) {
	state_vector = seed;
}

unsigned int LCG_minstd_rand::operator() (){
	state_vector = (state_vector * multiplier) % modulus;
	return state_vector;

}
*/

//TODO:
// return the next random double from the generator
// it lies in the range [0, 1)
// and is constructed from the operation
// 2^-53 * r_int
// where r_int is a random integer in [0,2^53)
// so that the full possible 53 random bits are used

	// find integers q and r such that:
	// v = 2^53 q + r
	// where r is the generated random int in [0,2^53)
	// and q is an int made from the remaining random bits in the state vector

	//void mpz_tdiv_q_2exp (mpz_t q, mpz_t state_vector_reduced, mp_bitcnt_t b)

	// if q < 2^53 we don't have enough random bits
	// so we need to first calculate the next state vector
	// then recalculate q

	//void mpz_tdiv_r_2exp (mpz_t r, mpz_t n, mp_bitcnt_t b)

	// calculate r, and construct the random double from it

	//void mpz_tdiv_r_2exp (mpz_t r, mpz_t n, mp_bitcnt_t b)

	//const double sc = 1. / (UINT64_C(1) << 53);
	//return sc * r;

	//mpz_add_ui(result, lh, rh)
