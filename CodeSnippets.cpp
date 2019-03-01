/******************* Random number generation *************************/
// generate random number in a range
int getRandomNumber(int min, int max) {
    random_device rd; // get a random seed
    mt19937 eng(rd()); // Initialize mersenne twister with a random seed
    uniform_int_distribution<> distr(min, max); // create a distribution

    return distr(eng);  //generate a random number
}
