#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int flag = 0;
    if (n % 2 == 0) {
      flag = 1;
      for (int i = 0, j = n / 2; j < n; i++, j++) {
        if (s[i] != s[j]) {
          flag = 0;
          break;
        }
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
