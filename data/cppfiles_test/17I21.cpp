#include <bits/stdc++.h>
using namespace std;
using std::cin;
using std::cout;
using vii = std::vector<int>;
using pii = std::pair<int, int>;
namespace IO {
char buf[(1 << 21)], *p1 = buf, *p2 = buf, buf1[(1 << 21)];
int _ = 0;
inline char gc() {
  return p1 == p2 &&
                 (p2 = (p1 = buf) + fread(buf, 1, (1 << 21), stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <class I>
inline I read(I &x) {
  x = 0;
  I f = 1;
  char c = getchar();
  if (c == EOF) {
    return -1;
  }
  while (c < '0' || c > '9') {
    if (c == '-') {
      f = f * (-1);
    }
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x = x * f;
}
template <class I>
inline void write(I x) {
  if (x == 0) {
    putchar('0');
    return;
  }
  int tmp = x > 0 ? x : (-x), cnt = 0;
  if (x < 0) {
    putchar('-');
  }
  while (tmp) {
    buf[cnt++] = (tmp % 10) + '0';
    tmp /= 10;
  }
  while (cnt) {
    putchar(buf[--cnt]);
  }
  return;
}
void _FILE() {}
}  // namespace IO
using namespace IO;
int T, n;
long long a[1000010];
class TA {
 private:
  long long tree[1000010];

 public:
  void clear() { memset(tree, 0, sizeof tree); }
  void add(int x, long long val) {
    for (; x <= n; x += ((x) & (-x))) {
      tree[x] += val;
    }
    return;
  }
  long long query(int x) {
    long long res = 0;
    for (; x > 0; x -= ((x) & (-x))) {
      res += tree[x];
    }
    return res;
  }
} ta;
long long cnt[1000010];
int b[1000010];
signed main() {
  _FILE();
  read(T);
  while (T--) {
    long long ans = 0;
    memset(cnt, 0, sizeof cnt);
    ta.clear();
    read(n);
    for (int i(1); i <= (n); ++i) {
      read(a[i]);
      b[i] = a[i];
    }
    ::sort(b + 1, b + n + 1);
    int size_b = ::unique(b + 1, b + n + 1) - (b + 1);
    for (int i(1); i <= (n); ++i) {
      a[i] = ::lower_bound(b + 1, b + size_b + 1, a[i]) - (b);
    }
    for (int i(1); i <= (n); ++i) {
      int val = a[i];
      if (i == 1) {
        ta.add(val, 1);
        ++cnt[val];
        continue;
      } else {
        long long res = ta.query(val - 1);
        ++cnt[val];
        if (res <= i - res - cnt[val]) {
          ans += res;
        } else {
          ans += i - res - cnt[val];
        }
        ta.add(val, 1);
      }
    }
    write(ans), putchar('\n');
  }
  return 0;
}
