#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string ans = "";
    int z = 0, it1 = n;
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < 2 * it1; k++) {
        if (k < it1) {
          ans += "(";
        } else {
          ans += ")";
        }
      }
      for (int j = 0; j < z; j++) {
        ans += "()";
      }
      z++;
      it1--;
      if (i != n - 1) {
        ans += "\n";
      }
    }
    cout << ans << endl;
  }
  return 0;
}
