int Factorial (int x) {
    if  (x <= 0) x = 1;
    int i = 1, f = 1 ;
    while (i <= x) {
    f *= i ;
    ++i;
    }
    return f;
}

