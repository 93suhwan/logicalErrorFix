#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  long long ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<long long> x) {
  for (long long i = 0; i < (long long)x.size(); i++)
    printf("%lld%c", x[i], " \n"[i == (long long)x.size() - 1]);
}
void work() {
  long long n = read(), a = read(), b = read();
  char s[10];
  scanf("%s", s);
  long long da = s[0] == 'l';
  scanf("%s", s);
  long long db = s[0] == 'l';
  if (a == 0) da = 1;
  if (a == n - 1) da = 0;
  if (b == 0) db = 1;
  if (b == n - 1) db = 0;
  if (a == b) {
    if (a == 0) return (void)printf("%lld\n", n - 1);
    if (a == n - 1) return (void)printf("%lld\n", 0LL);
    if (da == db) {
      if (da == 0)
        return (void)printf("%lld\n", 0LL);
      else
        return (void)printf("%lld\n", n - 1);
    } else {
      if (da == 1)
        return (void)printf("%lld\n", 0LL);
      else
        return (void)printf("%lld\n", n - 1);
    }
  }
  if (a < b)
    printf("%lld\n", ((a + b) & 1) ? 0 : n - 1);
  else
    printf("%lld\n", ((a + b) & 1) ? n - 1 : 0);
}
signed main() {
  long long T = read();
  while (T--) work();
  return 0;
}
