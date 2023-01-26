#include <bits/stdc++.h>
using namespace std;
int n, m;
void solve() {
  int a = 0, b = 0, c = 0;
  string s;
  cin >> s;
  int len = s.length();
  for (int i = 0; i < len; i++) {
    if (s[i] == 'A')
      a++;
    else if (s[i] == 'B')
      b++;
    else
      c++;
  }
  if (a + c == b)
    puts("YES");
  else
    puts("NO");
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
