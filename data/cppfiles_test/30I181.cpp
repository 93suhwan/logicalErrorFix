#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int T, n;
char a[N];
int main() {
  char s, q;
  int x, y;
  cin >> T;
  while (T--) {
    int ans = 0;
    bool flag = false;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int i = 0, j = n - 1;
    while (i < j) {
      if (a[i] == a[j]) {
        i++, j--;
      } else if (a[i] != a[j] && !flag) {
        flag = true;
        s = a[i];
        i++;
        ans++;
        q = a[j];
        x = i - 1;
        y = j - 1;
      } else if (a[i] != a[j]) {
        if (a[i] != s && a[j] != s) {
          ans = -1;
          break;
        }
        if (a[i] == s) {
          ans++;
          i++;
        }
        if (a[j] == s) {
          ans++;
          j--;
        }
      }
    }
    if (ans != -1)
      cout << ans << endl;
    else {
      ans = 1;
      while (x < y) {
        if (a[x] == a[y]) {
          x++, y--;
        } else {
          if (a[x] != q && a[y] != q) {
            ans = -1;
            break;
          }
          if (a[x] == q) {
            x++;
            ans++;
          }
          if (a[y] == q) {
            y--;
            ans++;
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
