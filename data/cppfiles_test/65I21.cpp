#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  x *= f;
}
int n;
int a[N];
char s[N];
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  scanf("%s", s + 1);
  int x = 0;
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n; i++)
    if (s[i] != s[i - 1]) x++;
  int l = n - x - 1, r = n - x + 1;
  printf("%d %c\n", a[n - x], s[1]);
  long long sum = a[n - x];
  for (int i = 2; i <= n; i++)
    if (s[i] != s[i - 1])
      printf("%d %c\n", a[r], s[i]), sum += a[r++] * (s[i] == s[1] ? 1 : -1);
    else if (sum > a[l])
      printf("%d %c\n", a[l], s[1] == 'L' ? 'R' : 'L'), sum -= a[l--];
    else
      printf("%d %c\n", a[l], s[1] == 'L' ? 'L' : 'R'), sum += a[l--];
  return 0;
}
