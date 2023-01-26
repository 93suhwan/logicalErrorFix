#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[2] == a[1] + a[0] || (a[0] == a[1] && a[2] % 2 == 0) ||
        (a[0] % 2 == 0 && a[1] == a[2])) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << '\n';
  }
  return 0;
}
