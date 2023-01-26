#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n;
int a[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (true) {
      bool flag = true;
      for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) {
          flag = false;
          swap(a[i], a[i + 1]);
          i++;
        }
      }
      if (!flag)
        res++;
      else
        break;
    }
    cout << res << endl;
  }
  return 0;
}
