#include <bits/stdc++.h>
using namespace std;
int n, t, p;
char a[10010], c, k;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    p = 0;
    scanf("%c", &c);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] != '?') p = 1;
    }
    if (!p) {
      for (int i = 1; i <= n; i++)
        if (i % 2 == 1)
          cout << 'B';
        else
          cout << 'R';
      cout << endl;
      continue;
    }
    for (int i = 1; i <= n; i++) {
      if (a[i - 1] == '?' && a[i] != '?') {
        k = i - 1;
        while (a[k] == '?') {
          if (a[k + 1] == 'B')
            a[k] = 'R';
          else
            a[k] = 'B';
          k--;
        }
      }
      if (a[i + 1] == '?' && a[i] != '?') {
        k = i + 1;
        while (a[k] == '?') {
          if (a[k - 1] == 'B')
            a[k] = 'R';
          else
            a[k] = 'B';
          k++;
        }
      }
    }
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << endl;
  }
  return 0;
}
