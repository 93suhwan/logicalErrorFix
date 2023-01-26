#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const long long INF = 1e18 + 56;
const long long NINF = -1 * INF;
void solve(long long t) {
  long long n, q;
  cin >> n >> q;
  set<long long> extra;
  set<long long> arr[n + 1];
  long long a, b, c;
  vector<long long> vis(n + 1, 0);
  for (long long i = 1; i <= q; i++) {
    cin >> a >> b >> c;
    extra.insert(b);
    if (a > c) swap(a, c);
    arr[a].insert(c);
  }
  for (long long i = 1; i <= n; i++) {
    for (auto it = arr[i].begin(); it != arr[i].end(); it++) {
      long long test = *it;
      if (vis[test] == 0) {
        cout << i << " " << test << "\n";
        vis[test] = 1;
      }
    }
  }
  for (auto it = extra.begin(); it != extra.end(); it++) {
    long long test = *it;
    if (vis[test] == 0) {
      cout << "1 " << test << "\n";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(), cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
