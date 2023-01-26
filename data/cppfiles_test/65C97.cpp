#include <bits/stdc++.h>
using namespace std;
int n;
int a[200009];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  sort(a + 1, a + n + 1);
  int x = 0;
  for (int i = 1; i < n; i++) {
    if (s[i - 1] != s[i]) {
      x++;
    }
  }
  int point = n - x;
  cout << a[point] << ' ' << s[0] << endl;
  int l, r;
  int ll, rr;
  l = r = (s[0] == 'L');
  ll = rr = point;
  for (int i = 1; i <= n - 1; i++) {
    if (s[i] == s[i - 1]) {
      ll--;
      l = l ^ 1;
      char tmp = (l == 1) ? 'L' : 'R';
      cout << a[ll] << ' ' << tmp << endl;
    }
    if (s[i] != s[i - 1]) {
      rr++;
      r = r ^ 1;
      char tmp = (r == 1) ? 'L' : 'R';
      cout << a[rr] << ' ' << tmp << endl;
    }
  }
  return 0;
}
