#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "longLCG.hpp"
#include <random>

TEST_CASE( "32 bit LCG: comparison with minstd_rnd", "[LCG_minstd_rand]" ) {
	unsigned int seed = 12345;
	std::minstd_rand std_rng (seed); 
	LCG_int32<48271, 2147483647> rng (seed);
	for(int i=0; i<999; i++) {
    	REQUIRE( rng() == std_rng() );
	}
}