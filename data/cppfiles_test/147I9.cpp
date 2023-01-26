#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int cnt_e = 0, cnt_n = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'E')
        cnt_e++;
      else
        cnt_n++;
    }
    if (cnt_e == cnt_n)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
