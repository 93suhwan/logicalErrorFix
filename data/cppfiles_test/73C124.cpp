#include <bits/stdc++.h>
using namespace std;
bool check(int a[], int b[], int l) {
  for (int i = 1; i <= l; i++)
    if (a[i] != b[i]) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 1];
    int b[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    if (check(a, b, n)) {
      cout << 0 << "\n";
    } else {
      int c = 1;
      bool flag = false;
      while (1000) {
        if (c % 2 != 0) {
          for (int i = 1; i <= n - 2; i += 2) {
            if (a[i] > a[i + 1]) {
              int t = a[i];
              a[i] = a[i + 1];
              a[i + 1] = t;
            }
          }
        } else {
          for (int i = 2; i <= n - 1; i += 2) {
            if (a[i] > a[i + 1]) {
              int t = a[i];
              a[i] = a[i + 1];
              a[i + 1] = t;
            }
          }
        }
        flag = check(a, b, n);
        if (flag == true)
          break;
        else
          c++;
      }
      cout << c << "\n";
    }
  }
  return 0;
}
