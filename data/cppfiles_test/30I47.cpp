#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, count;
    cin >> n;
    string s;
    cin >> s;
    bool flag;
    for (int i = 0; i < 26; i++) {
      count = 0;
      flag = true;
      char dlt = 'a' + i;
      int start = 0, end = s.size() - 1;
      while (start < end) {
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
      if (flag) break;
    }
    if (flag)
      cout << count << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
