#include "longLCG.hpp"

// initialise with uintmax_t values
LCG_mpir::LCG_mpir(uintmax_t i_seed, uintmax_t i_mult, uintmax_t i_mod) {
	mpz_init_set_ux (state_vector, i_seed);
	mpz_init_set_ux (multiplier, i_mult);
	mpz_init_set_ux (modulus, i_mod);	
}

// initialise with string values in base 10, e.g. "9342632134"
LCG_mpir::LCG_mpir(const char *str_seed, const char *str_mult, const char *str_mod) {
	mpz_init_set_str (state_vector, const_cast<char*>(str_seed), 10);
	mpz_init_set_str (multiplier, const_cast<char*>(str_mult), 10);
	mpz_init_set_str (modulus, const_cast<char*>(str_mod), 10);
}

LCG_mpir::~LCG_mpir() {
	mpz_clear (state_vector);
	mpz_clear (multiplier);
	mpz_clear (modulus);
}

uintmax_t LCG_mpir::operator() () {
	// state_vector = (state_vector * multiplier) % modulus;
	mpz_mul(state_vector, multiplier, state_vector);
	mpz_mod (state_vector, state_vector, modulus);
	return mpz_get_ux(state_vector); //return uintmax_t filled with LSBs of state_vector
}
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
