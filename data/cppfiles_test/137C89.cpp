#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
const long long M = 64;
string convert(long long n) {
  bitset<M> bst = n;
  string s = bst.to_string();
  reverse(s.begin(), s.end());
  while (s.back() == '0') s.pop_back();
  reverse(s.begin(), s.end());
  return s;
}
bool check(string &a, string &b) {
  long long n = a.size(), m = b.size();
  for (long long i = 0; i < m - n + 1; i++) {
    bool flag = true;
    for (long long j = 0; j < n; j++) {
      if (a[j] != b[i + j]) {
        flag = false;
      }
    }
    if (flag) {
      for (long long j = 0; j < m; j++) {
        if (b[j] == '0' && (j <= i || j >= (i + n))) {
          flag = false;
        }
      }
    }
    if (flag) return true;
  }
  return false;
}
bool isSubstring(string &a, string &b) {
  string c = a;
  reverse(c.begin(), c.end());
  return (check(a, b) || check(c, b));
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "YES";
  } else if (y % 2 == 0) {
    cout << "NO";
  } else {
    string s1 = convert(x);
    string s2 = convert(y);
    string s3 = s1;
    while (s3.back() == '0') s3.pop_back();
    s1.push_back('1');
    if (isSubstring(s1, s2) || isSubstring(s3, s2)) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }
  return 0;
}
