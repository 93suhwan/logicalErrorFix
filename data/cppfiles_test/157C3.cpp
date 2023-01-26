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
const int MOD1 = 1e9 + 7;
const int MOD = 998244353;
const int INF = 1.07e9;
const ll INFF = INT64_MAX;
const db EPS = 1e-9;
const db PI = acos(-1.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int N = 5000;
ll fact[N + 5], invFact[N + 5];
ll power(ll a, int b) {
  ll ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % MOD;
    b >>= 1;
    a = (a * a) % MOD;
  }
  return ans;
}
ll inv(ll a, ll p) { return power(a, p - 2); }
ll nCr(ll a, ll b) {
  if (a < b || b < 0) return 0;
  if (b == 0 || a == b) return 1;
  return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
}
void init() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
  invFact[N] = inv(fact[N], MOD);
  for (int i = N - 1; i >= 0; i--)
    invFact[i] = invFact[i + 1] * ll(i + 1) % MOD;
}
ll n, k;
string s;
void go() {
  cin >> n >> k >> s;
  ll ans = 0;
  VI pos;
  for (int i = 0; i < n; i++)
    if (s[i] == '1') pos.push_back(i);
  if (k > pos.size() || k == 0) {
    cout << "1\n";
    return;
  }
  ll curLen = (pos.size() == k ? n : pos[k]), zero = 0;
  ans = (ans + nCr(curLen, k)) % MOD;
  for (int i = pos[k], j = -1; i < n; i++) {
    if (s[i] == '1') {
      curLen = i - pos[++j];
      zero = curLen - k;
      if (zero > 0) ans = (ans + nCr(curLen - 1, zero - 1)) % MOD;
    } else {
      curLen = i - pos[j];
      zero = curLen - k;
      ans = (ans + nCr(curLen - 1, k - 1)) % MOD;
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  init();
  while (T--) go();
  return (0 - 0);
}
