#include <bits/stdc++.h>
using namespace std;
void solve(int t) {
  string s;
  cin >> s;
  int a, b, c;
  a = b = c = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A')
      a++;
    else if (s[i] == 'B')
      b++;
    else
      c++;
  }
  if (b == a + c)
    printf("YES\n");
  else
    printf("NO\n");
  return;
}
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
