#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    char s[n];
    scanf("%s", s + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += (s[i] != '?');
    if (!cnt) s[1] = 'R';
    for (int i = 2; i <= n; i++)
      if (s[i] == '?' && s[i - 1] != '?') s[i] = s[i - 1] ^ ('B' ^ 'R');
    for (int i = n - 1; i; i--)
      if (s[i] == '?' && s[i + 1] != '?') s[i] = s[i + 1] ^ ('B' ^ 'R');
    printf("%s\n", s + 1);
  }
}
