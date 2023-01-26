#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long i, j, k, l, n, p, q, c = 0, d = 0, sum = 0, flag = 0;
    char x;
    cin >> n >> x;
    string s;
    cin >> s;
    for (i = 0; i < n; i++) {
      if (s[i] != x) {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      cout << 0 << endl;
    else {
      flag = 0;
      for (i = n - 1; i >= (n) / 2; i--) {
        if (s[i] == x) {
          k = i + 1;
          flag = 1;
          break;
        }
      }
      if (flag == 1) {
        cout << 1 << "\n";
        cout << k << endl;
      } else {
        cout << 2 << endl;
        if (n % 2 == 0 && n != 4) {
          cout << n << "\n";
          cout << n - 2 << "\n";
        } else {
          if (n != 4) {
            cout << 2 << endl;
            cout << n << endl;
          } else {
            cout << 2 << endl;
            cout << 3 << endl;
          }
        }
      }
    }
  }
}
