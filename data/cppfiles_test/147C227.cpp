#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, br = 0;
  cin >> t;
  string a[t];
  for (int i = 0; i < t; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < a[i].length(); j++) {
      if (a[i][j] == 'N') {
        br++;
      }
    }
    if (br == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
    br = 0;
  }
  return 0;
}
