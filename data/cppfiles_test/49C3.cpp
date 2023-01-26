#include <bits/stdc++.h>
using namespace std;
auto start = std::chrono::high_resolution_clock::now();
long double crrtime() {
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  return ((long double)duration.count()) / ((long double)1e9);
}
mt19937 rng(2);
int inline randn(int L, int R) {
  uniform_int_distribution<int> uid(L, R);
  return uid(rng);
}
int inline randn(int N) {
  uniform_int_distribution<int> uid(0, N - 1);
  return uid(rng);
}
const long long mod = 998244353;
long long n, q;
vector<long long> ch[1000001];
vector<pair<long long, pair<long long, long long> > > qr[1000001];
long long a[1000001];
long long ans[1000001];
long long c[1000001];
long long s[1000001];
long long tot;
set<long long> st[1000001];
void dfs(long long x) {
  long long xx = a[x];
  if (c[xx] == 0) tot++;
  st[c[xx]].erase(xx);
  s[c[xx]]--;
  c[xx]++;
  st[c[xx]].insert(xx);
  for (auto aa : qr[x]) {
    long long pos = aa.first;
    long long l = aa.second.first;
    long long k = aa.second.second;
    if (s[l - 1] + k > 0) {
      ans[pos] = -1;
      continue;
    }
    long long L = 1;
    long long R = n;
    long long target = s[l - 1] + k;
    while (L < R) {
      long long m = (L + R) / 2;
      if (s[m] < target)
        L = m + 1;
      else
        R = m;
    }
    ans[pos] = *(st[L].begin());
  }
  for (auto y : ch[x]) dfs(y);
  st[c[xx]].erase(xx);
  c[xx]--;
  st[c[xx]].insert(xx);
  s[c[xx]]++;
  if (c[xx] == 0) tot--;
}
void solve() {
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 0; i <= n; i++) {
    ch[i].clear();
    qr[i].clear();
    st[i].clear();
    c[i] = 0;
    s[i] = 0;
    tot = 0;
  }
  for (long long i = 2; i <= n; i++) {
    long long x;
    cin >> x;
    ch[x].push_back(i);
  }
  for (long long i = 0; i < q; i++) {
    long long v, l, k;
    cin >> v >> l >> k;
    qr[v].push_back({i, {l, k}});
  }
  dfs(1);
  for (long long i = 0; i < q; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
signed main() {
  start = std::chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  cin >> tt;
  for (long long tc = 1; tc <= tt; ++tc) {
    solve();
  }
}
