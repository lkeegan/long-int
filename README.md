# longLCG
A C++ [Linear Congruential Generator (LCG)](https://en.wikipedia.org/wiki/Linear_congruential_generator) to generate pseudorandom numbers which uses arbitrarily long integer arithmetic, using the [mpir](http://mpir.org/) bignum arithmetic library.

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

* Choosing m to be very large
* Discarding a number of values of r between each used value

The [ranlux](luscher.web.cern.ch/luscher/ranlux/) generator is a proven high quality generator that uses a 576-bit integer for m and discards several hundred values of r between each used value, and for which there is a recent [improved implementation](https://github.com/sibidanov/ranluxpp). If you are looking for a good generator to use for monte carlo simulations, this should be the default choice.

If you are instead interested in exploring and testing LCGs of any size, then this code may be useful.