#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
using namespace std;
template <class T>
struct cLtraits_identity {
  using type = T;
};
template <class T>
using cLtraits_try_make_signed =
    typename conditional<is_integral<T>::value, make_signed<T>,
                         cLtraits_identity<T> >::type;
template <class S, class T>
struct cLtraits_common_type {
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS, tT>::type;
};
template <class S, class T>
inline auto max_L(S a, T b) -> typename cLtraits_common_type<S, T>::type {
  return (typename cLtraits_common_type<S, T>::type)a >=
                 (typename cLtraits_common_type<S, T>::type)b
             ? a
             : b;
}
inline int my_getchar() {
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if (s == e && e == 1048576) {
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if (s == e) {
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x) {
  int k;
  int m = 0;
  x = 0;
  for (;;) {
    k = my_getchar();
    if (k == '-') {
      m = 1;
      break;
    }
    if ('0' <= k && k <= '9') {
      x = k - '0';
      break;
    }
  }
  for (;;) {
    k = my_getchar();
    if (k < '0' || k > '9') {
      break;
    }
    x = x * 10 + k - '0';
  }
  if (m) {
    x = -x;
  }
}
struct MY_WRITER {
  char buf[1048576];
  int s;
  int e;
  MY_WRITER() {
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER() {
    if (s) {
      fwrite(buf, 1, s, stdout);
    }
  }
};
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a) {
  if (MY_WRITER_VAR.s == MY_WRITER_VAR.e) {
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a) { my_putchar(a); }
inline void wt_L(int x) {
  int s = 0;
  int m = 0;
  char f[10];
  if (x < 0) {
    m = 1;
    x = -x;
  }
  while (x) {
    f[s++] = x % 10;
    x /= 10;
  }
  if (!s) {
    f[s++] = 0;
  }
  if (m) {
    my_putchar('-');
  }
  while (s--) {
    my_putchar(f[s] + '0');
  }
}
template <class T, class S, class U>
inline void DigitF_L(T n, int sz, S res[], U b) {
  int i;
  for (i = (0); i < (sz); i++) {
    res[i] = n % b;
    n /= b;
  }
}
int main() {
  int i;
  int N;
  rd(N);
  int K;
  rd(K);
  int m[N][N];
  int d[11][N];
  int ress = 0;
  int res[1000000];
  int mx = 0;
  for (i = (0); i < (N); i++) {
    DigitF_L(i, 11, d[i], K);
  }
  for (i = (0); i < (N); i++) {
    int j;
    for (j = (i + 1); j < (N); j++) {
      int k;
      for (k = (11) - 1; k >= (0); k--) {
        if (d[i][k] != d[j][k]) {
          res[ress++] = k;
          break;
        }
      }
    }
  }
  int WYIGIcGE;
  cLtraits_try_make_signed<
      remove_reference<decltype((*((int *)NULL)))>::type>::type t_ynMSdg;
  if (ress == 0) {
    t_ynMSdg = 0;
  } else {
    t_ynMSdg = res[0];
    for (WYIGIcGE = (1); WYIGIcGE < (ress); WYIGIcGE++) {
      t_ynMSdg = max_L(t_ynMSdg, res[WYIGIcGE]);
    }
  }
  mx = t_ynMSdg;
  wt_L(mx + 1);
  wt_L('\n');
  {
    int tU__gIr_;
    if (ress == 0) {
      wt_L('\n');
    } else {
      for (tU__gIr_ = (0); tU__gIr_ < (ress - 1); tU__gIr_++) {
        wt_L(res[tU__gIr_] + 1);
        wt_L(' ');
      }
      wt_L(res[tU__gIr_] + 1);
      wt_L('\n');
    }
  }
  return 0;
}
