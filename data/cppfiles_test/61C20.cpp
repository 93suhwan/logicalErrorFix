#include <bits/stdc++.h>
using namespace std;
const int N = 220;
int t, n;
char a[N], b;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> a + 1;
    int t = 1;
    while (a[t] == '?') t++;
    for (int i = t - 1; i >= 1; i--) {
      if (a[i + 1] == 'R')
        a[i] = 'B';
      else
        a[i] = 'R';
    }
    for (int i = t; i <= n; i++) {
      if (a[i] == '?') {
        if (a[i - 1] == 'R')
          a[i] = 'B';
        else
          a[i] = 'R';
      }
    }
    for (int i = 1; i <= n; i++) cout << a[i];
    puts("");
  }
  return 0;
}
