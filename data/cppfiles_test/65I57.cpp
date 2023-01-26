#include <bits/stdc++.h>
const int N = 2e5 + 10;
int64_t getCurrentTime() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
std::mt19937 Rand(getCurrentTime());
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
int64_t s = 0;
int a[N], b[N], c[N], d[N];
std::deque<int> que;
inline void solve(int l, int r, int op) {
  int len = r - l + 1;
  if (len & 1) {
    que.push_back(l * (op ? -1 : 1));
    for (int i = l + 1, j = i + len / 2, o = op ? -1 : 1; j <= r; i++, j++)
      que.push_back(j * -o), que.push_back(i * o);
  } else {
    for (int i = l + 2, o = op ? -1 : 1; i <= r; i++)
      que.push_back(i * o), o = -o;
    que.push_back(l * (op ? -1 : 1));
    int x = op ? 1 : -1;
    if (l % 2 == 0) x = -x;
    que.push_front((l + 1) * x);
  }
}
int main() {
  freopen("weight.in", "r", stdin);
  freopen("weight.out", "w", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  std::sort(a + 1, a + n + 1);
  for (int i = 1, j = 1, lst = 0; i <= n; ++i) {
    char ch = getchar();
    while (ch != 'L' && ch != 'R') ch = getchar();
    int x = ch == 'R';
    if (i != 1 && x != lst) solve(j, i - 1, lst), j = i;
    lst = x;
    if (i == n) solve(j, i, lst);
    d[i] = x;
  }
  int i = 0;
  while (!que.empty()) {
    ++i;
    int x = que.front();
    b[abs(x)] = a[i], c[abs(x)] = x < 0;
    que.pop_front();
  }
  for (int i = 1; i <= n; ++i) printf("%d %c\n", b[i], c[i] ? 'R' : 'L');
  for (int i = 1; i <= n; ++i) {
    s += b[i] * (c[i] ? -1 : 1);
    if (s * (d[i] ? -1 : 1) < 0) return puts("qwq"), 0;
  }
  return 0;
}
