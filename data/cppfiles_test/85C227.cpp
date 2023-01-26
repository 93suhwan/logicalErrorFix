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
    if (s[0] == '0') count++;
    for (long long int i = 1; i < s.length(); i++)
      if (s[i] == '0' && s[i - 1] == '1') count++;
    cout << min(max_ans, count) << endl;
  }
}
