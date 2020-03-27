# Nth-Prime
A C++ module to calculate the Nth prime, for user input N
## Usage notes
The module runs through bins of integers [2, N], [N+1, 2N], [2N+1, 3N] ... , counting primes until N primes are reached. The module stores an array of flags for each integer in the current bin: 1 if the integer is a prime, 0 if it isn't. This means that, for large-enough N, a storage error will occur because of the required size of the array. Setting the bin size to numbers larger than N reduces runtime (up to a certain point) but runs into storage errors with smaller N. 
