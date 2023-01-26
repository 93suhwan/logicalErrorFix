#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    long long cnt = 0;
    for (long long i = 0; i < n; i++)
      if (s2[i] == '1') {
        if (i != 0 && s1[i - 1] == '1') {
          s1[i - 1] = '2';
          cnt++;
        } else if (s1[i] == '0') {
          s1[i] = '2';
          cnt++;
        } else if (i != n - 1 && s1[i + 1] == '1') {
          s1[i + 1] = '2';
          cnt++;
        }
      }
    cout << cnt << endl;
  }
  return 0;
}
