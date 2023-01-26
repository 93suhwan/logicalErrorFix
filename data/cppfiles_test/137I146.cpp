#include <bits/stdc++.h>
using namespace std;
int allone(string s, int i, int j) {
  for (int l = i; l <= j; l++)
    if (s[l] != '1') return 0;
  return 1;
}
int cmp(string s, string str) {
  int n1 = s.size(), n2 = str.size();
  for (int i = 0; i < n1 - n2 + 1; i++) {
    int key = 1;
    for (int j = 0; j < n2; j++) {
      if (s[i + j] != str[j]) key = 0;
    }
    if (key) {
      if (allone(s, 0, i - 1) && allone(s, i + n2, n1 - 1)) return 1;
    }
  }
  return 0;
}
string toString(long long n) {
  string s = "";
  while (n) {
    if (n % 2 == 0)
      s += '0';
    else
      s += '1';
    n /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  long long x, y;
  string s1, s2, s, s3, s4;
  cin >> x >> y;
  long long x2, x1 = x;
  x1 = (long long)(x1 << 1) + 1;
  while (x % 2 == 0) x /= 2;
  x2 = x;
  if (x1 > 1e18) x1 = 0;
  s1 = toString(x1);
  s2 = toString(x2);
  s3 = s1;
  s4 = s2;
  reverse(s3.begin(), s3.end());
  reverse(s4.begin(), s4.end());
  s = toString(y);
  if (cmp(s, s1) || cmp(s, s2) || cmp(s, s3) || cmp(s, s4))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
