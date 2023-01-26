#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int a[MAXN];
int n;
void solve() {
  cin >> n;
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      if (a[i] == a[i - 1])
        ans += 5;
      else
        ans++;
    }
    if (a[i] == 0) {
      if (a[i] == a[i - 1] && i >= 2) {
        ans = -1;
        break;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
