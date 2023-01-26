#include <bits/stdc++.h>
long long one = 1;
int t;
int n, k;
long long x;
std::string s;
long long w = 1;
int ansl;
char ans[4000006];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%lld", &n, &k, &x);
    std::cin >> s;
    x--;
    s += 'a';
    s += ' ';
    int l = s.length(), cnt = 0;
    ansl = 0;
    for (int i = l - 1; i >= 1; i--) s[i] = s[i - 1];
    s[0] = 'a';
    for (int i = l - 1; i >= 0; i--) {
      if (!x) {
        for (int j = i; j >= 0; j--)
          if (s[j] == 'a') ans[++ansl] = 'a';
        break;
      }
      if (s[i] == 'a') {
        if (!cnt)
          ans[++ansl] = 'a';
        else {
          w = one * cnt * k + 1;
          long long num = x % w;
          x /= w;
          for (long long j = 1; j <= num; j++) ans[++ansl] = 'b';
          ans[++ansl] = 'a';
          cnt = 0;
        }
      } else
        cnt++;
    }
    for (int i = ansl - 1; i >= 2; i--) printf("%c", ans[i]);
    printf("\n");
  }
  return 0;
}
