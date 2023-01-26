#include <bits/stdc++.h>
using std::vector;
struct number {
  int sign, power, type;
  number(int sign = 0, int power = 0, int type = 0)
      : sign(sign), power(power), type(type) {}
  bool operator<(const number &rhs) const {
    return sign == rhs.sign ? power > rhs.power : sign < rhs.sign;
  }
};
int n, s;
long long base_10[20];
std::priority_queue<number> q;
inline void solve() {
  scanf("%d%d", &s, &n);
  int m = 0, cnt = 0;
  while (s) {
    if (s % 10) {
      q.push(number(s % 10, m, 0));
      ++cnt;
    }
    ++m;
    s /= 10;
  }
  number cur;
  long long remain = 0;
  int one = 0;
  for (int i = 1; i < n; ++i) {
    cur = q.top();
    int x = cur.sign, y = cur.power, z = cur.type;
    if (x == 1) {
      if (y == 0) {
        if (z == 1)
          --i;
        else {
          --cnt;
          if (cnt == 0) --i;
        }
        ++one;
        q.pop();
        continue;
      }
      q.pop();
      q.push(number(1, y - 1, 1));
      q.push(number(9, y - 1, z));
      continue;
    }
    q.pop();
    q.push(number(x - 1, y, z));
    q.push(number(1, y, 1));
  }
  while (!q.empty()) {
    cur = q.top();
    q.pop();
    if (cur.type == 1)
      printf("%lld ", cur.sign * base_10[cur.power]);
    else
      remain += cur.sign * base_10[cur.power];
  }
  for (int i = 0; i < one; ++i) printf("1 ");
  if (remain) printf("%lld ", remain);
  puts("");
}
int main() {
  int t;
  scanf("%d", &t);
  base_10[0] = 1;
  for (int i = 1; i <= 10; ++i) base_10[i] = base_10[i - 1] * 10;
  while (t--) solve();
  return 0;
}
