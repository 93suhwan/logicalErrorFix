#include <bits/stdc++.h>
template <typename T>
void read(T &);
template <typename T>
void write(const T &);
const int N = 500005;
std::tuple<int, int, bool> v[N];
int dp[N];
int h[N];
int m;
int n, d;
int main() {
  read(n), read(d);
  for (int i = 1; i <= n; ++i) {
    int s, a;
    read(s), read(a);
    if (s < d) continue;
    if (s >= a) {
      v[++m] = {s, a, 1};
    } else {
      v[++m] = {a, s, 0};
    }
  }
  std::sort(v + 1, v + m + 1);
  int maxi = 0;
  int cnt = 0;
  for (int i = 1; i <= m; ++i) {
    dp[i] = dp[i - 1];
    int x = std::get<1>(v[i]);
    maxi = std::max(maxi, x);
    if (std::get<2>(v[i])) {
      ++cnt;
    } else if (x >= maxi) {
      int u = std::upper_bound(v + 1, v + m + 1, std::make_tuple(x, 1e9, 1)) -
              v - 1;
      dp[i] = std::max(dp[i], dp[u] + 1);
    }
  }
  write(dp[m] + cnt), putchar('\n');
  return 0;
}
template <typename T>
void read(T &Re) {
  T k = 0;
  char ch = getchar();
  int flag = 1;
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) k = k * 10 + ch - '0', ch = getchar();
  Re = flag * k;
}
template <typename T>
void write(const T &Wr) {
  if (Wr < 0)
    putchar('-'), write(-Wr);
  else if (Wr < 10)
    putchar(Wr + '0');
  else
    write(Wr / 10), putchar((Wr % 10) + '0');
}
