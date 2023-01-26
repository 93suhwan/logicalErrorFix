#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int p[30] = {0};
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) p[s[i] - 'a']++;
    int res = 0, k = 0;
    for (int i = 0; i < 30; i++) {
      if (p[i] >= 2)
        res++;
      else if (p[i] == 1) {
        k++;
        if (k == 2) {
          res++;
          k = 0;
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
