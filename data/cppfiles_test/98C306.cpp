#include <bits/stdc++.h>
using namespace std;
const int N = 60;
int n;
char a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> a + 1;
    bool flag = 0;
    for (int i = 2; i <= n; i++) {
      if (a[i] != a[i - 1]) {
        cout << i - 1 << " " << i << "\n";
        flag = 1;
        break;
      }
    }
    if (!flag)
      cout << "-1 -1"
           << "\n";
  }
  return 0;
}
