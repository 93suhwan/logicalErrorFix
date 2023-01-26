#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int p, long long int k) {
  if (max(p, k) % min(p, k) == 0)
    return min(p, k);
  else
    return gcd(max(p, k) % min(p, k), min(p, k));
}
long long int KPK(long long int p, long long int k) {
  long long int H, N;
  H = p * k;
  N = gcd(p, k);
  H /= N;
  return H;
}
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
        fact = KPK(fact, k);
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
