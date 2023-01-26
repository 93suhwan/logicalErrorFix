#include <bits/stdc++.h>
using namespace std;
void TEST_CASE() {
  long long n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<long long> nor(n, 0), abnor(n, 0);
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (s[i] == '+') {
        nor[i] = 1;
        abnor[i] = -1;
      } else {
        nor[i] = -1;
        abnor[i] = 1;
      }
    } else {
      if (s[i] == '+') {
        nor[i] = -1;
        abnor[i] = 1;
      } else {
        nor[i] = 1;
        abnor[i] = -1;
      }
    }
  }
  vector<long long> f1(n, 0), f2(n, 0);
  f1[0] = nor[0];
  f2[0] = abnor[0];
  for (long long i = 1; i < n; i++) {
    f1[i] += f1[i - 1] + nor[i];
    f2[i] += f2[i - 1] + abnor[i];
  }
  for (long long i = 0; i < q; i++) {
    long long l, r;
    cin >> l >> r;
    l--;
    r--;
    if (l % 2 == 0) {
      long long tot = f1[r];
      if (l > 0) {
        tot -= f1[l - 1];
      }
      if (tot == 0) {
        cout << 0 << "\n";
      } else if ((r - l + 1) % 2) {
        cout << 1 << "\n";
      } else {
        cout << 2 << "\n";
      }
    } else {
      long long tot = f2[r];
      if (l > 0) {
        tot -= f2[l - 1];
      }
      if (tot == 0) {
        cout << 0 << "\n";
      } else if ((r - l + 1) % 2) {
        cout << 1 << "\n";
      } else {
        cout << 2 << "\n";
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    TEST_CASE();
  }
  return 0;
}
