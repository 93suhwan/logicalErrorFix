#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
int a[maxn];
bool Permu() {
  for (int i = 1; i <= n; ++i) {
    if (a[i] != i) return 0;
  }
  return 1;
}
void Solve(int Test) {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  if (Permu()) {
    cout << 0 << "\n";
    return;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == i) continue;
    if (a[i] < i) {
      cout << -1 << "\n";
      return;
    }
    if (a[i] % (a[i] - i) != i) {
      cout << -1 << "\n";
      return;
    }
    ans++;
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  if (fopen("CF"
            ".inp",
            "r")) {
    freopen(
        "CF"
        ".inp",
        "r", stdin);
    freopen(
        "CF"
        ".out",
        "w", stdout);
  }
  int test = 1;
  cin >> test;
  for (int i = 1; i <= test; ++i) {
    Solve(i);
  }
}
