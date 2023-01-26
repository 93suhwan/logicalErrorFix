#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
string decimaltobinary(long long n) {
  string s;
  while (n) {
    s.push_back((n & 1) + '0');
    n >>= 1;
  }
  reverse(s.begin(), s.end());
  return s;
}
void solve(long long x, long long y) {
  if (x == y) {
    cout << "YES";
    return;
  }
  if (y % 2 == 0) {
    cout << "NO";
    return;
  }
  string s1 = decimaltobinary(x);
  string s2 = decimaltobinary(y);
  while (s1.back() == '0') s1.pop_back();
  string s3 = s1;
  reverse(s3.begin(), s3.end());
  if (s2.find(s1) != string::npos || s2.find(s3) != string::npos) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long x, y;
  cin >> x >> y;
  solve(x, y);
  return 0;
}
