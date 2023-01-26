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
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
map<long long, long long> calc(vector<long long> a) {
  map<long long, long long> cnt, ans;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    ans[a[i]] += cnt[a[i]];
    cnt[a[i]]++;
  }
  return ans;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  long long ans = 0;
  map<long long, long long> cnt_pref, cnt_suff;
  for (int i = 0; i < n; i++) cnt_suff[b[i]]++;
  for (int i = 0; i < n; i++) {
    ans += cnt_pref[a[i]] * cnt_suff[b[i]];
    cnt_pref[a[i]]++;
    cnt_suff[b[i]]--;
  }
  ans = (n * (n - 1) * (n - 2)) / 6 - ans;
  {
    cout << ans << "\n";
    return;
  }
}
