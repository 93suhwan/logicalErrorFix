#include <bits/stdc++.h>
long long _ = 0, Case = 1;
using namespace std;
const long long N = 200100;
long long st[N];
vector<long long> h[N];
void solve(long long Case) {
  long long n;
  cin >> n;
  vector<long long> a(n + 1), b(n + 1);
  map<long long, long long> mp1, mp2;
  for (long long i = 1; i <= n; i++) cin >> a[i], mp1[a[i]] = i;
  for (long long i = 1; i <= n; i++) cin >> b[i], mp2[b[i]] = i;
  sort(a.begin() + 1, a.end());
  sort(b.begin() + 1, b.end());
  for (long long i = 1; i <= n - 1; i++) {
    long long u = mp1[a[i]], v = mp1[a[i + 1]];
    h[u].push_back(v);
    u = mp2[b[i]], v = mp2[b[i + 1]];
    h[u].push_back(v);
  }
  long long ps = *max_element(a.begin(), a.end());
  long long start = mp1[ps];
  queue<long long> q;
  q.push(start);
  vector<long long> vis(n + 1, 0);
  while (q.size()) {
    auto t = q.front();
    q.pop();
    vis[t] = true;
    for (auto i : h[t]) {
      if (vis[i]) continue;
      q.push(i);
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (vis[i])
      cout << 1;
    else
      cout << 0;
  }
  cout << '\n';
  for (long long i = 1; i <= n; i++) h[i].clear();
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> _;
  for (Case = 1; Case <= _; Case++) solve(Case);
  return 0;
}
