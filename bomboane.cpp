#include <bits/stdc++.h>
#include <fstream>

/*
    Clasa in care vom rezolva problema.
    Campurile sunt N si M, numarul de copii si numarul de bomboane.
    Constanta cu care vom face mod.
    Vectorul cu intervalele specifice fiecarui copil(Explicat in README)
*/
class Candy {
 private:
    int N, M;
    const int kt = 1e9 + 7;
    std :: vector<std :: vector<int>> intervals;

 public:
    // Citirea din fisier
    explicit Candy(std :: ifstream &f) {
        f >> N >> M;
        for (int i = 0; i < N; ++i) {
            std :: vector<int> auxV;
            int aux;
            f >> aux;
            auxV.push_back(aux);
            f >> aux;
            auxV.push_back(aux);
            intervals.push_back(auxV);
        }
    }
    /*
        Efectiva implementare a algoritmului DP.
        Pe linia 0 se afla 0.
        Explicatia algoritmului se afla in README.
    */
    int get_Result() {
        std :: vector<int> capacity;
        int sum = 0;
        for (std :: vector<int> it : intervals) {
            M -= it[0];
            sum += it[1];
        }
        if (sum == M) {
            return 1;
        } else if (sum < M) {
            return 0;
        }
        long long **dp;
        dp = new long long*[N + 1];
        for (long long i = 0; i < N + 1; i++) {
            dp[i] = new long long[M + 1];
        }
        for (long long i = 0; i < N + 1; ++i) {
            dp[i][0] = 1;
        }
        for (long long j = 0; j < M + 1; ++j) {
            dp[0][j] = 0;
        }
        for (long long j = 0; j < M + 1; ++j) {
            if (j <= intervals[0][1] - intervals[0][0]) {
                dp[1][j] = 1;
            } else {
                dp[1][j] = 0;
            }
        }
        for (long long i = 2; i < N + 1; ++i) {
            for (int j = 1; j < M + 1; ++j) {
                dp[i][j] = 0;
                for (int k = 0; k <= j &&
                    k <= intervals[i - 1][1] - intervals[i - 1][0]; ++k) {
                    dp[i][j] =  (dp[i][j] + dp[i - 1][j - k]) % kt;
                }
            }
        }
        return dp[N][M];
    }
};
// Please always keep this simple mai function.
int main() {
    std :: ifstream f("bomboane.in");
    std :: ofstream g("bomboane.out");

    Candy myCandy(f);
    g << myCandy.get_Result();
    g.close();
    f.close();
}
