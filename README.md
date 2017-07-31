# longLCG
A C++ [Linear Congruential Generator (LCG)](https://en.wikipedia.org/wiki/Linear_congruential_generator) to generate pseudorandom numbers which uses arbitrarily long integer arithmetic, using the [mpir](http://mpir.org/) bignum arithmetic library. (note: work in progress)

## Background
Pseudo-random numbers are used in many applications, here we are interested in ones suitable for monte carlo simulations, which need to provide high quality random numbers.

A very simple way to generate pseudo-random numbers r is the LCG recurrence relation:

```
r = (A r + c) % m
```
An even simpler version, the [MCG, or Lehmer RNG](https://en.wikipedia.org/wiki/Lehmer_random_number_generator), sets c to zero.

An example of such a generator is the `minstd_rand` generator which uses

* A = 48271
* m = 2147483647 = 2^31 - 1

This means that r is an integer in the range `[1, 2^31-1)`, and the generator produces each number in this range exactly once before repeating the same cycle, so the period is 2^31 - 2.

For monte carlo simulations this generator is not very good: the periodic is not large enough, and subsequent numbers are correlated. These issues can be solved by

* Choose m to be very large, e.g. a 576 bit integer instead of only 32 bit.
* Discarding a number of values of r between each used value (typically a few hundred). 

This is essentially the [ranlux](luscher.web.cern.ch/luscher/ranlux/) generator, for which there is a recent [improved implementation](https://github.com/sibidanov/ranluxpp).

This code is for exploring and testing LCGs of any size.