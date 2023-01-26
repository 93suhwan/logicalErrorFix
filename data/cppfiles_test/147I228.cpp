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
    if (n == 2 && cnt_e == 1 && cnt_n == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
