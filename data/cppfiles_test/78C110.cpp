#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    unsigned int n;
    cin >> n;
    unsigned int cnts[32] = {0};
    for (long long i = 0; i < n; i++) {
      unsigned int a;
      cin >> a;
      unsigned int p2 = 1;
      for (int exp = 0; exp < 30; exp++) {
        if (a & p2) cnts[exp]++;
        p2 *= 2;
      }
    }
    for (long long i = 1; i <= n; i++) {
      bool valid = true;
      for (int j = 0; j < 32 && valid; j++) valid = valid & (cnts[j] % i == 0);
      if (valid) cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
