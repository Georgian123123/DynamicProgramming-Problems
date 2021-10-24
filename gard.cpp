#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
// Asa-zisa "Scandura" cu capetele x si y.
struct Uluca {
    long long x, y;
};
/*
    Clasa in care vom rezolva problema.
    Campurile sunt n, numarul de Scanduri si
    "gard" care este un vector de Scanduri.
*/
class Gard {
 private :
    long long n;
    vector<struct Uluca> gard;

 public :
// Citirea din fisier
    explicit Gard(ifstream &f) {
        f >> n;
        for (long long i = 0; i < n; ++i) {
            struct Uluca uluca;
            long long aux;
            f >> aux;
            uluca.x = aux;
            f >> aux;
            uluca.y = aux;
            gard.push_back(uluca);
        }
    }
// Functie auxiliara pentru sortare.
    static bool compare(Uluca u1, Uluca u2) {
        return u1.x < u2.x;
    }
/*
    Efectiva implementare a algoritmului Greedy.
    (Totul explicat in README)
*/
    long long get_result() {
        long long result = 0;
        std :: sort(gard.begin(), gard.end(), compare);
        Uluca uInit = gard[0];
        for (unsigned long long i = 1; i < gard.size(); ++i) {
            if (uInit.y >= gard[i].y) {
                result++;
            } else if (uInit.y <= gard[i].y && gard[i].x == uInit.x) {
                result++;
                std :: swap(uInit, gard[i]);
            } else if (gard[i].y > uInit.y) {
                std :: swap(uInit, gard[i]);
            }
        }
        return result;
    }
};
// Please always keep this simple main function.
int main() {
    ifstream f("gard.in");
    ofstream g("gard.out");
    class Gard myGard(f);
    g << myGard.get_result();
    f.close();
    g.close();
    return 0;
}

