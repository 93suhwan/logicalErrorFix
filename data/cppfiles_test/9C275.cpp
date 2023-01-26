#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k = 1, count = 0;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int length = s.size();
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[i - 1]) {
        count++;
        if (count >= 2)
          continue;
        else {
          k++;
        }
      } else {
        count = 0;
        k++;
      }
    }
    if (length == 1) k = 0;
    cout << k / 2 << "\n";
  }
  return 0;
}
