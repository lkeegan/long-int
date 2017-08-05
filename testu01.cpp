// Copyright (c) 2017 Liam Keegan
// Runs the testu01 PRNG test suite
// Any reasonable generator should pass all tests
// small crush takes a few minutes to run
// big crush around 5 hours
#include "longLCG.hpp"
#include <random>
extern "C"
{
#include "unif01.h"
#include "bbattery.h"
}
const unsigned int seed = 123;

//32-bit minstd_rnd
const unsigned int mod32 = 2147483647;
const unsigned int mul32 = 48271;
LCG_int32<mul32, mod32> rng_int32 (seed);

const uint64_t mod64 = 18446744073709551557UL; //2^64 - 59
const uint64_t mul64 = 13891176665706064842UL;

LCG_int64<mul64, mod64> rng_int64 (seed);

uint32_t rndint32 () {
	return rng_int64();
}

int main (void) {
	// run [small-crush / crush / big-crush] PRNG test suite
	unif01_Gen *gen;
	gen = unif01_CreateExternGenBits (const_cast<char*>("MCG64"), rndint32);
	bbattery_SmallCrush (gen);
	//bbattery_Crush (gen);
	//bbattery_BigCrush (gen);
	unif01_DeleteExternGen01 (gen);
	return 0;
}
