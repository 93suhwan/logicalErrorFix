#include <bits/stdc++.h>
using namespace std;
long long findsteps(string s, string str) {
  long long count = 0;
  long long i = 0;
  long long j = 0;
  while (i < s.size() && j < str.size()) {
    if (s[i] == str[j]) {
      i++;
      j++;
    } else {
      count++;
      i++;
    }
  }
  if (i == s.size()) {
    count += (str.size() - j);
  }
  if (j == str.size()) {
    count += (s.size() - i);
  }
  return count;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long ans = INT_MAX;
    long long k = 1;
    for (long long i = 0; i < 63; i++) {
      long long number = k;
      string str = to_string(number);
      long long x = findsteps(s, str);
      if (x < ans) {
        ans = x;
      }
      k *= 2;
    }
    cout << ans << endl;
  }
}
