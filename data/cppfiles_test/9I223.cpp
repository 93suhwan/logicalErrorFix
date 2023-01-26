#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long int t;
  cin >> t;
  while (t--) {
    int ay, ac, count = 0, add = 0, n, i, j, flag = 0;
    string a;
    char ch[100];
    cin >> a;
    n = a.length();
    for (i = 0; i < n; i++) {
      if (a[i] == a[n - i - 1]) {
        flag = 1;
      } else {
        flag = 0;
        break;
      }
    }
    if (flag == 1 && n != 1)
      cout << "1" << '\n';
    else if (flag == 0 && n != 1)
      cout << n / 2 << '\n';
    else
      cout << "0" << '\n';
  }
}
