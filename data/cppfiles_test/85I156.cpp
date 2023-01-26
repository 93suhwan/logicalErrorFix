#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() == 1) {
      if (s[0] == '0')
        cout << 1 << endl;
      else
        cout << 0 << endl;
      continue;
    }
    long long a, ans = 0, arr[2] = {0}, key = 0, i;
    for (i = 0; i < s.size() - 1; i++) {
      if (s[i] != s[i + 1]) {
        arr[s[i] - 48]++;
      }
    }
    if (arr[0] == 0 && arr[1] == 0) {
      if (s[0] == '0')
        cout << 1 << endl;
      else
        cout << 0 << endl;
    } else if (arr[0] == 1 && arr[1] == 1) {
      if (s[0] == s[s.size() - 1])
        if (s[0] == '1')
          cout << 1 << endl;
        else
          cout << 2 << endl;
    } else if (arr[0] == 1)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
  return 0;
}
