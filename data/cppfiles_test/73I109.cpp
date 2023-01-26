#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n;
int a[maxn];
bool check() {
  for (int i = 1; i <= n; i++) {
    if (a[i] != i) return false;
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (true) {
      bool flag = true;
      if (res % 2 == 0) {
        for (int i = 1; i < n; i += 2) {
          if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            flag = false;
          }
        }
      } else {
        for (int i = 2; i < n; i += 2) {
          if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            flag = false;
          }
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
