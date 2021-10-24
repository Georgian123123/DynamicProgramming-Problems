#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class GigelGym {
 private:
    int N, M;
    vector<long long> gant;
    vector<long long> rep;

 public:
        explicit GigelGym(ifstream &f) {
            f >> N >> M;
            for (int i = 0; i < N; ++i) {
                long long aux;
                f >> aux;
                gant.push_back(aux);
                f >> aux;
                rep.push_back(aux);
            }
        }
        long long get_sum(vector<long long> gant, vector<long long> rep) {
            long long min = *min_element(gant.begin(), gant.end());
            long long sum = 0;
            for (int i = 0; i < rep.size(); ++i) {
                sum += rep[i];
            }
            return min * sum;
        }
        int find_position(vector<long long>sum, long long sumInit) {
            int position = 0;
            int max = sumInit;
            for (int i = 0; i < sum.size(); ++i) {
                if (sum[i] > max) {
                    max = sum[i];
                    position = i;
                }
            }
            if (max == sumInit) {
                return -1;
            } else {
                return position;
            }
        }
        long long get_result() {
            vector<long long> gantResult;
            vector<long long> repResult;
            for (int i = 0; i < M; ++i) {
                gantResult.push_back(gant[i]);
                repResult.push_back(rep[i]);
            }
            long long sumInit = get_sum(gantResult, repResult);

            for (int i = M; i < N; ++i) {
                vector<long long> sum;
                for (int j = 0; j < M; ++j) {
                    std :: swap(gantResult[j], gant[i]);
                    std :: swap(repResult[j], rep[i]);
                    sum.push_back(get_sum(gantResult, repResult));
                    std :: swap(gant[i], gantResult[j]);
                    std :: swap(rep[i], repResult[j]);
                }
                int k = find_position(sum, sumInit);
                if (k != -1) {
                    std :: swap(gantResult[k], gant[i]);
                    std :: swap(repResult[k], rep[i]);
                    sumInit = sum[k];
                }
            }
            return sumInit;
        }
};

int main() {
    ifstream f("sala.in");
    ofstream g("sala.out");
    GigelGym myGigel(f);
    g << myGigel.get_result();
    f.close();
    g.close();
}
