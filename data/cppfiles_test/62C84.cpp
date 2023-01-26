#include <bits/stdc++.h>
#pragma GCC diagnostic warning "-Wshadow"
#pragma GCC diagnostic error "-Wreturn-type"
#pragma GCC diagnostic warning "-Wunused-value"
#pragma GCC diagnostic warning "-Wuninitialized"
#pragma GCC diagnostic warning "-Wmissing-braces"
#pragma GCC diagnostic warning "-Wsequence-point"
#pragma GCC diagnostic warning "-Wunused-function"
#pragma GCC diagnostic warning "-Wchar-subscripts"
#pragma GCC diagnostic warning "-Wunused-variable"
#pragma GCC diagnostic warning "-Wstrict-aliasing"
#pragma GCC diagnostic warning "-Wunused-parameter"
using namespace std;
inline int qread() {
  int tmp = 0;
  char buf = getchar();
  bool f = true;
  while (!isdigit(buf)) {
    if (buf == '-') f = false;
    buf = getchar();
  }
  while (isdigit(buf)) {
    tmp = tmp * 10 + buf - '0';
    buf = getchar();
  }
  return f ? tmp : -tmp;
}
void timer() {
  int t = clock();
  static int f_sta;
  static bool pt;
  if (pt) {
    printf("Delt.=%fs\n", (t - f_sta) * 1.00 / CLOCKS_PER_SEC);
  }
  f_sta = t;
  pt = true;
}
template <typename _Tp, size_t __Len, typename _Policy = plus<_Tp>>
struct BIT {
  _Tp __Sequence[__Len + 1];
  _Policy __Default = plus<_Tp>();
  BIT() { memset(__Sequence, 0, sizeof(__Sequence)); }
  BIT(_Policy __nDefault) : __Default(__nDefault) {
    memset(__Sequence, 0, sizeof(__Sequence));
  }
  static size_t _lowbit(int __t) { return size_t(__t & (-__t)); }
  void modify(size_t __pos, _Tp __val) {
    while (__pos <= __Len) {
      __Sequence[__pos] = __Default(__Sequence[__pos], __val);
      __pos += _lowbit(__pos);
    }
  }
  _Tp query(size_t __pos) {
    _Tp __tmp = 0;
    while (__pos > 0) {
      __tmp = __Default(__Sequence[__pos], __tmp);
      __pos -= _lowbit(__pos);
    }
    return __tmp;
  }
};
template <typename _Tp, size_t __Len>
struct exBIT {
  _Tp __SequenceA[__Len + 1], __SequenceB[__Len + 1];
  exBIT() {
    memset(__SequenceA, 0, sizeof(__SequenceA));
    memset(__SequenceB, 0, sizeof(__SequenceB));
  }
  static size_t _lowbit(int __t) { return size_t(__t & (-__t)); }
  void _modify(size_t __pos, _Tp __val) {
    _Tp __cpos = __pos;
    while (__pos <= __Len) {
      __SequenceA[__pos] = __SequenceA[__pos] + __val;
      __SequenceB[__pos] = __SequenceB[__pos] + __val * (__cpos - 1);
      __pos += _lowbit(__pos);
    }
  }
  void modify(size_t __l, size_t __r, _Tp __val) {
    _modify(__l, __val);
    _modify(__r + 1, -__val);
  }
  _Tp query(size_t __pos) {
    _Tp __tmp = 0, __cpos = __pos;
    while (__pos > 0) {
      __tmp = __cpos * __SequenceA[__pos] - __SequenceB[__pos] + __tmp;
      __pos -= _lowbit(__pos);
    }
    return __tmp;
  }
  _Tp query(size_t __l, size_t __r) { return query(__r) - query(__l - 1); }
};
template <size_t __Len>
struct dsu {
  int __Fa[__Len + 1];
  size_t __successful_merge_times;
  dsu() {
    for (size_t __t = 1; __t <= __Len; ++__t) {
      __Fa[__t] = -1;
    }
    __successful_merge_times = 0;
  }
  void clear() {
    for (size_t __t = 1; __t <= __Len; ++__t) {
      __Fa[__t] = -1;
    }
    __successful_merge_times = 0;
  }
  size_t findfa(size_t __pos) {
    while (__Fa[__pos] > 0 && __Fa[__Fa[__pos]] > 0) {
      __Fa[__pos] = __Fa[__Fa[__pos]];
      __pos = __Fa[__pos];
    }
    return __Fa[__pos] < 0 ? __pos : __Fa[__pos];
  }
  bool merge(size_t __a, size_t __b) {
    size_t __t_Fa = findfa(__a), __t_Fb = findfa(__b);
    if (__t_Fa != __t_Fb) {
      __successful_merge_times++;
      if (__Fa[__t_Fa] < __Fa[__t_Fb]) {
        __Fa[__t_Fa] += __Fa[__t_Fb];
        __Fa[__t_Fb] = __t_Fa;
      } else {
        __Fa[__t_Fb] += __Fa[__t_Fa];
        __Fa[__t_Fa] = __t_Fb;
      }
      return true;
    }
    return false;
  }
  bool same(size_t __a, size_t __b) { return findfa(__a) == findfa(__b); }
  size_t mergenum() { return __successful_merge_times; }
};
bool fs[1003][1003];
int a[10000], b[10000], mp[1004][1005];
int main() {
  int n = qread(), m = qread(), q = qread();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      fs[i][j] = 1;
    }
  }
  int ans = 0;
  int tmp = n + m - 1, top = 0;
  tmp -= 2 * std::min(n, m) - 2;
  for (int i = 1; i < std::min(n, m); i++) a[++top] = i;
  for (int i = 1; i <= tmp; i++) a[++top] = std::min(n, m);
  for (int i = std::min(n, m) - 1; i >= 1; i--) a[++top] = i;
  for (int i = 1; i <= top; i++) {
    ans += a[i] * (a[i] + 1) - a[i];
    ans += a[i] * a[i - 1];
  }
  for (int i = 1; i <= q; i++) {
    int x = qread();
    int y = qread();
    int tl = 1, lt = 1;
    int nx = x, ny = y;
    bool up = true;
    while (nx >= 1 && ny >= 1) {
      if (up) {
        ny--;
      } else {
        nx--;
      }
      up = !up;
      if (fs[nx][ny])
        tl++;
      else
        break;
    }
    nx = x, ny = y;
    up = false;
    while (nx <= n && ny <= m) {
      if (up) {
        ny++;
      } else {
        nx++;
      }
      up = !up;
      if (fs[nx][ny])
        lt++;
      else
        break;
    }
    int tr = 1, rt = 1;
    nx = x, ny = y;
    up = false;
    while (nx >= 1 && ny >= 1) {
      if (up) {
        ny--;
      } else {
        nx--;
      }
      up = !up;
      if (fs[nx][ny])
        tr++;
      else
        break;
    }
    nx = x, ny = y;
    up = true;
    while (nx <= n && ny <= m) {
      if (up) {
        ny++;
      } else {
        nx++;
      }
      up = !up;
      if (fs[nx][ny])
        rt++;
      else
        break;
    }
    if (fs[x][y]) {
      cout << ans - (lt * tl + rt * tr) + 1 << endl;
      ans = ans - (lt * tl + rt * tr) + 1;
    } else {
      cout << ans + (lt * tl + rt * tr) - 1 << endl;
      ans = ans + (lt * tl + rt * tr) - 1;
    }
    fs[x][y] = !fs[x][y];
  }
}
