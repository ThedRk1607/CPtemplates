int sum = 0, k = 1;
while (s) {
    sum += (s % 2) * k;
    s /= 10;
    k *= 2;
}
