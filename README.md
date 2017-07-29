# longLCG
A C++ Linear Congruential pseudorandom number Generator (LCG) which uses arbitrarily long integer arithmetic, using the [mpir](http://mpir.org/) bignum arithmetic library.

## Background
Pseudo-random numbers are used in many applications, here we are interested in ones suitable for monte carlo simulations, which need to be statistically proven.

A very simple and old way to generate pseudo-random numbers r is the recurrence relation:

```
r -> A r % m
```

An example of such a generator is the `minstd_rand` generator which uses A = 48271, m = 2147483647, where r is a 32-bit integer.

For monte carlo simulations this generator is not very good: the periodic is not large enough, and subsequent numbers are correlated. These issues can be solved by

* Choosing A, r and m to be very large, e.g. 576 bit integers instead of only 32 bit.
* Discarding a number of values of r between each used value (typically a few hundred). 

This is essentially the [ranlux](luscher.web.cern.ch/luscher/ranlux/) generator, for which there is a recent [improved implementation](https://github.com/sibidanov/ranluxpp).

This code is for exploring and testing LCGs of any size.