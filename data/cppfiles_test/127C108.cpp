#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long mul(long long x, long long y) { return (x * y) % MOD; }
long long sub(long long x, long long y) {
  if (x - y < 0) return x - y + MOD;
  return x - y;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string t;
    cin >> t;
    sort(s.begin(), s.end());
    long long s_iter(0);
    long long t_iter(0);
    while (s_iter < s.length() && t_iter < t.length()) {
      if (s[s_iter] == t[t_iter]) {
        s_iter++;
        t_iter++;
      } else {
        s_iter++;
      }
    }
    if (t_iter != t.length()) {
      cout << s << '\n';
      continue;
    }
    string lowest_t = "";
    for (long long i = 0; i < 3; i++) {
      for (long long j = 0; j < 3; j++) {
        for (long long k = 0; k < 3; k++) {
          if (i != j && j != k && i != k) {
            string curr_t = "";
            curr_t.push_back(t[i]);
            curr_t.push_back(t[j]);
            curr_t.push_back(t[k]);
            if (curr_t != t) {
              if (lowest_t == "")
                lowest_t = curr_t;
              else
                lowest_t = min(lowest_t, curr_t);
            }
          }
        }
      }
    }
    t = lowest_t;
    string second = "";
    string first = "";
    string third = "";
    string other = "";
    for (long long i = 0; i < s.length(); i++) {
      if (s[i] == t[0]) {
        first.push_back(t[0]);
      } else if (s[i] == t[1]) {
        second.push_back(t[1]);
      } else if (s[i] == t[2]) {
        third.push_back(t[2]);
      } else {
        other.push_back(s[i]);
      }
    }
    string res = first + second + third + other;
    cout << res << '\n';
  }
  return 0;
}
