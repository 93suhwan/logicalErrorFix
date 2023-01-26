#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s = "";
    cin >> s;
    int a = 0, b = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        a++;
      } else {
        b++;
      }
    }
    if ((a > 0) && (b > 0)) {
      size_t found = s.find("ab");
      if (found != string::npos)
        cout << found + 1 << " " << found + 2 << endl;
      else {
        size_t found = s.find("ba");
        if (found != string::npos)
          cout << found + 1 << " " << found + 2 << endl;
      }
    } else {
      cout << -1 << " " << -1 << endl;
    }
  }
  return 0;
}
