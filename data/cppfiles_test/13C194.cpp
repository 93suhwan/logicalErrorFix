#include <bits/stdc++.h>
using namespace std;
int solve() {
  string s;
  cin >> s;
  int len = s.size();
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == 'A')
      a++;
    else if (s[i] == 'B')
      b++;
    else
      c++;
  }
  if (a + c == b)
    return 1;
  else
    return 0;
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    if (solve())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
