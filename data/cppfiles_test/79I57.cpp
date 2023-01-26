#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
int n, a[N], b[N];
int par[N], t[N];
bool mark[N];
void solve() {
  set<int> S;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], S.insert(i);
  for (int i = 1; i <= n; i++) cin >> b[i];
  S.erase(n);
  queue<int> Q;
  Q.push(n);
  int ans = -1;
  while (!Q.empty()) {
    int x = Q.front();
    mark[x] = true;
    Q.pop();
    if (!Q.empty()) cout << Q.front() << '\n';
    if (a[x] >= x) {
      ans = t[x] + 1;
      break;
    }
    while (!S.empty()) {
      auto it = S.lower_bound(x - a[x]);
      if (it == S.end() || *it > x) break;
      if (mark[*it + b[*it]]) {
        S.erase(it);
        continue;
      }
      t[*it + b[*it]] = t[x] + 1;
      par[x] = *it;
      Q.push(*it + b[*it]);
      S.erase(it);
    }
  }
  cout << ans << '\n';
  int vx = n;
  while (ans > -1 && vx) {
    cout << par[vx] << ' ';
    vx = par[vx];
    vx += b[vx];
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int test_cases = 1;
  while (test_cases--) solve();
  return 0;
}
