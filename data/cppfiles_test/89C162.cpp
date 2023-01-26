#include <bits/stdc++.h>
using namespace std;
int n, a[100000 + 10];
void solve() {
  bool f = 0;
  for (int i = 1; i <= n; i++) {
    f = 0;
    for (int j = 2; j <= i + 1; j++) {
      if (a[i] % j != 0) {
        f = 1;
        break;
      }
    }
    if (!f) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    solve();
  }
}
