#include <bits/stdc++.h>
using namespace std;
const long long N = 1000000007;
bool help(string s, string ans) {
  if (ans >= s && ans.size() == s.size()) return true;
  if (ans.size() > s.size()) return false;
  long long a = s[0] - '0';
  long long b = s[1] - '0';
  ans += to_string(min(a, b));
  if (help(s, ans)) return true;
  ans = ans.substr(0, ans.size() - 1);
  ans += to_string(max(a, b));
  return help(s, ans);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    unordered_set<long long> st;
    long long y = n;
    while (y) {
      st.insert(y % 10);
      y /= 10;
    }
    if (st.size() <= k) {
      cout << n << "\n";
      continue;
    }
    string s = to_string(n);
    long long first = -1, second = -1;
    st.clear();
    for (long long i = 0; i < s.size(); i++) {
      if (first == -1) {
        first = s[i] - '0';
      } else {
        second = s[i] - '0';
      }
      st.insert(s[i] - '0');
      if (st.size() == k) break;
    }
    long long mn = min(first, second);
    long long mx = max(first, second);
    string ans;
    if (k == 1) {
      for (long long i = 1; i <= 9; i++) {
        string temp;
        for (long long j = 0; j < s.size(); j++) {
          temp += char(i + '0');
        }
        if (temp >= s) {
          ans = temp;
          break;
        }
      }
      cout << ans << "\n";
    } else {
      string temp;
      temp += s[0];
      char y = s[1];
      bool f = 0;
      for (long long i = 2; i < s.size(); i++) {
        if (s[i] > y) {
          f = 1;
          break;
        }
      }
      if (f == 1) {
        long long z = y - '0' + 1;
        temp += to_string(z);
        if (z == (s[0] - '0'))
          z = 0;
        else
          z = 1;
        for (long long i = 2; i < s.size(); i++) {
          temp += to_string(z);
        }
        ans = temp;
      } else {
        string t;
        ans = help(s, t);
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
