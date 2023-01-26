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
      if (a[i] - a[i + 1] == 1) t2++;
      if (a[i] - a[i + 1] == -1) t1++;
    }
    if (t1 > t2) {
      if (a[0] == 'b')
        a[0] = 'a';
      else
        a[0] = 'b';
    } else if (t1 < t2) {
      if (a[l - 1] == 'b')
        a[l - 1] = 'a';
      else
        a[l - 1] = 'b';
    }
    cout << a << endl;
  }
  return 0;
}
