#include <bits/stdc++.h>
using namespace std;
string seq, a;
string t;
int main() {
  getline(cin, t);
  int T = t[0] - '0';
  while (T--) {
    getline(cin, seq);
    getline(cin, a);
    int last;
    int ans = 0;
    for (int i = 0; i < (int)a.length(); i++) {
      int j;
      for (j = 0; j < (int)seq.length(); j++) {
        if (seq[j] == a[i]) break;
      }
      if (i == 0)
        last = j;
      else {
        ans += abs(j - last);
        last = j;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
