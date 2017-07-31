#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "longLCG.hpp"
#include <random>

const unsigned int seed = 123;
const int random_number_sequence_length = 9999;

//32-bit minstd_rnd
const unsigned int mod32 = 2147483647;
const unsigned int mul32 = 48271;

TEST_CASE( "32 bit LCG vs minstd_rnd", "[LCG_32bit]" ) {
	std::minstd_rand std_rng (seed); 
	LCG_int32<mul32, mod32> rng (seed);
	for(int i=0; i<random_number_sequence_length; i++) {
    	REQUIRE( rng() == std_rng() );
	}
}

TEST_CASE( "mpir LCG with char inputs vs minstd_rand", "[LCG_32bit]" ) {
	std::minstd_rand std_rng (seed);
	// convert integer params to char arrays
	char char_seed[32];
	char char_mul[32];
	char char_mod[32];
	sprintf(char_seed, "%d", seed);
	sprintf(char_mul, "%d", mul32);
	sprintf(char_mod, "%d", mod32);
	LCG_mpir rng (char_seed, char_mul, char_mod);
	for(int i=0; i<random_number_sequence_length; i++) {
    	REQUIRE( rng() == std_rng() );
	}
}

TEST_CASE( "mpir LCG with int inputs vs minstd_rand", "[LCG_32bit]" ) {
	std::minstd_rand std_rng (seed);
	LCG_mpir rng (seed, mul32, mod32);
	for(int i=0; i<random_number_sequence_length; i++) {
    	REQUIRE( rng() == std_rng() );
	}
}

//64-bit MLCG from Table 2 of doi:10.1090/s0025-5718-99-00996-5
const uint64_t mod64 = 18446744073709551557UL; //2^64 - 59
const uint64_t mul64 = 13891176665706064842UL;

TEST_CASE( "mpir LCG with int inputs vs 64 bit LCG", "[LCG_64bit]" ) {
	LCG_mpir rng (seed, mul64, mod64);
	LCG_int64<mul64, mod64> rng_int64 (seed);
	for(int i=0; i<random_number_sequence_length; i++) {
    	REQUIRE( rng() == rng_int64() );
	}
}