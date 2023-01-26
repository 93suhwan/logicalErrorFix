#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int a[N];
void solve() {
  for (int i = 1; i <= 7; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < 7 - 1; i++) {
    for (int j = i + 1; j <= 7 - 1; j++) {
      for (int k = j + 1; k <= 7; k++) {
        bool ok = 0;
        for (int q = 1; q <= 7; q++) {
          if (a[i] == a[q] || a[j] == a[q] || a[k] == a[q]) continue;
          if (a[i] + a[j] == a[q]) continue;
          if (a[i] + a[k] == a[q]) continue;
          if (a[k] + a[j] == a[q]) continue;
          if (a[i] + a[j] + a[k] != a[q]) {
            ok = 1;
            break;
          }
        }
        if (ok == 0) {
          cout << a[i] << ' ' << a[j] << ' ' << a[k] << '\n';
          return;
        }
      }
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  exit(0);
}
