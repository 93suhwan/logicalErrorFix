#include <bits/stdc++.h>
using namespace std;
int func(string s, int i, int g1, int g2) {
  if (i == 10) return 10;
  if (i % 2 == 0) {
    if (g1 > g2 + (10 - i) / 2 || g2 > g1 + (10 - i) / 2) return i;
  }
  if (i % 2 == 1)
    if (g1 > g2 + 1 + (10 - i) / 2 || g2 > g1 + (10 - i) / 2) return i;
  if (i % 2 == 0) {
    if (s[i] == '1')
      return func(s, i + 1, g1 + 1, g2);
    else if (s[i] == '0')
      return func(s, i + 1, g1, g2);
    else
      return min(func(s, i + 1, g1 + 1, g2), func(s, i + 1, g1, g2));
  }
  if (s[i] == '1')
    return func(s, i + 1, g1, g2 + 1);
  else if (s[i] == '0')
    return func(s, i + 1, g1, g2);
  return min(func(s, i + 1, g1, g2 + 1), func(s, i + 1, g1, g2));
}
int main() {
  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    cout << func(s, 0, 0, 0) << "\n";
  }
  return 0;
}
