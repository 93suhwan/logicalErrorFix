#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int cnta = 0, cntb = 0, cntc = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A')
        cnta++;
      else if (s[i] == 'B')
        cntb++;
      else
        cntc++;
    }
    if (cnta + cntc == cntb && cnta + cntb + cntc >= 4)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
