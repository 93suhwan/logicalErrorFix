#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long a, long long b) {
  a = ((a) < 0 ? -(a) : (a));
  b = ((b) < 0 ? -(b) : (b));
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
long long ext_gcd(long long A, long long B, long long* X, long long* Y) {
  long long x2, y2, x1, y1, x, y, r2, r1, q, r;
  x2 = 1;
  y2 = 0;
  x1 = 0;
  y1 = 1;
  for (r2 = A, r1 = B; r1 != 0;
       r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y) {
    q = r2 / r1;
    r = r2 % r1;
    x = x2 - (q * x1);
    y = y2 - (q * y1);
  }
  *X = x2;
  *Y = y2;
  return r2;
}
inline long long modInv(long long a, long long m) {
  long long x, y;
  ext_gcd(a, m, &x, &y);
  x %= m;
  if (x < 0) x += m;
  return x;
}
inline long long bigmod(long long a, long long p, long long m) {
  long long res = 1 % m, x = a % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
const long long inf = 2147383647;
const long long mod = 1000000007;
const double pi = 2 * acos(0.0);
const double eps = 1e-11;
int ks;
int n, m, k;
set<int> X, Y;
map<int, int> MX, MY;
vector<pair<int, int> > P;
vector<int> XV[200005], YV[200005], Xtot, Ytot;
void solve() {
  X.clear();
  Y.clear();
  P.clear();
  MX.clear();
  MY.clear();
  Xtot.clear();
  Ytot.clear();
  cin >> n >> m >> k;
  for (int i = 0; i <= n; i++) XV[i].clear();
  for (int i = 0; i <= m; i++) YV[i].clear();
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    X.insert(x);
    MX[x] = i;
  }
  for (int i = 0; i < m; i++) {
    int y;
    cin >> y;
    Y.insert(y);
    MY[y] = i;
  }
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    P.push_back(make_pair(x, y));
    if (X.find(x) != X.end()) XV[MX[x]].push_back(y);
    if (Y.find(y) != Y.end()) YV[MY[y]].push_back(x);
    Xtot.push_back(x);
    Ytot.push_back(y);
  }
  sort(Xtot.begin(), Xtot.end());
  sort(Ytot.begin(), Ytot.end());
  for (int i = 0; i < n; i++) sort(XV[i].begin(), XV[i].end());
  for (int i = 0; i < m; i++) sort(YV[i].begin(), YV[i].end());
  int ret = 0;
  for (int i = 0; i < k; i++) {
    int x = P[i].first, y = P[i].second;
    if (X.find(x) != X.end() && Y.find(y) != Y.end())
      continue;
    else if (Y.find(y) == Y.end()) {
      auto it1 = Y.upper_bound(y);
      auto it2 = Y.lower_bound(y);
      it2--;
      int up = *it1;
      int down = *it2;
      int total = upper_bound(Ytot.begin(), Ytot.end(), up - 1) -
                  lower_bound(Ytot.begin(), Ytot.end(), down + 1);
      int self = upper_bound(XV[MX[x]].begin(), XV[MX[x]].end(), up - 1) -
                 lower_bound(XV[MX[x]].begin(), XV[MX[x]].end(), down + 1);
      ret += (total - self);
    } else {
      auto it1 = X.upper_bound(x);
      auto it2 = X.lower_bound(x);
      it2--;
      int up = *it1;
      int down = *it2;
      int total = upper_bound(Xtot.begin(), Xtot.end(), up - 1) -
                  lower_bound(Xtot.begin(), Xtot.end(), down + 1);
      int self = upper_bound(YV[MY[y]].begin(), YV[MY[y]].end(), up - 1) -
                 lower_bound(YV[MY[y]].begin(), YV[MY[y]].end(), down + 1);
      ret += (total - self);
    }
  }
  cout << ret / 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (ks = 1; ks <= tc; ks++) {
    solve();
  }
  return 0;
}
