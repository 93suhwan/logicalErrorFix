#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using cd = complex<ld>;
using vcd = vector<cd>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <class T>
using min_pq = priority_queue<T, vector<T>, greater<T> >;
template <class T>
inline int ckmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int ckmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
template <class T>
void remDup(vector<T>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), end(v));
}
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
ll ceilDiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll floorDiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
void setPrec(int x) { cout << fixed << setprecision(x); }
string to_string(char c) { return string(1, c); }
string to_string(const char* s) { return (string)s; }
string to_string(string s) { return s; }
string to_string(bool b) { return to_string((int)b); }
template <class T>
string to_string(complex<T> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}
template <class T>
using V = vector<T>;
string to_string(V<bool> v) {
  string res = "{";
  for (int i = (0); i <= (int((v).size()) - 1); i++) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t sz>
string to_string(bitset<sz> b) {
  string res = "";
  for (int i = (0); i <= (int((b).size()) - 1); i++) res += char('0' + b[i]);
  return res;
}
template <class T, class U>
string to_string(pair<T, U> p);
template <class T>
string to_string(T v) {
  bool fst = 1;
  string res = "";
  for (const auto& x : v) {
    if (!fst) res += " ";
    fst = 0;
    res += to_string(x);
  }
  return res;
}
template <class T, class U>
string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class T>
void pr(T x) {
  cout << to_string(x);
}
template <class T, class... U>
void pr(const T& t, const U&... u) {
  pr(t);
  pr(u...);
}
void ps() { pr("\n"); }
template <class T, class... U>
void ps(const T& t, const U&... u) {
  pr(t);
  if (sizeof...(u)) pr(" ");
  ps(u...);
}
void DBG() { cerr << "]" << endl; }
template <class T, class... U>
void DBG(const T& t, const U&... u) {
  cerr << to_string(t);
  if (sizeof...(u)) cerr << ", ";
  DBG(u...);
}
const ld PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ld EPS = 1e-9;
const ll MODBASE = 1000000007LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 20;
const int MAXM = 1000;
const int MAXK = 16;
const int MAXQ = 200010;
int n, sum[MAXN], dp[1 << MAXN][2];
string s[MAXN];
vector<vi> X, Y, Z;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n;
  for (int i = (0); i <= (n - 1); i++) cin >> s[i];
  vi x, y, z;
  for (int i = (0); i <= (n - 1); i++) {
    x.clear();
    y.clear();
    z.clear();
    for (int j = (0); j <= (int((s[i]).size()) - 1); j++) {
      if (s[i][j] == '(')
        x.push_back(1);
      else
        x.push_back(-1);
    }
    for (int j = (1); j <= (int((x).size()) - 1); j++) x[j] += x[j - 1];
    sum[i] = x.back();
    y.push_back(x[0]);
    z.push_back(1);
    for (int j = (1); j <= (int((x).size()) - 1); j++) {
      int curMin = y.back(), cntMin = z.back();
      if (x[j] < curMin) {
        curMin = x[j];
        cntMin = 1;
      } else if (x[j] == curMin)
        cntMin++;
      y.push_back(curMin);
      z.push_back(cntMin);
    }
    X.push_back(x);
    Y.push_back(y);
    Z.push_back(z);
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0] = dp[0][1] = 0;
  for (int mask = (0); mask <= ((1 << n) - 1); mask++) {
    for (int p = (0); p <= (1); p++) {
      if (dp[mask][p] == -1) continue;
      if (p == 1) {
        for (int i = (0); i <= (n - 1); i++)
          if (!(mask & (1 << i))) ckmax(dp[mask | (1 << i)][1], dp[mask][1]);
        continue;
      }
      int prefixSum = 0;
      for (int i = (0); i <= (n - 1); i++)
        if (mask & (1 << i)) prefixSum += sum[i];
      for (int i = (0); i <= (n - 1); i++)
        if (!(mask & (1 << i))) {
          int newMask = mask + (1 << i);
          int newP = 0;
          int dau = 0, cuoi = int((X[i]).size()) - 1;
          while (dau <= cuoi) {
            int mid = (dau + cuoi) >> 1;
            if (Y[i][mid] < -prefixSum)
              cuoi = mid - 1;
            else
              dau = mid + 1;
          }
          int r = cuoi, dem = 0;
          if (r >= 0 && Y[i][r] == -prefixSum) dem = Z[i][r];
          if (r == int((X[i]).size()) - 1) {
            newP = 0;
          } else {
            newP = 1;
          }
          ckmax(dp[newMask][newP], dp[mask][p] + dem);
        }
    }
  }
  cout << max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]) << "\n";
  return 0;
}
