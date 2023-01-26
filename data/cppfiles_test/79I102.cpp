#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937 rnd;
const long long maxn = 3e5 + 50;
const long long mod = 1e9 + 7;
const long long base = 3e18;
long long a[maxn];
long long b[maxn];
vector<long long> adj[maxn];
pair<long long, long long> st[4 * maxn];
pair<long long, long long> la[4 * maxn];
pair<long long, long long> par[maxn];
pair<long long, long long> mer(pair<long long, long long> a,
                               pair<long long, long long> b) {
  if (a.first > b.first) return b;
  return a;
}
void dosth(long long id, long long left, long long right) {
  st[id * 2] = mer(st[id * 2], la[id]);
  st[id * 2 + 1] = mer(st[id * 2 + 1], la[id]);
  la[id * 2] = mer(la[id * 2], la[id]);
  la[id * 2 + 1] = mer(la[id * 2 + 1], la[id]);
  la[id] = make_pair(base, -1);
}
void update(long long id, long long left, long long right, long long x,
            long long y, pair<long long, long long> diff) {
  if (x > right || y < left) return;
  if (x <= left && y >= right) {
    st[id] = mer(st[id], diff);
    la[id] = mer(la[id], diff);
    return;
  }
  dosth(id, left, right);
  long long mid = (left + right) / 2;
  update(id * 2, left, mid, x, y, diff);
  update(id * 2 + 1, mid + 1, right, x, y, diff);
}
pair<long long, long long> get(long long id, long long left, long long right,
                               long long x) {
  pair<long long, long long> nw = make_pair(base, -1);
  if (x > right || x < left) return nw;
  if (left == right) return st[id];
  dosth(id, left, right);
  long long mid = (left + right) / 2;
  return mer(get(id * 2, left, mid, x), get(id * 2 + 1, mid + 1, right, x));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    adj[x + i].push_back(i);
  }
  for (int id = 0; id <= 4 * n; id++) {
    st[id] = make_pair(base, -1);
    la[id] = make_pair(base, -1);
  }
  pair<long long, long long> ans = make_pair(base, -1);
  for (int i = n; i >= 1; i--) {
    pair<long long, long long> nw = make_pair(0, -1);
    if (i != n) {
      nw = make_pair(base, -1);
      for (auto to : adj[i]) {
        auto p = get(1, 1, n, to);
        if (p.first < nw.first) {
          nw = p;
          par[i] = make_pair(p.second, to - p.second);
        }
      }
    }
    if (nw.first == base) continue;
    pair<long long, long long> nxt = make_pair(nw.first + 1, (long long)i);
    update(1, 1, n, max(1ll, i - a[i]), i, nxt);
    if (i == a[i]) {
      ans = mer(ans, nxt);
    }
  }
  if (ans.first == base) {
    cout << -1;
    return 0;
  }
  vector<long long> res;
  long long nw = ans.second;
  res.push_back(0);
  while (nw != n) {
    res.push_back(par[nw].first + par[nw].second);
    nw = par[nw].first;
  }
  reverse(res.begin(), res.end());
  cout << res.size() << "\n";
  for (auto to : res) cout << to << " ";
}
