#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 55;
char a[maxn];
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> a;
    if (n == 1)
      cout << -1 << " " << -1 << "\n";
    else {
      bool flag = false;
      for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
          cout << i << " " << i + 1 << "\n";
          break;
        }
      }
    }
  }
  return 0;
}
