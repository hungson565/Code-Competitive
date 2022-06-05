// https://vnoi.info/wiki/translate/he/Number-Theory-2.md


void sieve(int N) {
    bool isPrime[N+1];
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             // Mark all the multiples of i as composite numbers
             for(int j = i * i; j <= N; j += i)
                 isPrime[j] = false;
        }
    }
}

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


//----------------------------------------

#define MAXV 1000111

bool isPrime[MAXV];
int cntPrimeFactors[MAXV];

int main() {

    memset(isPrime, true, sizeof(isPrime));
    memset(cntPrimeFactors, 0, sizeof(cntPrimeFactors));
    vector<int> primes;

    isPrime[1] = false;
    for (int i = 2; i < MAXV; i++) {
        if (!isPrime) {
            continue;
        }
        primes.push_back(i);
        for (int j = 2 * i; j < MAXV; j += i) {
            cntPrimeFactors[j]++;
        }
    }

    return 0;
}

