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
                         cLtraits_identity<T>>::type;
template <class S, class T>
struct cLtraits_common_type {
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS, tT>::type;
};
template <class S, class T>
inline auto min_L(S a, T b) -> typename cLtraits_common_type<S, T>::type {
  return (typename cLtraits_common_type<S, T>::type)a <=
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
inline void rd(char &c) {
  int i;
  for (;;) {
    i = my_getchar();
    if (i != ' ' && i != '\n' && i != '\r' && i != '\t' && i != EOF) {
      break;
    }
  }
  c = i;
}
inline int rd(char c[]) {
  int i;
  int sz = 0;
  for (;;) {
    i = my_getchar();
    if (i != ' ' && i != '\n' && i != '\r' && i != '\t' && i != EOF) {
      break;
    }
  }
  c[sz++] = i;
  for (;;) {
    i = my_getchar();
    if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) {
      break;
    }
    c[sz++] = i;
  }
  c[sz] = '\0';
  return sz;
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
template <class S, class T>
inline S chmin(S &a, T b) {
  if (a > b) {
    a = b;
  }
  return a;
}
vector<int> pos[200000 + 10];
vector<int> cpos[200000 + 10];
int n;
int k;
int a[200000 + 10];
int clr[200000 + 10];
char tmp[1025];
int main() {
  int PiIOrLma;
  int AuJVIghY = rd_int();
  for (PiIOrLma = (0); PiIOrLma < (AuJVIghY); PiIOrLma++) {
    int i;
    n = rd(tmp);
    k = 2;
    for (i = (0); i < (n); i++) {
      a[i] = tmp[i] - 'a';
    }
    int N = 'z' - 'a' + 2;
    for (i = (0); i < (N + 2); i++) {
      pos[i].clear();
      cpos[i].clear();
    }
    for (i = (0); i < (n + 2); i++) {
      clr[i] = 0;
    }
    for (i = (0); i < (n); i++) {
      pos[a[i]].push_back(i);
    }
    priority_queue<pair<int, int>> pq;
    for (i = (0); i < (k); i++) {
      pq.push(make_pair(-cpos[i].size(), i));
    }
    for (i = (0); i < (N); i++) {
      int j;
      for (j = (0); j < (min_L(k, pos[i].size())); j++) {
        pair<int, int> t = pq.top();
        pq.pop();
        cpos[t.second].push_back(pos[i][j]);
        pq.push(make_pair(-cpos[t.second].size(), t.second));
      }
    }
    int minval = 1073709056;
    for (i = (0); i < (k); i++) {
      chmin(minval, cpos[i].size());
    }
    for (i = (0); i < (k); i++) {
      int j;
      for (j = (0); j < (minval); j++) {
        clr[cpos[i][j]] = i + 1;
      }
    }
    int ans = 0;
    for (i = (0); i < (n); i++) {
      if (clr[i] != 0) {
        ++ans;
      }
    }
    wt_L(ans / 2);
    wt_L('\n');
  }
  return 0;
}
