#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int a[maxn];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int d = 2;
    int flag = 1;
    for (int i = 1; i <= n; i++) {
      if (d > i + 1) {
        flag = 0;
        break;
      }
      if (a[i] % d)
        continue;
      else {
        i--;
        d++;
      }
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
