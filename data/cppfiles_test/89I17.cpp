#include <bits/stdc++.h>
using namespace std;
int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    int banyak;
    cin >> banyak;
    long long int fact, S;
    fact = 1;
    S = 1e9;
    int angka[banyak];
    bool univ;
    univ = true;
    for (int k = 2; k <= banyak + 1; k++) {
      if (fact <= S) {
        fact *= k;
      }
      cin >> angka[k - 2];
      if (angka[k - 2] % fact == 0) {
        univ = false;
      }
    }
    if (univ) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
