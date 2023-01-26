#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 10;
deque<int> a[2];
int w[Maxn];
int n;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
int work() {
  for (int i = 0; i < 2; ++i)
    if (!a[i].size()) return (a[i ^ 1].size() & 1) ^ 1;
  if (a[0][0] == a[1][0]) return ((a[0].size() & 1) | (a[1].size() & 1)) ^ 1;
  int p = 0;
  if (a[1][0] > a[0][0]) p = 1;
  if (a[p].size() & 1) return 0;
  int cnt = 0;
  while (a[p ^ 1].size() && a[p ^ 1][0] < a[p][0]) a[p ^ 1].pop_front(), ++cnt;
  return work() ^ (cnt & 1);
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) w[i] = read();
  for (int i = 1; i <= n; ++i) {
    a[0].push_back(w[i]);
    if (w[i] >= w[i + 1]) break;
  }
  for (int i = n; i; --i) {
    a[1].push_back(w[i]);
    if (w[i] >= w[i - 1]) break;
  }
  if (!work())
    puts("Alice");
  else
    puts("Bob");
  return 0;
}
