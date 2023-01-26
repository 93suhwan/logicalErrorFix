#include <bits/stdc++.h>
using namespace std;
void go() {
  long long int n, x;
  cin >> n;
  char c;
  cin >> c;
  string s;
  cin >> s;
  long long int cnt = 0;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == c) cnt++;
  }
  if (cnt == n) {
    cout << "0\n";
    return;
  }
  for (long long int j = 2; j <= n; j++) {
    x = j;
    long long int flag = 0;
    while (x <= n) {
      if (s[x - 1] != c) {
        flag = 1;
        break;
      }
      x += j;
    }
    if (flag == 0) {
      cout << "1\n" << j << "\n";
      return;
    }
  }
  cout << "2\n" << n << " " << n - 1 << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    go();
  }
  return 0;
}
