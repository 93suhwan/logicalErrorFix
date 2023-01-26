#include <bits/stdc++.h>
using namespace std;
int fun(string &s1, string &s2) {
  int i = 0, j = 0, count = 0;
  while (i < s1.length() && j < s2.length()) {
    if (s1[i] == s2[j]) {
      i++;
      j++;
      count++;
    } else
      i++;
  }
  return s1.length() + s2.length() - 2 * count;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  while (test--) {
    long long x;
    cin >> x;
    string s1 = to_string(x);
    int ans = INT_MAX, i = 0;
    x = 1;
    do {
      string s2 = to_string(x);
      ans = min(ans, fun(s1, s2));
      x = x << 1;
    } while (x <= 2 * 1e18);
    cout << ans;
    cout << "\n";
  }
  return 0;
}
