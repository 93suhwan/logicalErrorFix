#include <bits/stdc++.h>
using namespace std;
const int nh = 50013, m7 = 1000000007, m99 = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int o0o;
  cin >> o0o;
  while (o0o--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = n;
    for (int ch = 0; ch < 26; ch++) {
      int k = 0;
      for (int i = 0, h = n - 1; i < h;) {
        if (s[i] == s[h])
          i++, h--;
        else if (s[i] - 'a' == ch)
          i++, k++;
        else if (s[h] - 'a' == ch)
          h--, k++;
        else {
          k = n;
          break;
        }
      }
      c = min(c, k);
    }
    if (c == n) c = -1;
    cout << c << "\n";
  }
  return 0;
}
