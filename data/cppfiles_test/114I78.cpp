#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, vector<T>& a) {
  os << "[";
  for (int i = 0; i < long long(a.size()); i++) {
    os << a[i] << ((i != long long(a.size() - 1) ? " " : ""));
  }
  os << "]\n";
  return os;
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2>& p) {
  os << "" << p.first << " " << p.second << "";
  return os;
}
void usaco(string taskname) {
  string fin = taskname + ".in";
  string fout = taskname + ".out";
  const char* FIN = fin.c_str();
  const char* FOUT = fout.c_str();
  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);
}
template <typename T>
void read(vector<T>& v) {
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
  int t = 1;
  while (t--) solve();
}
int n, m;
vector<int> c;
vector<vector<int>> a;
vector<vector<int>> b;
void solve() {
  cin >> n;
  c.resize(n);
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    a[i].resize(c[i]);
    read(a[i]);
  }
  cin >> m;
  b.resize(m, vector<int>(n));
  for (int i = 0; i < m; i++) read(b[i]);
  sort(b.begin(), b.end());
  long long suff = 5;
  while (power(suff, n) <= m) suff++;
  long long bst = 0;
  vector<int> ans;
  for (int i = 0; i < 1e7; i++) {
    string s = to_base(i, suff);
    if (s.size() > n) break;
    while (s.size() != n) s = '0' + s;
    vector<int> cur(n);
    bool ok = 1;
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      cur[j] = c[j] - (s[j] - '0');
      ok &= (0 <= cur[j] - 1);
      if (ok) sum += a[j][cur[j] - 1];
    }
    if (ok && sum > bst && !binary_search(b.begin(), b.end(), cur))
      bst = sum, ans = cur;
  }
  {
    for (auto ait : ans) cout << ait << " ";
    cout << "\n";
  }
}
