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
      set<char> st;
      for (long long i = 1; i < s.size(); i++) {
        st.insert(s[i]);
      }
      auto it = st.end();
      it--;
      char x = *(it);
      char y = s[0];
      char z = s[0];
      if (st.size() > 1) {
        it--;
        y = *(it);
      }
      if (z < x && y < x) {
        long long rr = s[1] - '0';
        rr += 1;
        y = char(rr + '0');
        temp += y;
        for (long long j = 2; j < s.size(); j++) {
          temp += min(z, y);
        }
        ans = temp;
      } else {
        y = s[1];
        for (long long i = 1; i < s.size(); i++) {
          if (min(z, y) < s[i]) {
            if (max(z, y) > s[i]) {
              temp += max(z, y);
              for (long long j = i + 1; j < s.size(); j++) {
                temp += min(z, y);
              }
              ans = temp;
              break;
            } else {
              temp += max(z, y);
            }
          } else if (min(z, y) > s[i]) {
            for (long long j = i; j < s.size(); j++) {
              temp += min(z, y);
            }
            ans = temp;
            break;
          } else {
            temp += min(z, y);
          }
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
