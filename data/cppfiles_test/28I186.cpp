#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
int arr[300005], org[300005];
int vis[300005];
int idx[300005];
int chk(int k) {
  for (int i = 0; i <= n; i++) vis[i] = 0;
  for (int i = 0; i < n; i++) {
    arr[(i + k) % n + 1] = i + 1;
    idx[i + 1] = (i + k) % n + 1;
  }
  int ans = n;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    ans--;
    int cur = i;
    while (!vis[cur]) {
      vis[cur] = 1;
      cur = idx[org[cur]];
    }
  }
  return ans <= m;
}
int res[300005];
void solve() {
  int pivot = -1;
  cin >> n >> m;
  for (int i = 0; i < n; i++) res[i] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> org[i];
  }
  for (int i = 0; i < n; i++) {
    chk(i);
  }
  for (int stp = 0; stp <= 60; stp++) {
    int k = rng() % n;
    k++;
    k = (k - org[k] + n) % n;
    if (chk(k)) {
      pivot = k;
    }
  }
  if (pivot == -1) {
    cout << 0 << '\n';
  } else {
    int l, r;
    l = r = pivot;
    for (int k = 20; k >= 0; k--) {
      if (r + (1 << k) < n && chk(r + (1 << k))) r += (1 << k);
    }
    for (int k = 20; k >= 0; k--) {
      if (l - (1 << k) >= 0 && chk(l - (1 << k))) l -= (1 << k);
    }
    cout << r - l + 1;
    for (int i = l; i <= r; i++) cout << ' ' << i;
    cout << '\n';
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
