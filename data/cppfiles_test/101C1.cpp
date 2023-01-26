#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    int z = 1;
    cin >> n;
    int a[n + 5], b[n * 2 + 5];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i + 1] = 0;
    }
    string s;
    cin >> s;
    int blue[n + 5], red[n + 5];
    int j = 0, k = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'B') {
        blue[j] = a[i], j++;
      } else
        red[k] = a[i], k++;
    }
    sort(blue, blue + j);
    sort(red, red + k);
    int x = 0;
    if (k == 0) red[0] = n;
    for (int i = 1; i <= j; i++) {
      if (blue[i - 1] < i) {
        z = 0;
        break;
      }
    }
    if (red[0] > j + 1 || z == 0) {
      cout << "NO" << endl;
      continue;
    } else {
      for (int i = 0; i < k; i++) {
        if (red[i] <= j + 1)
          j++;
        else {
          z = 0;
          break;
        }
      }
    }
    if (z)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
