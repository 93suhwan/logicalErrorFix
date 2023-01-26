#include <bits/stdc++.h>
using namespace std;
const int N = 300100;
const long long mod = 998244353LL;
long long a[N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  vector<int> gud;
  while (q--) {
    long long n, m;
    cin >> n >> m;
    long long bad = (1LL << 30LL) - 1LL, lim;
    for (long long i = 30; i >= 0; i--) {
      if (n & (1LL << i)) continue;
      if (bad - (1LL << i) > m) bad -= (1LL << i);
    }
    cout << bad - n << "\n";
  }
  return 0;
}
