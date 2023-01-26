#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long MOD = long long(9e18)) {
  long long res = 1;
  a %= MOD;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
    a %= MOD;
    res %= MOD;
  }
  return res % MOD;
}
template <typename T>
void umax(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void umin(T& a, T b) {
  a = min(a, b);
}
clock_t startTime;
double getTime() { return (double)(clock() - startTime) / CLOCKS_PER_SEC; }
template <typename T>
ostream& operator<<(ostream& s, vector<T>& v) {
  for (auto el : v) {
    s << el << '|';
  }
  return s;
}
long long mod = 998244353;
int T = 1;
int n, k;
string s;
void solve() {
  cin >> n >> k;
  cin >> s;
  vector<vector<int> > prefP(n, vector<int>(2, 0));
  vector<vector<int> > prefM(n, vector<int>(2, 0));
  for (int i = (0); i < (n); i++) {
    if (i) {
      prefP[i][0] += prefP[i - 1][0];
      prefM[i][0] += prefM[i - 1][0];
      prefP[i][1] += prefP[i - 1][1];
      prefM[i][1] += prefM[i - 1][1];
    }
    if (s[i] == '+') {
      prefP[i][i % 2]++;
    } else {
      prefM[i][i % 2]++;
    }
  }
  while (k--) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    int cntP[2];
    cntP[0] = prefP[r][0] - (l > 0 ? prefP[l - 1][0] : 0);
    cntP[1] = prefP[r][1] - (l > 0 ? prefP[l - 1][1] : 0);
    int cntM[2];
    cntM[0] = prefM[r][0] - (l ? prefM[l - 1][0] : 0);
    cntM[1] = prefM[r][1] - (l ? prefM[l - 1][1] : 0);
    int p = abs(cntP[0] - cntP[1]);
    int m = abs(cntM[0] - cntM[1]);
    int ans = 0;
    if (p & 1) {
      p--;
      ans++;
    }
    if (m & 1) {
      m--;
      ans++;
    }
    ans += min(p, m);
    cout << ans << '\n';
  }
}
int main() {
  startTime = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    solve();
    cout << "\n";
    cout.flush();
  };
  return 0;
}
