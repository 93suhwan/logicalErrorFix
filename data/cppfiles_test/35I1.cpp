/*
Author : Hocky Yudhiono
24-Oct-21 19:03:50

1. You can sort the query if offline!
2. Don't bring the dp remaining state when dfsing on DP on Tree.
3. Try to reverse (Think from the back) if you stuck.
4. Be careful when submitting Div. 2 D-F, dont waste it on stupid WAs.
5. Try to reduce a problem, think of it when you're making subtasks
   like when problemsetting.
6. Matching problems can be solved with DP and vice versa.
   Counting and optimizing problems can be solved with DP.
   Try bitmasking when N is small. When big, consider greedy-ing.
7. map<string,int> is faster than you think

*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

// Suffix Literal:
// U: Unsigned
// L: Long double
// LL: Long long
typedef long long ll;
typedef long long LL;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef pair<ll, ll> PLL;
typedef pair<ll, ll> pll;
typedef long double ld;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define popf pop_front
#define pf push_front
#define popb pop_back
#define mp make_pair
#define pb push_back
#define remove erase
#define fi first
#define se second

// If the time limit is strict, try not to use long double

// Remember to undefine if the problem is interactive
#define endl '\n'
#define DEBUG(X) cout << ">>> DEBUG(" << __LINE__ << ") " << #X << " = " << (X) << endl

const double EPS = 1e-9;
const int INFMEM = 63;
const int INF = 1061109567;
const ll LINF = 4557430888798830399LL;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
// Do dir^1 to get reverse direction
const char dch[4] = {'R', 'L', 'D', 'U'};
// const string ds[8] = {"E","W","S","N","SE","NW","SW","NE"};
const double PI = 3.141592653589793;

inline void open(string a) {
  freopen((a + ".in").c_str(), "r", stdin);
  freopen((a + ".out").c_str(), "w", stdout);
}

inline void fasterios() {
  // Do not use if interactive
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  // cout << fixed << setprecision(10);
}

const int MAXN = 1e6;
int isi[MAXN + 5];
bool isPlus[MAXN + 5];

const int MAX_PR = 1'000'000;
vector<bool> isprime(MAX_PR + 1);
vi eratosthenesSieve(int lim) {
  fill(all(isprime), 1); isprime[0] = isprime[1] = 0;
  for (int i = 4; i < lim; i += 2) isprime[i] = 0;
  for (int i = 3; i * i < lim; i += 2) if (isprime[i])
      for (int j = i * i; j < lim; j += i * 2) isprime[j] = 0;
  vi pr;
  rep(i, 2, lim) if (isprime[i]) pr.push_back(i);
  return pr;
}

vector <PII> prefixSum[100005];
vector <PII> numFactor[1000005];
vector <int> posInPrime[1000005];
vector <PII> monotonicDeque[100005];

namespace Color {
enum Code {
  FG_RED     = 31,
  FG_GREEN   = 32,
  FG_YELLOW  = 33,
  FG_BLUE    = 34,
  FG_MAGENTA = 35,
  FG_CYAN    = 36,
  FG_DEFAULT = 39
};
class ColorDebugger {
  Code code;
 public:
  ColorDebugger(Code pCode) : code(pCode) {}
  template <class T>
  ColorDebugger& operator<<(const T &other) {
    cerr << "\033[" << code << "m" << other << "\033[" << FG_DEFAULT << "m";
    return *this;
  }
  ColorDebugger& operator<<(ostream & (*pManip)(ostream&)) {
    (*pManip)(cerr);
    return *this;
  }
};
}

using namespace Color;
ColorDebugger rcout(FG_RED);
ColorDebugger ycout(FG_YELLOW);
ColorDebugger gcout(FG_GREEN);
ColorDebugger bcout(FG_BLUE);
ColorDebugger mcout(FG_MAGENTA);
ColorDebugger ccout(FG_CYAN);

int palingKanan[100005];
int hi[100006];
vi prime;

struct BIT {
  int n, logN; vector <LL> BITVal;
  BIT(int N) : n(N), BITVal(N + 1) { logN = 31 - __builtin_clz(N); }
  void upd(LL pos, LL val) {
    if (pos <= 0) return;
    for (; pos <= n; pos += (pos & (-pos))) BITVal[pos] += val;
  }
  void change(LL pos, LL val) {
    if (pos <= 0) return;
    upd(pos, val - get(pos, pos));
  }
  LL get(LL pos) {
    LL ret = 0;
    for (; pos > 0; pos -= (pos & (-pos))) ret += BITVal[pos];
    return ret;
  }
  LL get(LL a, LL b) {
    return get(b) - (a > 1 ? get(a - 1) : 0);
  }
  // Find the first index x such that get(x) >= sum, lower bound
  LL findOrder(LL sum) {
    LL pos = 0;
    for (int k = logN; k >= 0; k--) {
      LL nx = pos + (1 << k);
      if (nx <= n && BITVal[nx] < sum)
        pos = nx, sum -= BITVal[pos];
    }
    return pos + 1;
  }
};
vector <PII> factor(int n) {
  if (isprime[n]) return {{n, 1}};
  vector <PII> ret;
  trav(cur, prime) {
    if (n % cur) continue;
    ret.pb({cur, 0});
    while (!(n % cur)) {
      n /= cur;
      ret.back().se++;
    }
    if (n == 1) break;
  }
  return ret;
}

int main() {
  fasterios();
  prime = eratosthenesSieve(MAXN);
  int n; cin >> n;
  BIT keepMin(1e6 + 5);
  for (int i = 1; i <= n; i++) {
    cin >> isi[i];
  }
  keepMin.upd(n, 1);
  for (int i = 1; i <= n; i++) {
    char ch; cin >> ch;
    isPlus[i] = (ch == '*');
  }
  for (int i = 1; i <= n; i++) {
    numFactor[i] = factor(isi[i]);
    trav(cur, numFactor[i]) {
      cur.fi = lower_bound(all(prime), cur.fi) - begin(prime);
      // curposnya coba dicancel
      // bcout << cur.fi << " " << cur.se << endl;
      posInPrime[i].pb(sz(prefixSum[cur.fi]));
      prefixSum[cur.fi].pb({isPlus[i] ? cur.se : -cur.se, i});
    }
  }
  for (int i = 0; i < sz(prime); i++) {
    palingKanan[i] = INF;
    monotonicDeque[i].pb({ -INF, n + 1});
    hi[i]++;
    if (sz(prefixSum[i]) == 0) continue;
    // bcout << "Computing " << prime[i] << endl;
    for (int j = 1; j < sz(prefixSum[i]); j++) {
      prefixSum[i][j].fi += prefixSum[i][j - 1].fi;
    }
    // trav(cur, prefixSum[i]){
    //   gcout << cur.fi << " " << cur.se << endl;
    // }
  }
  LL ans = 0;
  for (int i = n; i >= 1; i--) {
    // binser batasnya
    // rcout << "Computing " << i << " " << isi[i] << endl;
    rep(j, 0, sz(numFactor[i])) {
      auto &cur = numFactor[i][j];
      // bcout << "Computing " << cur.fi << " " << cur.se << endl;
      int findVal = (posInPrime[i][j] > 0 ? prefixSum[cur.fi][posInPrime[i][j] - 1].fi : 0);
      // gcout << findVal << endl;
      if (isPlus[i]) {
        int kiri = 0;
        int kanan = hi[cur.fi] - 1;
        while (kiri < kanan) {
          int mid = (kiri + kanan + 1) >> 1;
          if (findVal <= monotonicDeque[cur.fi][mid].fi) {
            kanan = mid - 1;
          } else {
            kiri = mid;
          }
        }
        if (palingKanan[cur.fi] != INF) keepMin.upd(palingKanan[cur.fi], -1);
        palingKanan[cur.fi] = monotonicDeque[cur.fi][kiri].se - 1;
        keepMin.upd(palingKanan[cur.fi], 1);
        // mcout << findVal << " " << monotonicDeque[cur.fi][kiri].fi << endl;
        // mcout << palingKanan[cur.fi] << endl;
      } else {
        if (palingKanan[cur.fi] != INF) keepMin.upd(palingKanan[cur.fi], -1);
        palingKanan[cur.fi] = i - 1;
        keepMin.upd(palingKanan[cur.fi], 1);
      }
      int putVal = prefixSum[cur.fi][posInPrime[i][j]].fi;
      while (monotonicDeque[cur.fi][hi[cur.fi] - 1].fi >= putVal) hi[cur.fi]--;
      if (sz(monotonicDeque[cur.fi]) == hi[cur.fi]) monotonicDeque[cur.fi].pb({putVal, i}), hi[cur.fi]++;
      else monotonicDeque[cur.fi][hi[cur.fi]] = {putVal, i}, hi[cur.fi]++;
    }
    ans += keepMin.findOrder(1) - i + 1;
    // rcout << "Curans : " << ans << endl;
  }
  cout << ans << endl;
}