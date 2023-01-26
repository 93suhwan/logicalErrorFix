#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
const int MXINF = 0x3f3f3f3f;
const int MNINF = 0x7f7f7f7f;
const ull MOD = 1000000007;
const int MAXN = 8192;
vector<int> g[MAXN + 5];
int ans[MAXN + 5], r[MAXN + 5];
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i <= MAXN; i++) {
    ans[i] = 0;
    r[i] = MAXN;
    g[i].push_back(0);
  }
  ans[0] = 1;
  for (int i = 0; i < n; i++) {
    for (auto x : g[a[i]]) {
      int val = x ^ a[i];
      ans[val] = 1;
      while (r[val] > a[i]) {
        g[r[val]].push_back(val);
        r[val]--;
      }
    }
    g[a[i]] = {};
  }
  int cnt = 0;
  for (int i = 0; i <= MAXN; i++) cnt += ans[i];
  cout << cnt << endl;
  for (int i = 0; i <= MAXN; i++)
    if (ans[i]) cout << i << " ";
  cout << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
