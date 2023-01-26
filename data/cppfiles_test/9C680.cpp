#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i, j, count = 0, add = 0, y[100], sum = 0, ac = 0, ay = 0;
    string a;
    cin >> a;
    n = a.length();
    for (i = 0; i <= 99; i++) {
      y[i] = 0;
    }
    for (i = 0; a[i]; i++) {
      count = a[i] - 'a';
      add++;
      if (y[count] == 0) {
        y[count] = add;
      } else {
        y[count] = y[count] + add;
      }
      add = 0;
    }
    for (i = 0; i < 100; i++) {
      if (y[i] > 1) {
        ac++;
      } else if (y[i] == 1) {
        ay++;
      }
    }
    cout << ac + ay / 2 << '\n';
  }
}
