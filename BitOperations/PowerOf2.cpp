//So the bitwise AND of a number with it's predecessor will always be 0,
bool is_set(unsigned int number, int x) {
    return (number >> x) & 1;
}
