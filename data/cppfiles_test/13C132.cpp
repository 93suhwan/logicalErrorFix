#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int a, b, c;
  a = b = c = 0;
  for (int i = 0; i < (int)s.length(); i++) {
    if (s[i] == 'A') a++;
    if (s[i] == 'B') b++;
    if (s[i] == 'C') c++;
  }
  if (a + c != b)
    puts("NO");
  else
    puts("YES");
}
int main() {
  int K;
  scanf("%d", &K);
  while (K--) {
    solve();
  }
}
