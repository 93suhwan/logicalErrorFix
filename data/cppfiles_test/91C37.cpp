#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long MOD1 = 1e9 + 7;
const long long INF = 1e17;
const int inf = 1e9;
long long n, m, k, l, r;
string s;
void solve() {
  cin >> n;
  vector<long long> a(n + 2);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
  }
  vector<long long> ndv(n + 1);
  vector<long long> mnv(n + 1);
  long long ans = 0;
  long long add = 0;
  for (int i = 1; i <= n; i++) {
    mnv[i] = a[i];
    ndv[i] = 1;
    for (int j = i - 1; j >= 1; j--) {
      if (i != 1 && ndv[j] == ceil((long double)a[j] / mnv[j + 1])) {
        break;
      }
      add -= (j * (ndv[j] - 1)) % MOD;
      ndv[j] = ceil((long double)a[j] / mnv[j + 1]);
      mnv[j] = a[j] / ndv[j];
      add += (j * (ndv[j] - 1)) % MOD;
    }
    ans = (ans + add) % MOD;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
