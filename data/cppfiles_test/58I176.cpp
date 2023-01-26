#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, H = 2002, mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    bool f = true;
    for (int i = 1; i < n; ++i) {
      if ((s1[i] == s2[i] && s1[i] == '1') &&
          (s1[i - 1] == s2[i - 1] && s1[i - 1] == '1')) {
        f = false;
        break;
      }
    }
    if (f)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
