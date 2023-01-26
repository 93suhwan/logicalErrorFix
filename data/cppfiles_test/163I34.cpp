#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using uint = unsigned;
using ull = unsigned long long;
using umapII = unordered_map<int, int>;
using VI = vector<int>;
using VC = vector<char>;
using VS = vector<string>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;
using VVVVB = vector<VVVB>;
using VVVVVB = vector<VVVVB>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;
using VVVVLL = vector<VVVLL>;
using VD = vector<db>;
using SI = set<int>;
using SS = set<string>;
using PII = pair<int, int>;
using PDD = pair<db, db>;
using PLL = pair<ll, ll>;
using VPI = vector<PII>;
using VVPI = vector<VPI>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using VVVVI = vector<VVVI>;
using VVVVVI = vector<VVVVI>;
void eraseDups(VI& a) { a.erase(unique(a.begin(), a.end()), a.end()); }
int strToInt(string& a) {
  stringstream x(a);
  int b;
  x >> b;
  return b;
}
int bitCnt(int a) {
  bitset<64> b(a);
  return b.count();
}
int bitCnt(string a) {
  bitset<64> b(a);
  return b.count();
}
VI readVI(int n) {
  VI a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  return a;
}
VVI readVVI(int n, int m) {
  VVI a(n, VI(m));
  for (int i = 0; i < n; i++) a[i] = readVI(m);
  return a;
}
VLL readVLL(ll n) {
  VLL a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  return a;
}
VVLL readVVLL(ll n, ll m) {
  VVLL a(n, VLL(m));
  for (int i = 0; i < n; i++) a[i] = readVLL(m);
  return a;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void print(VI& a) {
  for (auto el : a) {
    cout << el << ' ';
  }
  cout << '\n';
}
void print(VPI& a) {
  for (auto el : a) {
    cout << el.first << ',' << el.second << ' ';
  }
  cout << '\n';
}
void print(VI& a, int n) {
  int cnt = 0;
  for (auto el : a) {
    if (cnt++ == n) break;
    cout << el << ' ';
  }
  cout << '\n';
}
void print(VVI& a) {
  for (auto el : a) {
    print(el);
  }
}
const int MOD = 1e9 + 7;
const int MOD1 = 998244353;
const int INF = 1.07e9;
const ll INFF = INT64_MAX;
const db EPS = 1e-9;
const db PI = acos(-1.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int pow(ll a, ll b, ll p) {
  ll cur = 1, res = 1;
  a %= p;
  while (cur <= b) {
    if (cur & b) res = res * a % p;
    a = a * a % p;
    cur <<= 1;
  }
  return res;
}
int inv(int a, int p) { return pow(a, p - 2, p); }
void go() {
  int n, m, x, y, x1, y1, prob, prob1;
  cin >> n >> m >> x >> y >> x1 >> y1 >> prob;
  prob1 = 100 - prob;
  prob = 100;
  set<VI> seen;
  int X = 1, Y = 1, len = 0, cnt = 0;
  int ext = 0;
  if (x == x1 || y1 == y) ext = 1;
  while (1) {
    if (seen.count({x, y, X, Y})) break;
    int xx = x + X, yy = y + Y;
    if (xx == 0 || xx == n + 1) {
      X = -X;
      continue;
    }
    if (yy == 0 || yy == m + 1) {
      Y = -Y;
      continue;
    }
    seen.insert({x, y, X, Y});
    if (x == x1 || y == y1)
      cnt++, ext = 1;
    else
      ext++;
    tie(x, y) = {xx, yy};
    len++;
  }
  int Gcd = gcd(cnt, len);
  cnt /= Gcd;
  len /= Gcd;
  Gcd = gcd(prob, prob1);
  prob /= Gcd;
  prob1 /= Gcd;
  ll b = pow(prob, cnt, MOD);
  ll a = pow(prob1, cnt, MOD);
  a = ((b - a) % MOD + MOD) % MOD;
  ll res = (len * b % MOD) % MOD * inv(a, MOD) % MOD;
  res = (res - ext + MOD) % MOD;
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) go();
  return (0 - 0);
}
