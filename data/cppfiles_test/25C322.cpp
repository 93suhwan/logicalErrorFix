#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int i, j, n;
    string s, t;
    cin >> s >> t;
    int n1 = s.size();
    int n2 = t.size();
    int flag = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != t[0]) continue;
      int k = i;
      int c = 0;
      while (k < n1 && c < n2 && s[k] == t[c]) {
        int k1 = k - 1;
        int c1 = c + 1;
        while (k1 >= 0 && c1 < n2 && s[k1] == t[c1]) {
          k1--;
          c1++;
        }
        if (c1 == n2) {
          flag = 1;
          break;
        }
        k++;
        c++;
      }
      if (c == n2) flag = 1;
      if (flag) {
        break;
      }
    }
    if (flag)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
    ;
  }
  return 0;
}
