#define int int64_t

const int MOD = 1e9 + 7;

int power(int x, int k) {
    if (k == 0) return 1;
    if (k == 1) return x % MOD;

    int mid = power(x, k / 2);
    mid = mid * mid % MOD;

    if (k % 2) return mid * x % MOD;
    return mid;
}

int N = 5000;
int fact[N];

void generateFact() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) fact[i] = (fact[i - 1] * i) % MOD;
}

int powerLogN(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n%2) {
        int sub = powerLogN(a, n/2);
        return (((sub*sub)%MOD)*a)%MOD;
    }

    int sub = powerLogN(a, n/2);
    return (sub*sub)%MOD;
}

int nCr(int n, int r) {
    int num = fact[n];
    int den = (fact[r] * fact[n - r]) % MOD;
    int ans = (num * powerLogN(den, MOD - 2)) % MOD;
    return ans;
}

int nAr(int n, int r) {
    int num = fact[n];
    int den = fact[n - r];
    int ans = (num * powerLogN(den, MOD - 2)) % MOD;
    return ans;
}

