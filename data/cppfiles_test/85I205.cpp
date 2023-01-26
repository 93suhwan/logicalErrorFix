#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int count = 0;
    long long int max_ans = 2;
    long long int i = 1;
    if (s[0] == '0') {
      count++;
      for (; i < s.length(); i++)
        if (s[i] == '1') {
          i++;
          break;
        }
    }
    for (; i < s.length(); i++)
      if (s[i] != s[i - 1]) count++;
    cout << min(max_ans, count) << endl;
  }
}
