#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
string decimaltobinary(long long n) {
  string s;
  while (n) {
    s.push_back((n & 1) + '0');
    n = n >> 1;
  }
  reverse(s.begin(), s.end());
  return s;
}
bool found(string &s, string &t) {
  long long n = s.size(), m = t.size();
  for (long long i = 0; i < m - n + 1; i++) {
    bool flag = true;
    for (long long j = 0; j < n; j++) {
      if (s[j] != t[j + i]) {
        flag = false;
      }
    }
    if (flag) {
      for (long long j = 0; j < m; j++) {
        if (t[j] == '0' && (j < i || j > (i + n))) {
          flag = false;
        }
      }
    }
    if (flag) {
      return true;
    }
  }
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long x, y;
  cin >> x >> y;
  if (x == y)
    cout << "YES";
  else if (y % 2 == 0)
    cout << "NO";
  else {
    string s1 = decimaltobinary(x);
    string s2 = decimaltobinary(y);
    string s3;
    if (x % 2 == 0) {
      s1.push_back('1');
      s3 = s1;
      reverse(s3.begin(), s3.end());
      if (found(s1, s2) || found(s3, s2)) {
        cout << "YES";
      } else {
        s1.pop_back();
        while (s1.back() == '0') s1.pop_back();
        s3 = s1;
        reverse(s3.begin(), s3.end());
        if (found(s1, s2) || found(s3, s2)) {
          cout << "YES";
        } else {
          cout << "NO";
        }
      }
    } else {
      s3 = s1;
      reverse(s3.begin(), s3.end());
      if (found(s1, s2) || found(s3, s2)) {
        cout << "YES";
      } else {
        cout << "NO";
      }
    }
  }
  return 0;
}
