#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    int n, c1 = 1;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
      if (s[i] == '0') b[i] = c1++;
    for (int i = 0; i < n; i++)
      if (s[i] == '1') b[i] = c1++;
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << '\n';
  }
  return 0;
}
