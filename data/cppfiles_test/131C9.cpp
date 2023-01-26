#include <bits/stdc++.h>
using namespace std;
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("1617E"
            ".inp",
            "r")) {
    freopen(
        "1617E"
        ".inp",
        "r", stdin);
    freopen(
        "1617E"
        ".out",
        "w", stdout);
  }
}
const bool love = true;
const int N = 2e5 + 2;
int n, a[N], p2[32];
void readinp() {
  cin >> n;
  for (int i = int(1); i <= int(n); i++) cin >> a[i];
  p2[0] = 1;
  for (int i = int(1); i <= int(31); i++) p2[i] = p2[i - 1] * 2;
}
int change(int val) {
  int k = 0, l = 0, r = 31;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (p2[mid] >= val) {
      r = mid - 1;
      k = mid;
    } else
      l = mid + 1;
  }
  return p2[k] - val;
}
int dis(int x, int y) {
  if (x == y) return 0;
  if (x > y) swap(x, y);
  return 1 + dis(x, change(y));
}
void solve() {
  pair<int, int> mx = {0, 0};
  for (int i = int(2); i <= int(n); i++)
    mx = max(mx, make_pair(dis(a[1], a[i]), i));
  int p = mx.second;
  mx = {0, 0};
  for (int i = int(1); i <= int(n); i++)
    if (i != p) mx = max(mx, make_pair(dis(a[p], a[i]), i));
  cout << p << ' ' << mx.second << ' ' << mx.first;
}
int main() {
  setIO();
  int t = 1;
  while (t--) {
    readinp();
    solve();
  }
  return 0;
}
