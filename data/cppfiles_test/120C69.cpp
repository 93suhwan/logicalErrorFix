#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;
const int mo = 1e9 + 7;
using namespace std;
std::vector<std::vector<int>> sum(N, std::vector<int>(22, 0));
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x *= f;
}
template <typename T>
void write(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void writeln(T x) {
  write(x);
  puts("");
}
void Pre() {
  for (int i = 1; i <= N - 5; i++)
    for (int j = 0; j <= 20; j++) sum[i][j] = sum[i - 1][j] + ((i >> j) & 1);
}
int main() {
  int T, l, r;
  read(T);
  Pre();
  while (T--) {
    read(l), read(r);
    int ans = 0;
    l--;
    for (int i = 0; i <= 20; i++) ans = max(ans, sum[r][i] - sum[l][i]);
    writeln(r - l - ans);
  }
}
