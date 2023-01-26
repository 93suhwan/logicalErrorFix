#include <bits/stdc++.h>
using namespace std;
const long long mx = 100005;
const long long mod = 1000000007;
int cnt(string s, char ch) {
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == ch) return i;
  }
}
void testCase(int tc) {
  string c, s;
  cin >> c >> s;
  int ans = 0;
  for (int i = 1; i < s.length(); ++i) {
    int d = abs(cnt(c, s[i]) - cnt(c, s[i - 1]));
    ans += d;
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) testCase(i);
}
