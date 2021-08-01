using Gee;
int main (string[] args) {
    long n_max = long.parse(args[1]);
    var p = new ArrayList<long> ();
    for (long n = 2; n < n_max; n++) {
        bool flag_prime = true;
        // search for all pimes found
        foreach (long i in p) {
            long n_div_i = n / i;
            long n_mod_i = n % i;
            if (n_mod_i == 0) {
                flag_prime = false;
                break; // found not to be prime
            }
            if (n_div_i < i) {
                break; // no use doing more i-loop if n < i*i
            }
        }
        if (flag_prime == true) {
            p.add(n);
        }
    }
    foreach (long i in p) {
        stdout.printf ("%lld\n", i);
    }
    return 0;
}
