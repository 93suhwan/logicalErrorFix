#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O8")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long int N = 1e5 + 20, mod = 1e9 + 7, inf = 1e18, dlt = 12250,
                    maxm = 2e6;
int poww(long long a, int k) {
  if (!k) return 1;
  if (k == 1) return a;
  long long r = poww(a, k / 2);
  return (((r * r) % mod) * poww(a, k & 1)) % mod;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    string s;
    cin >> s;
    n = s.size();
    int ans1 = 9, ans2 = 9;
    int sc1 = 0, sc2 = 0;
    for (int i = 0; i < 5; i++) {
      if (s[2 * i] == '1') sc1++;
      if (5 - i + sc2 < sc1 || sc1 + 4 - i < sc2) {
        ans2 = 2 * i;
        break;
      }
      if (s[2 * i + 1] != '0') sc2++;
      if (4 - i + sc1 < sc2 || sc2 + 4 - i < sc1) {
        ans2 = 2 * i + 1;
        break;
      }
    }
    sc1 = 0;
    sc2 = 0;
    for (int i = 0; i < 5; i++) {
      if (s[2 * i] != '0') sc1++;
      if (5 - i + sc2 < sc1 || sc1 + 4 - i < sc2) {
        ans1 = 2 * i;
        break;
      }
      if (s[2 * i + 1] == '1') sc2++;
      if (4 - i + sc1 < sc2 || sc2 + 4 - i < sc1) {
        ans1 = 2 * i + 1;
        break;
      }
    }
    cout << min(ans1, ans2) + 1 << '\n';
  }
  return 0;
}
