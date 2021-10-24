#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*Clasa in care vom rezolva problema, campurile sunt n,
numarul de bancnote, instructiunea dupa care ne vom ghida
si constanta cu care vom aplica operatia de modulo.
*/
class Gigel {
 private:
    long long  n;
    static const int kt = 1e9 + 7;
    int instruction;

 public:
    // citirea din fisier
    explicit Gigel(ifstream &f) {
        f >> instruction >> n;
    }
    // exponentierea logaritmica
    long long fast_pow(long long base, long long exponent, int mod) {
        if (!exponent) {
            return 1;
        }
        long long  aux = 1;
        while (exponent != 1) {
            if (exponent % 2 == 0) {
                base = (1LL * base * base) % mod;
                exponent /= 2;
            } else {
                aux = (1LL * aux * base) % mod;
                exponent--;
            }
        }
        return (1LL * aux * base) % mod;
    }
    long long get_result() {
        if (instruction == 1) {
            return (fast_pow(2, n - 1, kt) * 5) % kt;
        }
         /*
        Efectiva implementare a algoritmului DP.
        Pe linia 0 vom avea bancnotele.
         */
        if (instruction == 2) {
            long long **dp;
            dp = new long long*[n + 1];
            for (long long  i = 0; i < n + 1; ++i) {
                dp[i] = new long long[5];
            }
            dp[0][0] = 10;
            dp[0][1] = 50;
            dp[0][2] = 100;
            dp[0][3] = 200;
            dp[0][4] = 500;
            for (int j = 0; j < 5; ++j) {
                dp[1][j] = 1;
            }
            for (int i = 2; i < n + 1; ++i) {
                for (int j = 0; j < 5; ++j) {
                    dp[i][j] = 0;
                }
            }
            for (int i = 2; i < n + 1; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (dp[0][j] == 10) {
                        dp[i][j] += dp[i - 1][1] +
                                    dp[i - 1][2] + dp[i - 1][4];
                        dp[i][j] %= kt;
                    } else if (dp[0][j] == 50) {
                        dp[i][j] += dp[i - 1][0] + dp[i - 1][3];
                        dp[i][j] %= kt;
                    } else if (dp[0][j] == 100) {
                        dp[i][j] += dp[i - 1][0] + dp[i - 1][3] +
                                    dp[i - 1][2];
                        dp[i][j] %= kt;
                    } else if (dp[0][j] == 200) {
                        dp[i][j] += dp[i - 1][1] + dp[i - 1][4];
                        dp[i][j] %= kt;
                    } else if (dp[0][j] == 500) {
                        dp[i][j] += dp[i - 1][3];
                        dp[i][j] %= kt;
                    }
                }
            }
            return (dp[n][0] + dp[n][1] + dp[n][2] +
                    dp[n][3] + dp[n][4]) % kt;
        }
        return 0;
    }
};
// Please always keep that simple main function.
int main() {
    ifstream f("bani.in");
    ofstream g("bani.out");
    Gigel myGigel(f);
    g << myGigel.get_result();
    f.close();
    g.close();
}
