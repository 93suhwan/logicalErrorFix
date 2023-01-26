#include <bits/stdc++.h>
using namespace std;
int t, n;
char a[2][101];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    bool f = 0;
    for (int i = 1; i <= n; i++) cin >> a[0][i];
    for (int i = 1; i <= n; i++) {
      cin >> a[1][i];
      if (a[1][i] == '1' && a[0][i] == '1') f = 1;
    }
    if (f)
      puts("NO");
    else
      puts("YES");
  }
}
