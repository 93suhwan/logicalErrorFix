#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, vector<T> &a) {
  os << "[";
  for (int i = 0; i < long long(a.size()); i++) {
    os << a[i] << ((i != long long(a.size() - 1) ? " " : ""));
  }
  os << "]\n";
  return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p) {
  os << "" << p.first << " " << p.second << "";
  return os;
}
void usaco(string taskname) {
  string fin = taskname + ".in";
  string fout = taskname + ".out";
  const char *FIN = fin.c_str();
  const char *FOUT = fout.c_str();
  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);
}
template <typename T>
void read(vector<T> &v) {
  int n = v.size();
  for (int i = 0; i < n; i++) cin >> v[i];
}
template <typename T>
vector<T> UNQ(vector<T> a) {
  vector<T> ans;
  for (T t : a)
    if (ans.empty() || t != ans.back()) ans.push_back(t);
  return ans;
}
long long ceil(long long a, long long b) {
  long long ans = a / b;
  if (a % b) ans++;
  return ans;
}
long double log(long double a, long double b) { return log(b) / log(a); }
long long power(long long base, long long exp, long long M = 1e18) {
  long long ans = 1;
  while (exp) {
    if (exp % 2 == 1) ans = ((ans % M) * (base % M)) % M;
    base = ((base % M) * (base % M)) % M;
    exp /= 2;
  }
  return ans;
}
string to_base(int n, int new_base) {
  string s;
  int nn = n;
  while (nn) {
    s += to_string(nn % new_base);
    nn /= new_base;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
  long long x = (a / gcd(a, b));
  return b * x;
}
vector<long long> generate_array(long long n, long long mn = 1,
                                 long long mx = 1e18 + 1) {
  if (mx == 1e18 + 1) mx = n;
  vector<long long> ans(n);
  for (int i = 0; i < n; i++) ans[i] = (mn + rand() % (mx - mn + 1));
  return ans;
}
string substr(string s, int l, int r) {
  string ans;
  for (int i = l; i <= r; i++) ans += s[i];
  return ans;
}
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) solve();
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<vector<bool>> has(26, vector<bool>(26));
  for (int i = 1; i <= min(25, n); i++)
    for (int j : g[i]) has[i][j] = has[j][i] = 1;
  n = min(n, 25);
  for (int i = 0; i < (1 << n); i++) {
    if (__builtin_popcount(i) != 5) continue;
    vector<int> cur;
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) cur.push_back(j);
    bool ok = 1;
    for (int j1 = 0; j1 < 5; j1++)
      for (int j2 = j1 + 1; j2 < 5; j2++) ok &= has[cur[j1]][cur[j2]];
    if (ok) {
      for (int &x : cur) x++;
      {
        for (auto ait : cur) cout << ait << " ";
        cout << "\n";
      }
      return;
    }
    ok = 1;
    for (int j1 = 0; j1 < 5; j1++)
      for (int j2 = j1 + 1; j2 < 5; j2++) ok &= !has[cur[j1]][cur[j2]];
    if (ok) {
      for (int &x : cur) x++;
      {
        for (auto ait : cur) cout << ait << " ";
        cout << "\n";
      }
      return;
    }
  }
  {
    cout << -1 << "\n";
    return;
  }
}
