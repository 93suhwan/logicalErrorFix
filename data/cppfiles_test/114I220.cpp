#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int pow_mod(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1, a = 1LL * a * a % mod)
    if (b & 1) ret = 1LL * ret * a % mod;
  return ret;
}
int gcd(int a, int b) { return a % b == 0 ? b : gcd(b, a % b); }
inline long long rd() {
  long long x = 0;
  int t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * t;
}
const int N = 200100;
const double pi = 3.1415927536;
const double INF = 1e9;
const double eps = 1e-6;
vector<int> v[11], res[N];
int c[11];
int ans[N];
map<vector<int>, int> mp;
int n;
long long ma;
void wk(int u) {
  vector<int> t;
  for (int i = 0; i <= n - 1; i++) t[i] = res[u][i];
  if (mp.count(t)) {
    return;
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += v[i][res[u][i - 1]];
  }
  if (sum > ma) {
    sum = ma;
    for (int i = 1; i <= n; i++) {
      ans[i] = res[u][i - 1];
    }
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    int x;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      v[i].push_back(x);
    }
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x;
    for (int j = 1; j <= n; j++) {
      cin >> x;
      res[i].push_back(x);
    }
    mp[res[i]] = 1;
  }
  vector<int> t;
  for (int i = 1; i <= n; i++) t.push_back(c[i]);
  if (!mp.count(t)) {
    for (int i = 1; i <= n; i++) cout << c[i] << ' ';
    cout << endl;
    return;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (res[i][j - 1] > 1) {
        res[i][j - 1]--;
        wk(i);
        res[i][j - 1]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) solve();
}
