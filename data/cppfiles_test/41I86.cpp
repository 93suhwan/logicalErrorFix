#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
void read(T &x) {
  char ch;
  x = 0;
  int f = 1;
  while (isspace(ch = getchar_unlocked()))
    ;
  if (ch == '-') ch = getchar_unlocked(), f = -1;
  do x = x * 10 + (ch - '0');
  while (isdigit(ch = getchar_unlocked()));
  x *= f;
}
template <class T, class... A>
void read(T &x, A &...args) {
  read(x);
  read(args...);
}
const int N = 1005;
int id[N];
int main() {
  int n, k;
  read(n, k);
  printf("%d\n", (n + k - 1) / k);
  int cnt = 0;
  id[0] = 1;
  for (int i = 1; i <= n; ++i) {
    ++cnt;
    if (cnt == k + 1) {
      id[i] = id[i - 1] + 1;
      cnt = 1;
    } else
      id[i] = id[i - 1];
    printf("id[%d] = %d\n", i, id[i]);
  }
  int c = (n + k - 1) / k;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) printf("%d ", (i - j + c * n) % c);
  puts("");
  return 0;
}
