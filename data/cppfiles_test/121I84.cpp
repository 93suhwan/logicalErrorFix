#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long inf = 0x3f3f3f3f;
long long gcd(long long a, long long b) {
  long long d;
  while (b) {
    d = b;
    b = a % b;
    a = d;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
string bin(long long x) {
  if (x == 0)
    return "";
  else {
    string s = bin(x / 2);
    s.push_back(char('0' + x % 2));
    return s;
  }
}
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int od = 0, ev = 0;
  int len = s1.length();
  int ze = 0;
  int s1on = 0;
  for (int i = 0; i < len; i++) {
    if (s1[i] == '1') s1on++;
    if (s1[i] == s2[i]) {
      ev++;
      if (s1[i] == '0') ze++;
    } else if (s1[i] != s2[i])
      od++;
  }
  if (od != 0 && s1on == 0) {
    cout << -1 << '\n';
    ;
    return;
  }
  if (od == 0) {
    cout << 0 << '\n';
    ;
    return;
  } else if (od % 2 == 0) {
    int num = od / 2;
    if (num % 2 == 1) {
      cout << od / 2 << '\n';
      ;
    } else
      cout << od << '\n';
    ;
  } else if (od % 2 == 1) {
    if (s1on == 1 && od == n - 1) {
      cout << 1 << '\n';
      ;
      return;
    }
    cout << -1 << '\n';
    ;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
