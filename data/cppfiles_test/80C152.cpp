#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
const int N = 2e5 + 5;
const long long int mod = 1e9 + 7;
const long long int Mod = 998244353;
const long double Pi = acos(-1);
const long long int Inf = 4e18;
const long double Eps = 1e-9;
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
using namespace std;
void TestCase() {
  int n;
  string s;
  cin >> n >> s;
  int l1, r1, l2, r2, fz = n + 1, lz = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      fz = min(fz, i);
      lz = max(lz, i);
    }
  }
  if (lz == -1) {
    l1 = 1, r1 = (n + 1) / 2;
    l2 = 2, r2 = 1 + (n + 1) / 2;
  } else {
    if (n % 2) {
      if (fz == (n / 2) && lz == (n / 2)) {
        l1 = 1, r1 = (n + 1) / 2;
        l2 = (n + 1) / 2, r2 = n;
      } else {
        if (fz < (n / 2)) {
          l1 = fz + 1, r1 = n;
          l2 = fz + 2, r2 = n;
        } else {
          l1 = 1, r1 = fz + 1;
          l2 = 1, r2 = fz;
        }
      }
    } else {
      if (fz < n / 2) {
        l1 = fz + 1, r1 = n;
        l2 = fz + 2, r2 = n;
      } else {
        l1 = 1, r1 = fz + 1;
        l2 = 1, r2 = fz;
      }
    }
  }
  cout << l1 << " " << r1 << " " << l2 << " " << r2;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int T = 1;
  cin >> T;
  while (T--) {
    TestCase();
    cout << "\n";
  }
  return 0;
}
