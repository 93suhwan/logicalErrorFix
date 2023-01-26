#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int add() { return 0; }
template <typename... M>
int add(int a, M... b) {
  int x = add(b...);
  return a + x - mod * (a + x >= mod);
}
int mul() { return 1; }
template <typename... M>
int mul(int a, M... b) {
  return int(1ll * a * mul(b...) % mod);
}
int pwr(int a, long long x) {
  return (x ? mul(pwr(mul(a, a), x >> 1), (x & 1 ? a : 1)) : 1);
}
int dvd(int a, int b) { return mul(a, pwr(b, mod - 2)); }
int sub(int a, int b) { return a - b + mod * (a < b); }
void inc(int& a, int b) { a = add(a, b); }
void dec(int& a, int b) { a = sub(a, b); }
vector<int> fact = {1}, invf = {1};
int C(int n, int k) {
  if (n < k or 0 > k) return 0;
  while (fact.size() <= n) {
    fact.push_back(mul(fact.back(), fact.size()));
    invf.push_back(dvd(1, fact.back()));
  }
  return mul(fact[n], invf[k], invf[n - k]);
}
const int N = 1e6 + 5;
int cntr[N][2];
int cntc[N][2];
int tot[2];
map<pair<int, int>, int> a;
bool badr(int i) { return cntr[i][0] and cntr[i][1]; }
bool detr(int i) { return cntr[i][0] or cntr[i][1]; }
bool badc(int i) { return cntc[i][0] and cntc[i][1]; }
bool detc(int i) { return cntc[i][0] or cntc[i][1]; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  int dr = 0, dc = 0, br = 0, bc = 0;
  while (q--) {
    int x, y, t;
    cin >> x >> y >> t;
    int ans = 0;
    if (a.count(make_pair(x, y))) {
      int cur = a[make_pair(x, y)];
      a.erase(make_pair(x, y));
      bool wasbr = badr(x);
      bool wasdr = detr(x);
      --cntr[x][(y & 1) ^ cur];
      if (wasbr and !badr(x)) {
        --br;
      }
      if (wasdr and !detr(x)) {
        --dr;
      }
      bool wasbc = badc(y);
      bool wasdc = detc(y);
      --cntc[y][(x & 1) ^ cur];
      if (wasbc and !badc(y)) {
        --bc;
      }
      if (wasdc and !detc(y)) {
        --dc;
      }
      --tot[(x + y + cur) & 1];
    }
    if (t == 0 or t == 1) {
      a[make_pair(x, y)] = t;
      bool wasbr = badr(x);
      bool wasdr = detr(x);
      ++cntr[x][(y & 1) ^ t];
      if (!wasbr and badr(x)) {
        ++br;
      }
      if (!wasdr and detr(x)) {
        ++dr;
      }
      bool wasbc = badc(y);
      bool wasdc = detc(y);
      ++cntc[y][(x & 1) ^ t];
      if (!wasbc and badc(y)) {
        ++bc;
      }
      if (!wasdc and detc(y)) {
        ++dc;
      }
      ++tot[(x + y + t) & 1];
    }
    if (br == 0) inc(ans, pwr(2, n - dr));
    if (bc == 0) inc(ans, pwr(2, m - dc));
    if (tot[0] == 0) dec(ans, 1);
    if (tot[1] == 0) dec(ans, 1);
    cout << ans << '\n';
  }
  return 0;
}
