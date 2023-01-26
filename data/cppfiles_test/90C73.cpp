#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
void *wmem;
char memarr[96000000];
template <class S, class T>
inline auto min_L(S a, T b) -> typename cLtraits_common_type<S, T>::type {
  return (typename cLtraits_common_type<S, T>::type)a <=
                 (typename cLtraits_common_type<S, T>::type)b
             ? a
             : b;
}
template <class T>
inline void walloc1d(T **arr, int x, void **mem = &wmem) {
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void *)(((char *)(*mem)) + skip[((unsigned long long)(*mem)) & 15]);
  (*arr) = (T *)(*mem);
  (*mem) = ((*arr) + x);
}
template <class T>
inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem) {
  walloc1d(arr, x2 - x1, mem);
  (*arr) -= x1;
}
template <class T1>
void sortA_L(int N, T1 a[], void *mem = wmem) {
  sort(a, a + N);
}
template <class T1, class T2>
void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem) {
  int i;
  pair<T1, T2> *arr;
  walloc1d(&arr, N, &mem);
  for (i = (0); i < (N); i++) {
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr + N);
  for (i = (0); i < (N); i++) {
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
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
inline void rd(long long &x) {
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
inline int rd_int(void) {
  int x;
  rd(x);
  return x;
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
inline void wt_L(long long x) {
  int s = 0;
  int m = 0;
  char f[20];
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
template <class S>
inline void arrInsert(const int k, int &sz, S a[], const S aval) {
  int i;
  sz++;
  for (i = sz - 1; i > k; i--) {
    a[i] = a[i - 1];
  }
  a[k] = aval;
}
template <class S, class T>
inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[],
                      const T bval) {
  int i;
  sz++;
  for (i = sz - 1; i > k; i--) {
    a[i] = a[i - 1];
  }
  for (i = sz - 1; i > k; i--) {
    b[i] = b[i - 1];
  }
  a[k] = aval;
  b[k] = bval;
}
template <class S, class T, class U>
inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[],
                      const T bval, U c[], const U cval) {
  int i;
  sz++;
  for (i = sz - 1; i > k; i--) {
    a[i] = a[i - 1];
  }
  for (i = sz - 1; i > k; i--) {
    b[i] = b[i - 1];
  }
  for (i = sz - 1; i > k; i--) {
    c[i] = c[i - 1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template <class S, class T, class U, class V>
inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[],
                      const T bval, U c[], const U cval, V d[], const V dval) {
  int i;
  sz++;
  for (i = sz - 1; i > k; i--) {
    a[i] = a[i - 1];
  }
  for (i = sz - 1; i > k; i--) {
    b[i] = b[i - 1];
  }
  for (i = sz - 1; i > k; i--) {
    c[i] = c[i - 1];
  }
  for (i = sz - 1; i > k; i--) {
    d[i] = d[i - 1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
template <class S, class T>
inline S chmin(S &a, T b) {
  if (a > b) {
    a = b;
  }
  return a;
}
template <class S, class T>
inline S chmax(S &a, T b) {
  if (a < b) {
    a = b;
  }
  return a;
}
int n;
int m;
int nsz;
long long a[200000 + 10];
long long l[200000 + 10];
long long r[200000 + 10];
long long nl[200000 + 10];
long long nr[200000 + 10];
long long idx[200000 + 10];
long long dp[2];
long long ndp[2];
int main() {
  int PiIOrLma;
  wmem = memarr;
  int AuJVIghY = rd_int();
  for (PiIOrLma = (0); PiIOrLma < (AuJVIghY); PiIOrLma++) {
    int i;
    rd(n);
    rd(m);
    {
      int djQeACzd;
      for (djQeACzd = (0); djQeACzd < (n); djQeACzd++) {
        rd(a[djQeACzd]);
      }
    }
    {
      int NN9wFlop;
      for (NN9wFlop = (0); NN9wFlop < (m); NN9wFlop++) {
        rd(l[NN9wFlop]);
        rd(r[NN9wFlop]);
      }
    }
    sortA_L(n, a);
    a[n] = 4611686016279904256LL;
    ++n;
    nsz = 0;
    for (i = (0); i < (m); i++) {
      int u = lower_bound(a, a + n, l[i]) - a;
      if (l[i] <= a[u] && a[u] <= r[i]) {
        continue;
      }
      arrInsert(nsz, nsz, nl, l[i], nr, r[i]);
    }
    for (i = (0); i < (nsz); i++) {
      auto OUHHcm5g = ((nl[i]));
      auto o8AZ1iEn = ((-nr[i]));
      l[i] = OUHHcm5g;
      r[i] = o8AZ1iEn;
    }
    m = nsz;
    nsz = 0;
    sortA_L(m, l, r);
    for (i = (0); i < (m); i++) {
      r[i] = -r[i];
    }
    for (i = (0); i < (m); i++) {
      while (nsz > 0 && nl[nsz - 1] <= l[i] && r[i] <= nr[nsz - 1]) {
        --nsz;
      }
      arrInsert(nsz, nsz, nl, l[i], nr, r[i]);
    }
    for (i = (0); i < (nsz); i++) {
      auto a3PBjchb = ((nl[i]));
      auto j4Ja_un4 = ((nr[i]));
      l[i] = a3PBjchb;
      r[i] = j4Ja_un4;
    }
    m = nsz;
    int cl = 0;
    for (i = (0); i < (n); i++) {
      for (cl = (cl); cl < (m); cl++) {
        if (l[cl] > a[i]) {
          break;
        }
        idx[cl] = i;
      }
    }
    long long minr = a[0];
    int lx = 0;
    int rx = 0;
    while (lx < m && idx[lx] == 0) {
      chmin(minr, r[lx]);
      ++lx;
    }
    dp[0] = abs(a[0] - minr);
    dp[1] = dp[0] * 2;
    rx = lx;
    long long ans = 4611686016279904256LL;
    for (i = (0); i < (n - 1); i++) {
      int j;
      int ci = i + 1;
      while (rx < m && idx[rx] == ci) {
        ++rx;
      }
      nsz = 0;
      arrInsert(nsz, nsz, nl, a[i], nr, a[i]);
      for (j = (lx); j < (rx); j++) {
        arrInsert(nsz, nsz, nl, l[j], nr, r[j]);
      }
      arrInsert(nsz, nsz, nl, a[i + 1], nr, a[i + 1]);
      memset(ndp, 0x7F, sizeof(ndp));
      if (i == n - 2) {
        long long mar = a[i];
        for (j = (0); j < (nsz - 1); j++) {
          chmax(mar, nl[j]);
        }
        mar -= a[i];
        ans = min_L(dp[0] + mar * 2, dp[1] + mar);
        break;
      }
      for (j = (0); j < (nsz - 1); j++) {
        int k;
        long long ldis = (nl[j] - a[i]);
        long long rdis = (a[i + 1] - nr[j + 1]);
        for (k = (0); k < (2); k++) {
          int x;
          for (x = (0); x < (2); x++) {
            chmin(ndp[k], dp[x] + (2 - x) * (ldis) + (1 + k) * (rdis));
          }
        }
      }
      lx = rx;
      memcpy(dp, ndp, sizeof(dp));
    }
    wt_L(ans);
    wt_L('\n');
  }
  return 0;
}
