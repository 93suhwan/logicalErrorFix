#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n;
int ans[MAXN];
long long Read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x * 10) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
template <typename T>
void Put1(T x) {
  if (x > 9) Put1(x / 10);
  putchar(x % 10 ^ 48);
}
template <typename T>
void Put(T x, char c = -1) {
  if (x < 0) putchar('-'), x = -x;
  Put1(x);
  if (c >= 0) putchar(c);
}
template <typename T>
T Max(T x, T y) {
  return x > y ? x : y;
}
template <typename T>
T Min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T Abs(T x) {
  return x < 0 ? -x : x;
}
int main() {
  n = Read();
  int hou = n;
  for (int i = 1; i < n; ++i) {
    printf("? ");
    for (int j = 1; j < n; ++j) Put(i, ' ');
    Put(n, '\n');
    fflush(stdout);
    if (Read()) {
      hou = i;
      break;
    }
  }
  ans[n] = hou;
  for (int i = 1; i <= n; ++i) {
    if (i == hou) continue;
    printf("? ");
    for (int j = 1; j < n; ++j) Put(hou, ' ');
    Put(i, '\n');
    fflush(stdout);
    ans[Read()] = i;
  }
  printf("! ");
  for (int i = 1; i <= n; ++i) Put(ans[i], ' ');
  fflush(stdout);
  return 0;
}
