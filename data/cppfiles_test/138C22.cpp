#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
double eps = 1e-12;
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
template <typename T>
void get_ar(T *ar, long long n) {
  for (long long i = 0; i < n; i++) cin >> ar[i];
}
template <typename T>
void printar(T *ar, long long n) {
  for (long long i = 0; i < n; i++) cout << ar[i] << " ";
  cout << "\n";
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long imod(long long a, long long m) { return power(a, m - 2, m); }
template <typename T, size_t N, size_t M>
void print2dArray(T (&theArray)[N][M], long long n = N, long long m = M) {
  for (long long x = 0; x < n; x++) {
    for (long long y = 0; y < m; y++) {
      cout << theArray[x][y] << " ";
    }
    cout << "\n";
  }
}
template <typename T, size_t N>
void print_ar(T (&theArray)[N], long long n = N) {
  for (long long x = 0; x < n; x++) {
    cout << theArray[x] << " ";
  }
  cout << "\n";
}
struct DSU {
  long long connected;
  vector<long long> par, sz, mi, ma;
  void init(long long n) {
    par = sz = mi = ma = vector<long long>(n + 1, 0);
    for (long long i = 1; i <= n; i++)
      par[i] = i, sz[i] = 1, mi[i] = i, ma[i] = i;
    connected = n;
  }
  long long getPar(long long u) {
    while (u != par[u]) {
      par[u] = par[par[u]];
      u = par[u];
    }
    return u;
  }
  long long getSize(long long u) { return sz[getPar(u)]; }
  void merge(long long u, long long v) {
    long long par1 = getPar(u), par2 = getPar(v);
    if (par1 == par2) return;
    connected--;
    if (sz[par1] > sz[par2]) swap(par1, par2);
    long long aa = min(mi[par1], mi[par2]);
    long long bb = max(ma[par1], ma[par2]);
    sz[par2] += sz[par1];
    sz[par1] = 0;
    par[par1] = par[par2];
    mi[par2] = aa;
    ma[par2] = bb;
  }
};
DSU dd;
vector<long long> pres, pref;
long long give(long long p1) {
  long long l = dd.mi[p1], r = dd.ma[p1];
  long long tot = pres[r] - pres[l - 1];
  long long ans = pref[r] - pref[r - tot];
  return ans;
}
void solve() {
  long long n, m, q, K, ans = 0, tmp;
  cin >> n >> m >> q;
  vector<long long> a(n), b(m);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i];
  }
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<vector<long long> > temp;
  temp.push_back({0, 0});
  for (long long i = 0; i < n; i++) {
    temp.push_back({a[i], 1});
  }
  for (long long i = 0; i < m; i++) {
    temp.push_back({b[i], 0});
  }
  dd.init(n + m + 1);
  sort((temp).begin(), (temp).end());
  pres.resize(n + m + 1, 0);
  pref.resize(n + m + 1, 0);
  for (long long i = 1; i < ((long long)(temp).size()); i++) {
    pres[i] = pres[i - 1] + temp[i][1];
    pref[i] = pref[i - 1] + temp[i][0];
  }
  vector<vector<long long> > diff;
  for (long long i = 1; i < ((long long)(temp).size()) - 1; i++) {
    diff.push_back({temp[i + 1][0] - temp[i][0], i});
  }
  sort((diff).begin(), (diff).end());
  long long cur = 0;
  vector<vector<long long> > quer;
  for (long long i = 0; i < q; i++) {
    long long x;
    cin >> x;
    quer.push_back({x, i});
  }
  sort((quer).begin(), (quer).end());
  vector<long long> fin(q, 0);
  for (auto x : quer) {
    long long k = x[0], ind = x[1];
    while (cur < ((long long)(diff).size()) && diff[cur][0] <= k) {
      long long p1 = dd.getPar(diff[cur][1]), p2 = dd.getPar(diff[cur][1] + 1);
      ans -= give(p1);
      ans -= give(p2);
      dd.merge(p1, p2);
      long long pa = dd.getPar(p1);
      ans += give(pa);
      cur++;
    }
    fin[ind] = ans;
  }
  for (long long i = 0; i < q; i++) {
    cout << fin[i] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  for (long long it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
