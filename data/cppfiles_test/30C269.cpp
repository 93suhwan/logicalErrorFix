#include <bits/stdc++.h>
using namespace std;
long long solve(string s, char c, long long n) {
  long long left = 0, right = n - 1;
  long long ans = 0;
  while (left < right) {
    if (s[left] == s[right]) {
      left++;
      right--;
    } else if (s[left] == c) {
      left++;
      ans++;
    } else if (s[right] == c) {
      right--;
      ans++;
    } else
      return 100000000000000000;
  }
  return ans;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long arr[26] = {0};
    for (long long i = 0; i < s.length(); i++) {
      arr[s[i] - 'a']++;
    }
    string t = "abcdefghijklmnopqrstuvwxyz";
    long long ans = 100000000;
    char c1 = 'a';
    for (long long i = 0; i < 26; i++) {
      long long val = solve(s, t[i], n);
      if (ans > val) ans = val;
    }
    if (ans == 100000000) {
      cout << -1 << "\n";
    } else
      cout << ans << "\n";
  }
  return 0;
}
