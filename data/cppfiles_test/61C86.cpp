#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char s[N];
void solve() {
  int n;
  scanf("%d%s", &n, s + 1);
  for (long long int i = 1; i <= n; i++) {
    if (s[i] == '?' && (s[i - 1] == 'R' || s[i - 1] == 'B')) {
      if (s[i - 1] == 'R')
        s[i] = 'B';
      else
        s[i] = 'R';
    }
  }
  for (long long int i = n; i; i--) {
    if (s[i] == '?') {
      if (s[i + 1] == 'R')
        s[i] = 'B';
      else
        s[i] = 'R';
    }
  }
  printf("%s\n", s + 1);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
