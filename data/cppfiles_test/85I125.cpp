#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long cur_mex = 0;
    for (long long i = 0; i < (long long)s.size(); ++i) {
      if (s[i] - '0' == cur_mex) cur_mex++;
    }
    long long mex = 0;
    for (long long i = 0; i < (long long)s.size(); ++i) {
      if (s[i] == '0') mex++;
      char c = s[i];
      cout << i << " ";
      for (; i < (long long)s.size(); ++i) {
        if (s[i] != c) break;
      }
      i--;
      cout << i << " ..\n";
    }
    cout << min(mex, cur_mex) << "\n";
  }
}
