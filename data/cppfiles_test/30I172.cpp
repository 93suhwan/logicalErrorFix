#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, count = 0;
    cin >> n;
    string s;
    cin >> s;
    bool ans = false;
    for (int i = 0; i < 26; i++) {
      char dlt = 'a' + i;
      bool flag = true;
      count = 0;
      int start = 0, end = s.size() - 1;
      while (start <= end) {
        if (s[start] == s[end]) {
          start++;
          end--;
        } else if (s[start] == dlt) {
          start++;
          count++;
        } else if (s[end] == dlt) {
          end--;
          count++;
        } else {
          flag = false;
          break;
        }
      }
      if (flag) {
        ans = true;
        break;
      }
    }
    if (ans)
      cout << count << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
