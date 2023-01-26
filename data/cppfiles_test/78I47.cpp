#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N];
int t, n;
int cnt[11];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; i++) {
    int t = a[i];
    for (int j = 1; j <= 10; j++) {
      if ((t >> (j - 1)) & 1) cnt[j]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    bool flag = true;
    ;
    for (int j = 1; j <= 10; j++) {
      if (cnt[j] % i) {
        flag = false;
        break;
      }
    }
    if (flag) cout << i << " ";
  }
  cout << '\n';
}
int main() {
  cin >> t;
  while (t--) solve();
}
