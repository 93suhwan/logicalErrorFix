#include <bits/stdc++.h>
using namespace std;
char a[10000000];
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    memset(a, 0, sizeof(a));
    cin >> a;
    int t1 = 0, t2 = 0, l = strlen(a);
    for (int i = 0; i < l - 1; ++i) {
      if (a[i] - a[i + 1] > 0) t2++;
      if (a[i] - a[i + 1] < 0) t1++;
    }
    if (t1 > t2) {
      for (int i = 0; i < l; ++i) {
        if (a[i] == 'a' && a[i + 1] == 'a' && a[i + 2] == 'b')
          a[i] = 'b', i += 3;
        else if (a[i] == 'a' && a[i + 1] == 'b' && a[i + 2] == 'b')
          a[i] = 'b', i += 3;
      }
    } else if (t1 < t2) {
      for (int i = 0; i < l; ++i) {
        if (a[i] == 'b' && a[i + 1] == 'b' && a[i + 2] == 'a')
          a[i] = 'a', i += 3;
        else if (a[i] == 'b' && a[i + 1] == 'a' && a[i + 2] == 'a')
          a[i] = 'a', i += 3;
      }
    }
    cout << a << endl;
  }
  return 0;
}
