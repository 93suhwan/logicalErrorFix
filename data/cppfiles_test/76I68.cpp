#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e18;
const long long mod = 1e9 + 9;
const long long inf = 1e9;
const long double EPS = 1e-12;
const long double Pi = acosl(-1);
const long long P = 31;
const long long dx[4] = {0, 0, 1, -1};
const long long dy[4] = {1, -1, 0, 0};
long long qqq = 1;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long n, m, perm[90], a[60][60];
vector<long long> g[200009];
vector<pair<long long, long long>> q;
void solve() {
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
    q.push_back({u - 1, v - 1});
    q.push_back({v - 1, u - 1});
  }
  if (n <= 50) {
    for (long long i = 0; i < n - 5; i++) {
      perm[i] = 0;
    }
    for (long long i = n - 5; i < n; i++) {
      perm[i] = 1;
    }
    for (long long i = 0; i < n; i++) {
      for (auto j : g[i]) {
        a[i][j] = 1;
      }
    }
    do {
      vector<long long> v;
      for (long long i = 0; i < n; i++) {
        if (perm[i] == 1) {
          v.push_back(i);
        }
      }
      long long ans = 0;
      for (long long i = 0; i < (long long)v.size(); i++) {
        for (long long j = i + 1; j < (long long)v.size(); j++) {
          ans += a[v[i]][v[j]];
        }
      }
      if (ans == 0 || ans == 25) {
        for (auto i : v) {
          cout << i + 1 << ' ';
        }
        cout << '\n';
        return;
      }
    } while (next_permutation(perm, perm + n));
    cout << "-1\n";
    return;
  }
  for (long long cnt = 0; cnt <= 100; cnt++) {
    vector<long long> v(5);
    vector<long long> used(n);
    for (long long i = 0; i < 5; i++) {
      v[i] = rnd() % n;
      while (used[v[i]]) {
        v[i] = rnd() % n;
      }
      used[v[i]] = 1;
    }
    long long ans = 0;
    for (auto i : q) {
      ans += (used[i.first] && used[i.second]);
    }
    if (ans == 0 || ans == 20) {
      for (auto i : v) {
        cout << i + 1 << ' ';
      }
      cout << '\n';
      return;
    }
  }
  cout << "-1\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  clock_t tStart = clock();
  while (qqq--) {
    solve();
  }
  cerr << "Runtime is:" << (long double)(clock() - tStart) / CLOCKS_PER_SEC
       << '\n';
  return 0;
}
