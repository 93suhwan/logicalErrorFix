#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  for (int d = 0; d < q; d++) {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    n = n % 2;
    m = m % 2;
    int y = abs(n - m);
    int j = 0;
    for (int i = y; i < s.size(); i++) {
      if (s[i] == t[j]) {
        j++;
      } else {
        i++;
      }
      if (j == t.size()) {
        break;
      }
    }
    if (j == t.size()) {
      cout << "YES" << '\n';
      ;
    } else {
      cout << "NO" << '\n';
      ;
    }
  }
}
