int main (string[] args) {
    long n = long.parse(args[1]);
    long a = 0;
    long b = 1;
    long c;
    while (b < n) {
        stdout.printf ("%ld\n", b);
        c = b;
        b = a + b;
        a = c;
        if (b < 0) {
            stdout.printf ("E: overflow %ld\n", b);
            return 0;
        }
    }
    return 0;
}
