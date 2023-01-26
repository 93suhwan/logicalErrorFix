#include <bits/stdc++.h>
using namespace std;
int t, n;
char x;
string s;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> t;
  while (t--) {
    int sum = 0, y;
    cin >> n >> x;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == x) {
        y = i + 1;
        sum++;
      }
    }
    if (sum == 0) {
      cout << "0" << endl;
    } else {
      if (y > n / 2)
        cout << "1\n" << x << endl;
      else
        cout << "2\n" << n << " " << n - 1 << endl;
    }
  }
  return 0;
}
