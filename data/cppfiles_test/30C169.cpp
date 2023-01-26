#include <bits/stdc++.h>
using namespace std;
int calc(string s, char c) {
  int n = s.size();
  int p = 0, q = n - 1, cnt = 0;
  while (p < q) {
    if (s[p] == s[q]) {
      p++;
      q--;
      continue;
    }
    if (s[p] == c)
      p++;
    else if (s[q] == c)
      q--;
    else {
      return 1000000;
    }
    cnt++;
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int p = 0, q = n - 1;
    while (p < q && s[p] == s[q]) {
      p++;
      q--;
    }
    if (p >= q) {
      cout << "0\n";
      continue;
    }
    s = s.substr(p, (q - p) + 1);
    n = s.size();
    int a = calc(s, s[0]);
    int b = calc(s, s[n - 1]);
    a = min(a, b);
    if (a != 1000000)
      cout << a << '\n';
    else
      cout << "-1\n";
  }
}
