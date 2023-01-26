#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;
inline long long read() {
  long long ans = 0;
  char ch = getchar(), las = ' ';
  while (!isdigit(ch)) las = ch, ch = getchar();
  while (isdigit(ch)) ans = (ans << 1) + (ans << 3) + ch - '0', ch = getchar();
  if (las == '-') ans = -ans;
  return ans;
}
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void MYFILE() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
int n;
long long a[maxn], sum[maxn];
inline long long S(int L, int R) { return sum[R] - sum[L - 1]; }
struct Node {
  int pos;
  long long val;
  inline bool operator<(const Node& oth) const { return pos < oth.pos; }
};
vector<Node> st[maxn];
int cnt[maxn];
inline void in(int pos, int len, long long val) {
  int& top = cnt[len];
  if (top && st[len][top].val <= val) return;
  if (++top == (int)st[len].size()) st[len].push_back((Node){0, 0});
  st[len][top] = (Node){pos, val};
}
inline bool check(int len) {
  for (int i = 1; i <= n; ++i)
    st[i].clear(), st[i].push_back((Node){0, 0}), cnt[i] = 0;
  for (int i = len; i <= n; ++i) {
    in(i, len, S(i - len + 1, i));
    int tot = len;
    for (int j = len - 1; j; --j) {
      if (j + tot > i) break;
      long long tp = S(i - j + 1, i);
      int pos =
          upper_bound(st[j + 1].begin(), st[j + 1].end(), (Node){i - j, 0}) -
          st[j + 1].begin() - 1;
      if (pos > 0 && pos <= cnt[j + 1] && st[j + 1][pos].val < tp) {
        in(i, j, tp);
      }
      tot += j;
    }
  }
  return cnt[1] > 0;
}
int main() {
  int T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= n; ++i) {
      a[i] = read();
      sum[i] = sum[i - 1] + a[i];
    }
    int L = 1, R = 1;
    while (R * (R + 1) / 2 <= n) R++;
    R--;
    while (L < R) {
      int mid = (L + R + 1) >> 1;
      if (check(mid))
        L = mid;
      else
        R = mid - 1;
    }
    write(L), puts("");
  }
  return 0;
}
