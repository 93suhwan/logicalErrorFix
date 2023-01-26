#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long cnr(long long a, long long b, long long m) {
  long long t = 1, d = 1;
  for (long long i = 1; i <= b; i++) {
    t = (t * i) % m;
    d = (d * (a - i + 1)) % m;
  }
  return ((d * binpow(t, (m - 2), m))) % m;
}
long long phi(long long n) {
  long long result = n;
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  if (n > 1) result -= result / n;
  return result;
}
const long long MOD = 1e9 + 7;
const long long INF = 2147483646;
const long long LLINF = 1e19;
const long long N = 5e5 + 9;
const long long maxn = 4e5 + 7;
long long f[maxn], cnt[maxn], pos[maxn];
long long sum[maxn], ans[maxn], now;
long long find(long long u) { return u == f[u] ? u : f[u] = find(f[u]); }
vector<pair<long long, long long>> del, qry;
long long a[maxn];
void t_main() {
  long long n, m, q;
  cin >> n >> m >> q;
  for (long long i = 1; i <= n + m; i++) {
    cin >> a[i];
    pos[i] = i;
  }
  sort(pos + 1, pos + 1 + n + m,
       [&](long long x, long long y) { return a[x] < a[y]; });
  for (long long i = 1; i <= n + m; i++) {
    f[i] = i;
    cnt[i] = (pos[i] <= n);
    sum[i] = sum[i - 1] + a[pos[i]];
    if (i < n + m) del.push_back(make_pair(a[pos[i + 1]] - a[pos[i]], i));
  }
  sort(del.begin(), del.end());
  for (long long i = 1; i <= q; i++) {
    pair<long long, long long> cur;
    cin >> cur.first;
    cur.second = i;
    qry.push_back(cur);
  }
  sort(qry.begin(), qry.end());
  for (long long i = 1; i <= n; i++) now += a[i];
  for (long long i = 0, ptr = 0; i < q; i++) {
    while (ptr < del.size() && del[ptr].first <= qry[i].first) {
      long long x = del[ptr].second;
      long long y = find(x + 1);
      now -= sum[x] - sum[x - cnt[x]];
      now -= sum[y] - sum[y - cnt[y]];
      f[x] = y;
      cnt[y] += cnt[x];
      now += sum[y] - sum[y - cnt[y]];
      ptr++;
    }
    ans[qry[i].second] = now;
  }
  for (long long i = 1; i <= q; i++) cout << ans[i] << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  while (tt--) t_main();
  return 0;
}
