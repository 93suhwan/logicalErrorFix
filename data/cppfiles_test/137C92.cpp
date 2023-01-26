#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long power(long long a, long long b, long long modi) {
  a %= modi;
  long long res = 1;
  while (b) {
    if (b % 2) {
      res = (res * a) % modi;
    }
    b /= 2;
    a = (a * a) % modi;
  }
  return res;
}
long long x, y;
string convert(long long n) {
  string ans = "";
  while (n) {
    if (n % (long long)2)
      ans += '1';
    else
      ans += '0';
    n /= (long long)2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
bool check(string s1, string s2) {
  long long l1 = s1.length();
  long long l2 = s2.length();
  for (long long i = 0; i <= (l2 - l1); i++) {
    if (s2[i] == '0') return false;
    long long p1 = 0, p2 = i;
    bool flag = true;
    while (p1 < l1) {
      if (s1[p1] != s2[p2]) {
        flag = false;
        break;
      }
      p1++;
      p2++;
    }
    if (p2 == l2 && i && s2[p2 - 1] == '0') continue;
    if (flag) {
      while (p2 < l2) {
        if (s2[p2] == '0') flag = false;
        p2++;
      }
      if (flag) return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    cin >> x >> y;
    if (x == y) {
      cout << "YES" << '\n';
      return 0;
    }
    string s1 = convert(x);
    string s2 = convert(y);
    string s3 = s1;
    reverse(s3.begin(), s3.end());
    string s5 = '1' + s3;
    for (long long i = 0; i < (long long)s3.length(); i++) {
      if (s3[i] == '1') {
        s3 = s3.substr(i);
        break;
      }
    }
    string s4 = s3;
    reverse(s4.begin(), s4.end());
    if (check(s1, s2) || check(s3, s2) || check(s4, s2) || check(s5, s2))
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
