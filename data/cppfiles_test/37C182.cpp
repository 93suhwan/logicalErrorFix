#include <bits/stdc++.h>
using namespace std;
int getint() {
  char ch;
  int res = 0, p;
  while (!isdigit(ch = getchar()) && ch != '-')
    ;
  p = ch == '-' ? ch = getchar(), -1 : 1;
  while (isdigit(ch)) res = res * 10 + ch - '0', ch = getchar();
  return res * p;
}
const int maxn = 1e5 + 5;
int n, m;
int cnt[maxn];
void work() {
  n = getint();
  m = getint();
  for (int i = (1); i <= (n); ++i) cnt[i] = 0;
  for (int i = (1); i <= (m); ++i) {
    int a, b, c;
    a = getint();
    b = getint();
    c = getint();
    cnt[b]++;
  }
  int rt = 0;
  for (int i = (1); i <= (n); ++i)
    if (!cnt[i]) rt = i;
  for (int i = (1); i <= (n); ++i)
    if (i != rt) printf("%d %d\n", rt, i);
}
int main() {
  int T;
  T = getint();
  while (T--) work();
  return 0;
}
