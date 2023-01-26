#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int t, n, segs[N], arr[N + 5], arr2[N + 5];
bool check(int m) {
  m++;
  for (int i = 1; i <= m; i++) arr[i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int i = 1; i <= m; i++) arr2[i] = arr[i];
    for (int j = 1; j <= m; j++) {
      if (arr[j] == i - 1) {
        if (j - segs[i] >= 1) arr2[j - segs[i]] = max(arr2[j - segs[i]], i);
        if (j + segs[i] <= m) arr2[j + segs[i]] = max(arr2[j + segs[i]], i);
      }
    }
    for (int i = 1; i <= m; i++) arr[i] = arr2[i];
  }
  for (int i = 1; i <= m; i++)
    if (arr[i] == n) return true;
  return false;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> segs[i];
  int l = 0, r = N - 1;
  while (r - l > 1) {
    int m = l + (r - l) / 2;
    if (check(m))
      r = m;
    else
      l = m;
  }
  cout << r << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    solve();
  }
}
