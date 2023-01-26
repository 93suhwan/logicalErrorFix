#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:360777216")
using LL = long long;
using ld = long double;
const int INF = 2 * 1000 * 1000 * 1000;
LL MOD = 1e9 + 7;
LL LINF = (LL)4e18;
double EPS = 1e-7;
using namespace std;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return a / gcd(a, b) * b; }
const LL max_er = 1e2;
vector<LL> min_div(max_er + 1, 0);
vector<int> pp(max_er + 1, 1);
vector<LL> res(max_er + 1, -1);
vector<LL> primes;
void eratosfen() {
  pp[0] = pp[1] = 0;
  for (LL i = 2; i <= max_er; ++i) {
    if (!pp[i]) continue;
    primes.push_back(i);
    min_div[i] = i;
    for (LL j = i * i; j <= max_er; j += i) {
      pp[j] = 0;
      if (!min_div[j]) min_div[j] = i;
    }
  }
}
vector<pair<int, int> > divs;
void get_divs(LL n) {
  while (n != 1) {
    LL cur = min_div[n];
    LL cnt = 0;
    while (n % cur == 0) {
      n /= cur;
      cnt++;
    }
    divs.push_back({cur, cnt});
  }
}
int T[24 * 100];
void build(vector<int>& a, int v, int tl, int tr) {
  if (tl == tr)
    T[v] = a[tl] == 0;
  else {
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    T[v] = T[v * 2] + T[v * 2 + 1];
  }
}
void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    T[v] = val == 0;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(2 * v, tl, tm, pos, val);
    else
      update(2 * v + 1, tm + 1, tr, pos, val);
    T[v] = T[2 * v] + T[2 * v + 1];
  }
}
int get(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (tl == l && tr == r) return T[v];
  int tm = (tl + tr) / 2;
  return get(2 * v, tl, tm, l, min(tm, r)) +
         get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
}
bool check(vector<pair<LL, LL> >& a, LL mid) {
  if (mid == 1) return true;
  set<LL> ss;
  for (int(i) = 0; (i) < mid; (i)++) ss.insert(a[i].second);
  auto it_start = ss.begin();
  auto it_end = ss.end();
  it_end--;
  LL mn = *it_start;
  LL mx = *it_end;
  if (mx - mn + 1 == mid) return true;
  for (int(i) = mid; (i) < a.size(); (i)++) {
    ss.erase(a[i - mid].second);
    ss.erase(a[i].second);
    it_start = ss.begin();
    it_end = ss.end();
    it_end--;
    LL mn = *it_start;
    LL mx = *it_end;
    if (mx - mn + 1 == mid) return true;
  }
  return false;
}
LL binpow(LL a, LL n, LL mod) {
  if (n == 0) return 1ll;
  if (n % 2 == 1)
    return (binpow(a, n - 1, mod) * a) % mod;
  else {
    int b = binpow(a, n / 2, mod) % mod;
    return (b * b) % mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  srand(time(nullptr));
  LL _ = 1, n, m, l, r, k, h, w;
  cin >> _;
  for (int(__) = 0; (__) < _; (__)++) {
    cin >> n >> k;
    LL mod = 1000000007;
    LL ans = binpow(2ll, (n - 1) * k, mod);
    if (n % 2 == 1) ans++;
    ans %= mod;
    cout << ans << endl;
  }
  return 0;
}
