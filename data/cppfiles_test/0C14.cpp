#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
int poww(int a, int b, int mod) {
  int res = 1;
  if (b < 0) b = (b % (mod - 1) + mod - 1) % (mod - 1);
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) res = 1ll * res * a % mod;
  return res;
}
void Max(int& x, int y) { x = max(x, y); }
void Min(int& x, int y) { x = min(x, y); }
void OK(bool yes) { cout << (yes ? "Yes\n" : "No\n"); }
const int N = 200200, M = 2010, LN = (1 << 24), K = 17, inf = 3e18,
          Mod1 = 1e9 + 7, Mod2 = 999997457;
const long double pi = acos(-1), eps = 1e-12;
int Fact[N], iFact[N];
void init() {
  Fact[0] = iFact[0] = 1ll;
  for (int i = 1; i < N; i++) Fact[i] = (1ll * Fact[i - 1] * i) % Mod;
  iFact[N - 1] = poww(Fact[N - 1], -1, Mod);
  for (int i = N - 2; i; i--) iFact[i] = (1ll * iFact[i + 1] * (i + 1)) % Mod;
}
int Cnk(int x, int y) {
  if (y > x) return 0;
  return (((Fact[x] * poww(Fact[y], -1, Mod)) % Mod) *
          poww(Fact[x - y], -1, Mod)) %
         Mod;
}
void Add(int& x, int y, int j = 0) {
  int mod = Mod;
  if (j == 1) mod = Mod1;
  if (j == 2) mod = Mod2;
  x %= mod;
  y %= mod;
  if (x < 0) x += mod;
  if (y < 0) y += mod;
  x = (x + y >= mod ? x + y - mod : x + y);
}
int n, m;
string s[1000010];
bool asc(int i, int j) { return s[i] < s[j]; }
bool des(int i, int j) { return s[i] > s[j]; }
void Solve(vector<int>& v, int idx) {
  if (idx > m) {
    for (auto p : v) cout << p << ' ';
    return;
  }
  if (idx & 1) {
    sort(v.begin(), v.end(), des);
  } else {
    sort(v.begin(), v.end(), asc);
  }
  vector<int> tmp;
  for (int i = 0; i < v.size(); i++) {
    if (i == 0) {
      tmp.push_back(v[i]);
    } else {
      if (s[v[i]][idx] == s[v[i - 1]][idx])
        tmp.push_back(v[i]);
      else {
        Solve(tmp, idx + 1);
        tmp.clear();
        tmp.push_back(v[i]);
      }
    }
  }
  Solve(tmp, idx + 1);
  tmp.clear();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int T = 1;
  int Case = 1;
  while (T--) {
    cin >> n >> m;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      v.push_back(i);
    }
    Solve(v, 0);
  }
  return 0;
}
