#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using ull = unsigned long long;
using db = long double;
const int N = 2e5 + 5, LG = 18, MOD = 998244353;
const long double PI = acos(-1);
void doWork() {
  vector<int> v(3);
  for (int i = 0; i < 3; i++) cin >> v[i];
  bool ok = false;
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      int x = v[i];
      int y = v[j];
      int z = v[3 - i - j];
      if (x == y && z % 2 == 0) {
        ok = true;
      }
      if (x + y == z) {
        ok = true;
      }
    }
  }
  if (ok) {
    cout << "YES\n";
  } else
    cout << "NO\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    doWork();
  }
  return 0;
}
