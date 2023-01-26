#include <bits/stdc++.h>
const double pi = acos(-1.0);
typedef const double &cd;
typedef const unsigned &cst;
typedef const unsigned int &cu;
typedef unsigned int *pu;
typedef const unsigned int *cpu;
struct cp {
  double a, b;
  __inline__ __attribute__((always_inline)) cp() {}
  __inline__ __attribute__((always_inline)) cp(cd x, cd y) : a(x), b(y) {}
  __inline__ __attribute__((always_inline)) cp operator+(const cp &o) const {
    return cp(a + o.a, b + o.b);
  }
  __inline__ __attribute__((always_inline)) cp operator-(const cp &o) const {
    return cp(a - o.a, b - o.b);
  }
  __inline__ __attribute__((always_inline)) cp operator*(const cp &o) const {
    return cp(a * o.a - b * o.b, b * o.a + a * o.b);
  }
  __inline__ __attribute__((always_inline)) cp operator*(cd o) const {
    return cp(a * o, b * o);
  }
  __inline__ __attribute__((always_inline)) cp operator!() const {
    return cp(a, -b);
  }
};
typedef cp *pcp;
typedef const cp *cpcp;
namespace cpoly {
__inline__ __attribute__((always_inline)) void fft(const pcp &x, cst k,
                                                   const pcp &w) {
  if (__builtin_expect((k == 1), 0)) return;
  for (unsigned int i = 0, j = 0; i < k; ++i) {
    if (i > j) std::swap(x[i], x[j]);
    for (unsigned int l = k >> 1; (j ^= l) < l; l >>= 1)
      ;
  }
  w[0] = cp(1, 0);
  const cpcp xk = x + k;
  {
    for (cp *a = x, *b = x + 1; a < xk; a += 2, b += 2) {
      const cp o = *b;
      *b = *a - o;
      *a = *a + o;
    }
  }
  for (unsigned int i = 2; i < k; i <<= 1) {
    const cp g = cp(std::cos(pi / i), std::sin(pi / i));
    for (unsigned int j = i; j -= 2; w[j | 1] = (w[j] = w[j >> 1]) * g)
      ;
    w[1] = g;
    for (cp *a = x, *b = x + i; a < xk; a += i, b += i) {
      const cp *wl = w;
      for (const pcp c = b; a < c; ++a, ++b, ++wl) {
        const cp o = *b * *wl;
        *b = *a - o;
        *a = *a + o;
      }
    }
  }
}
__inline__ __attribute__((always_inline)) void ifft(const pcp &x, cst k,
                                                    const pcp &w) {
  if (__builtin_expect((k == 1), 0)) return;
  for (unsigned int i = 0, j = 0; i < k; i++) {
    if (i > j) std::swap(x[i], x[j]);
    for (unsigned int l = k >> 1; (j ^= l) < l; l >>= 1)
      ;
  }
  w[0] = cp(1, 0);
  const cpcp xk = x + k;
  {
    for (cp *a = x, *b = x + 1; a < xk; a += 2, b += 2) {
      const cp o = *b;
      *b = *a - o;
      *a = *a + o;
    }
  }
  for (unsigned int i = 2; i < k; i <<= 1) {
    const cp g = cp(std::cos(pi / i), -std::sin(pi / i));
    for (unsigned int j = i; j -= 2; w[j | 1] = (w[j] = w[j >> 1]) * g)
      ;
    w[1] = g;
    for (cp *a = x, *b = x + i; a < xk; a += i, b += i) {
      cp *wl = w;
      for (const pcp c = b; a < c; ++a, ++b, ++wl) {
        const cp o = *b * *wl;
        *b = *a - o;
        *a = *a + o;
      }
    }
  }
  for (unsigned int i = 0; i < k; i++) x[i] = cp(x[i].a / k, x[i].b / k);
}
}  // namespace cpoly
namespace zpoly {
using cpoly::fft;
using cpoly::ifft;
using std::memcpy;
using std::memset;
__inline__ __attribute__((always_inline)) void times(const cpu &a, const cpu &b,
                                                     const pu &c, cu n, cu m) {
  unsigned int l = (n + m) >> 1, len = 1;
  for (; len <= l; len <<= 1)
    ;
  cp *x = new cp[len], *y = new cp[len];
  {
    cp *ed = x + (n >> 1);
    const unsigned int *ai = a;
    for (cp *i = x; i < ed; ++ai, ++i) {
      i->a = *ai;
      i->b = *++ai;
    }
    ed->a = *ai;
    ed->b = (n & 1) ? *++ai : 0;
    const pcp xk = x + len - 1;
    if (__builtin_expect((ed < xk), 1))
      memset(ed + 1, 0, (xk - ed) * sizeof(cp));
  }
  {
    cp *ed = y + (m >> 1);
    const unsigned int *bi = b;
    for (cp *i = y; i < ed; ++bi, ++i) {
      i->a = *bi;
      i->b = *++bi;
    }
    ed->a = *bi;
    ed->b = (m & 1) ? *++bi : 0;
    const pcp yk = y + len - 1;
    if (__builtin_expect((ed < yk), 1))
      memset(ed + 1, 0, (yk - ed) * sizeof(cp));
  }
  cp *w = new cp[len];
  fft(x, len, w);
  fft(y, len, w);
  unsigned int hl = len >> 1;
  x[0] = x[0] * y[0] + cp(x[0].b * y[0].b * 2, 0);
  if (len > 1) {
    x[hl] = x[hl] * y[hl];
    for (unsigned int i = 1, j; i < hl; ++i) {
      j = len - i;
      const cp tmp = x[i] * y[i] -
                     (x[i] - !x[j]) * (y[i] - !y[j]) * (w[i] + cp(1, 0)) * 0.25;
      x[j] = x[j] * y[j] - (x[j] - !x[i]) * (y[j] - !y[i]) *
                               (cp(1, 0) - w[j ^ len >> 1]) * 0.25;
      x[i] = tmp;
    }
  }
  ifft(x, len, w);
  unsigned int *now = c + (n + m);
  if ((n + m) & 1) {
    *now = unsigned int(x[l].b + 0.5);
    --now;
  }
  *now = unsigned int(x[l].a + 0.5);
  for (const cp *i = x + l; --i >= x;) {
    *--now = unsigned int(i->b + 0.5);
    *--now = unsigned int(i->a + 0.5);
  }
}
__inline__ __attribute__((always_inline)) void times_eq(const pu &a,
                                                        const cpu &b, cu n,
                                                        cu m) {
  unsigned int l = (n + m) >> 1, len = 1;
  for (; len <= l; len <<= 1)
    ;
  cp *x = new cp[len], *y = new cp[len];
  {
    cp *ed = x + (n >> 1);
    const unsigned int *ai = a;
    for (cp *i = x; i < ed; ++ai, ++i) {
      i->a = *ai;
      i->b = *++ai;
    }
    ed->a = *ai;
    ed->b = (n & 1) ? *++ai : 0;
    const pcp xk = x + len - 1;
    if (__builtin_expect((ed < xk), 1))
      memset(ed + 1, 0, (xk - ed) * sizeof(cp));
  }
  {
    cp *ed = y + (m >> 1);
    const unsigned int *bi = b;
    for (cp *i = y; i < ed; ++bi, ++i) {
      i->a = *bi;
      i->b = *++bi;
    }
    ed->a = *bi;
    ed->b = (m & 1) ? *++bi : 0;
    const pcp yk = y + len - 1;
    if (__builtin_expect((ed < yk), 1))
      memset(ed + 1, 0, (yk - ed) * sizeof(cp));
  }
  cp *w = new cp[len];
  fft(x, len, w);
  fft(y, len, w);
  unsigned int hl = len >> 1;
  x[0] = x[0] * y[0] + cp(x[0].b * y[0].b * 2, 0);
  if (len > 1) {
    x[hl] = x[hl] * y[hl];
    for (unsigned int i = 1, j; i < hl; ++i) {
      j = len - i;
      const cp tmp = x[i] * y[i] -
                     (x[i] - !x[j]) * (y[i] - !y[j]) * (w[i] + cp(1, 0)) * 0.25;
      x[j] = x[j] * y[j] - (x[j] - !x[i]) * (y[j] - !y[i]) *
                               (cp(1, 0) - w[j ^ len >> 1]) * 0.25;
      x[i] = tmp;
    }
  }
  ifft(x, len, w);
  unsigned int *now = a + (n + m);
  if ((n + m) & 1) {
    *now = unsigned int(x[l].b + 0.5);
    --now;
  }
  *now = unsigned int(x[l].a + 0.5);
  for (const cp *i = x + l; --i >= x;) {
    *--now = unsigned int(i->b + 0.5);
    *--now = unsigned int(i->a + 0.5);
  }
}
}  // namespace zpoly
namespace f_998244353_poly {
using std::memcpy;
using std::memset;
__inline__ __attribute__((always_inline)) unsigned long long quickpow(
    unsigned long long x, unsigned int k, unsigned long long ret = 1) {
  for (; k; k >>= 1, x = x * x % 998244353)
    if (k & 1) ret = ret * x % 998244353;
  return ret;
}
inline void mod1(unsigned int &x) { x >= 998244353 && (x -= 998244353); }
inline void mod2(unsigned int &x) { int(x) < 0 && (x += 998244353); }
inline void getw(const pu &w, cu l) {
  for (unsigned int i = l >> 1, wi; i; w[i >>= 1] = wi)
    wi = quickpow(3, 499122176 / i);
  for (unsigned int i = 1, ed = l >> 1; i < ed; i <<= 1) {
    const cpu c = w + i;
    const unsigned long long wi = *c;
    for (pu a = w, b = w + i; (++b, ++a) < c; *b = *a * wi % 998244353)
      ;
  }
  w[0] = 1;
}
inline void getiw_with_w(const pu &w, cu l) {
  if (l >= 4) {
    w[1] = 998244353 - w[1];
    for (unsigned int i = 2, ed = l >> 1; i < ed; i <<= 1)
      for (pu a = w + i, b = w + (i << 1); --b > a; ++a) {
        const unsigned int o = *a;
        *a = 998244353 - *b;
        *b = 998244353 - o;
      }
  }
}
inline void ntt_with_w(const pu &x, cu l, const cpu &w) {
  const cpu xl = x + l;
  for (unsigned int i = l; i >>= 1;) {
    cpu wl = w;
    for (pu a = x, b = x + i; a < xl; a += i, b += i, ++wl) {
      const unsigned long long w = *wl;
      for (const cpu c = b; a < c; ++a, ++b) {
        const unsigned int o = *b * w % 998244353;
        mod2(*b = *a - o);
        mod1(*a += o);
      }
    }
  }
}
inline void intt_with_iw(const pu &x, cu l, const cpu &w) {
  const cpu xl = x + l;
  for (unsigned int i = 1; i < l; i <<= 1) {
    cpu wl = w;
    for (pu a = x, b = x + i; a < xl; a += i, b += i, ++wl) {
      const unsigned long long w = *wl;
      for (const cpu c = b; a < c; ++a, ++b) {
        const unsigned int o = *b;
        *b = (*a - o + 998244353) * w % 998244353;
        mod1(*a += o);
      }
    }
  }
  unsigned long long iv = quickpow(l, 998244351);
  for (unsigned int *i = x + l; --i >= x; *i = *i * iv % 998244353)
    ;
}
inline void ntt(const pu &x, cu l, const pu &w) {
  getw(w, l);
  ntt_with_w(x, l, w);
}
inline void intt(const pu &x, cu l, const pu &w) {
  getw(w, l);
  getiw_with_w(w, l);
  intt_with_iw(x, l, w);
}
__inline__ __attribute__((always_inline)) unsigned int getl(unsigned int l) {
  if (__builtin_expect((!l), 0))
    l = 1;
  else {
    for (unsigned int tmp; (tmp = l & (l - 1)); l = tmp)
      ;
    l <<= 1;
  }
  return l;
}
__inline__ __attribute__((always_inline)) void times_eq_non_const_wel_small_1(
    const pu &a, const pu &b, cu l) {
  const pu w = new unsigned int[l];
  getw(w, l);
  ntt_with_w(a, l, w);
  ntt_with_w(b, l, w);
  for (unsigned int *ai = a + l, *bi = b + l; (--bi, --ai) >= a;
       *ai = unsigned long long(*ai) * *bi % 998244353)
    ;
  getiw_with_w(w, l);
  intt_with_iw(a, l, w);
  delete[] w;
}
__inline__ __attribute__((always_inline)) void times_eq_non_const_wel_small(
    const pu &a, const pu &b, cu n, cu m, cu l) {
  memset(a + n + 1, 0, (l - n - 1) << 2);
  memset(b + m + 1, 0, (l - m - 1) << 2);
  times_eq_non_const_wel_small_1(a, b, l);
}
__inline__ __attribute__((always_inline)) void times_eq_non_const_wel_small(
    const pu &a, const pu &b, cu n, cu m) {
  times_eq_non_const_wel_small(a, b, n, m, getl(n + m));
}
__inline__ __attribute__((always_inline)) void times_non_const_wel_small(
    const pu &a, const pu &b, const pu &c, cu n, cu m, cu l) {
  times_eq_non_const_wel_small(a, b, n, m, l);
  memcpy(c, a, (n + m + 1) << 2);
}
__inline__ __attribute__((always_inline)) void times_non_const_wel_small(
    const pu &a, const pu &b, const pu &c, cu n, cu m) {
  times_non_const_wel_small(a, b, c, n, m, getl(n + m));
}
template <typename T_iita, typename T_iitb, typename T_oitc>
__inline__ __attribute__((always_inline)) void times_big(cu n, cu m,
                                                         T_iita &iita,
                                                         T_iitb &iitb,
                                                         T_oitc &oitc) {
  unsigned int nb = n / 4194304, mb = m / 4194304;
  const pu a = new unsigned int[(nb + 1) * 8388608],
           b = new unsigned int[(mb + 1) * 8388608];
  const pu w = new unsigned int[8388608];
  getw(w, 8388608);
  const pu anb = a + nb * 8388608, bmb = b + mb * 8388608;
  {
    const pu an = a + ((n << 1) - n % 4194304);
    unsigned int *x = a;
    for (; (x + 4194304) <= an; x += 4194304) {
      for (const pu ed = x + 4194304; x < ed; ++x, ++iita) *x = *iita;
      memset(x, 0, 4194304 << 2);
      ntt_with_w(x - 4194304, 8388608, w);
    }
    for (; x <= an; ++x, ++iita) *x = *iita;
    memset(x, 0, 8388608 - (x - anb));
    ntt_with_w(anb, 8388608, w);
  }
  {
    const pu bm = b + ((m << 1) - m % 4194304);
    unsigned int *x = b;
    for (; (x + 4194304) <= bm; x += 4194304) {
      for (const pu ed = x + 4194304; x < ed; ++x, ++iitb) *x = *iitb;
      memset(x, 0, 4194304 << 2);
      ntt_with_w(x - 4194304, 8388608, w);
    }
    for (; x <= bm; ++x, ++iitb) *x = *iitb;
    memset(x, 0, 8388608 - (x - bmb));
    ntt_with_w(bmb, 8388608, w);
  }
  const pu now = new unsigned int[8388608], prv = new unsigned int[4194304];
  memset(prv, 0, 4194304 << 2);
  getiw_with_w(w, 8388608);
  if (nb <= mb) {
    for (unsigned int i = 0; i <= nb; ++i) {
      memset(now, 0, 8388608 << 2);
      for (unsigned int *x = a, *y = b + i * 8388608; y >= b; y -= 8388608 << 1)
        for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
          *t = (*t + unsigned long long(*x) * *y) % 998244353;
      intt_with_iw(now, 8388608, w);
      for (unsigned int i = 0; i < 4194304; ++i, ++oitc) {
        unsigned int x = now[i] + prv[i];
        mod1(x);
        *oitc = x;
      }
      memcpy(prv, now + 4194304, 4194304 << 2);
    }
    if (__builtin_expect((nb), 1)) {
      for (unsigned int i = 1, ed = mb - nb; i <= ed; ++i) {
        memset(now, 0, 8388608 << 2);
        for (unsigned int *x = anb, *y = b + i * 8388608; x >= a;
             x -= 8388608 << 1)
          for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
            *t = (*t + unsigned long long(*x) * *y) % 998244353;
        intt_with_iw(now, 8388608, w);
        for (unsigned int i = 0; i < 4194304; ++i, ++oitc) {
          unsigned int x = now[i] + prv[i];
          mod1(x);
          *oitc = x;
        }
        memcpy(prv, now + 4194304, 4194304 << 2);
      }
      for (unsigned int i = nb; --i;) {
        memset(now, 0, 8388608 << 2);
        for (unsigned int *x = anb - i * 8388608, *y = bmb; x <= anb;
             y -= 8388608 << 1)
          for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
            *t = (*t + unsigned long long(*x) * *y) % 998244353;
        intt_with_iw(now, 8388608, w);
        for (unsigned int i = 0; i < 4194304; ++i, ++oitc) {
          unsigned int x = now[i] + prv[i];
          mod1(x);
          *oitc = x;
        }
        memcpy(prv, now + 4194304, 4194304 << 2);
      }
    } else {
      for (unsigned int i = 1, ed = mb - nb; i < ed; ++i) {
        memset(now, 0, 8388608 << 2);
        for (unsigned int *x = anb, *y = b + i * 8388608; x >= a;
             x -= 8388608 << 1)
          for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
            *t = (*t + unsigned long long(*x) * *y) % 998244353;
        intt_with_iw(now, 8388608, w);
        for (unsigned int i = 0; i < 4194304; ++i, ++oitc) {
          unsigned int x = now[i] + prv[i];
          mod1(x);
          *oitc = x;
        }
        memcpy(prv, now + 4194304, 4194304 << 2);
      }
    }
    for (unsigned int *x = anb, *y = bmb, *t = now, *ed = anb + 8388608; x < ed;
         ++x, ++y, ++t)
      *t = unsigned long long(*x) * *y % 998244353;
    intt_with_iw(now, 8388608, w);
    unsigned int exl = n + m - 4194304 * (nb + mb);
    if (exl < 4194304) {
      for (unsigned int i = 0; i <= exl; ++i, ++oitc) {
        unsigned int x = now[i] + prv[i];
        mod1(x);
        *oitc = x;
      }
    } else {
      for (unsigned int i = 0; i < 4194304; ++i, ++oitc) {
        unsigned int x = now[i] + prv[i];
        mod1(x);
        *oitc = x;
      }
      for (unsigned int *i = now + 4194304, *ed = now + exl; i <= ed;
           ++i, ++oitc)
        *oitc = *i;
    }
  } else {
    for (unsigned int i = 0; i <= mb; ++i) {
      memset(now, 0, 8388608 << 2);
      for (unsigned int *x = b, *y = a + i * 8388608; y >= a; y -= 8388608 << 1)
        for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
          *t = (*t + unsigned long long(*x) * *y) % 998244353;
      intt_with_iw(now, 8388608, w);
      for (unsigned int i = 0; i < 4194304; ++i, ++oitc) {
        unsigned int x = now[i] + prv[i];
        mod1(x);
        *oitc = x;
      }
      memcpy(prv, now + 4194304, 4194304 << 2);
    }
    if (__builtin_expect((mb), 1)) {
      for (unsigned int i = 1, ed = nb - mb; i <= ed; ++i) {
        memset(now, 0, 8388608 << 2);
        for (unsigned int *x = bmb, *y = a + i * 8388608; x >= b;
             x -= 8388608 << 1)
          for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
            *t = (*t + unsigned long long(*x) * *y) % 998244353;
        intt_with_iw(now, 8388608, w);
        for (unsigned int i = 0; i < 4194304; ++i, ++oitc) {
          unsigned int x = now[i] + prv[i];
          mod1(x);
          *oitc = x;
        }
        memcpy(prv, now + 4194304, 4194304 << 2);
      }
      for (unsigned int i = mb; --i;) {
        memset(now, 0, 8388608 << 2);
        for (unsigned int *x = bmb - i * 8388608, *y = anb; x <= bmb;
             y -= 8388608 << 1)
          for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
            *t = (*t + unsigned long long(*x) * *y) % 998244353;
        intt_with_iw(now, 8388608, w);
        for (unsigned int i = 0; i < 4194304; ++i, ++oitc) {
          unsigned int x = now[i] + prv[i];
          mod1(x);
          *oitc = x;
        }
        memcpy(prv, now + 4194304, 4194304 << 2);
      }
    } else {
      for (unsigned int i = 1, ed = nb - mb; i < ed; ++i) {
        memset(now, 0, 8388608 << 2);
        for (unsigned int *x = bmb, *y = a + i * 8388608; x >= b;
             x -= 8388608 << 1)
          for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
            *t = (*t + unsigned long long(*x) * *y) % 998244353;
        intt_with_iw(now, 8388608, w);
        for (unsigned int i = 0; i < 4194304; ++i, ++oitc) {
          unsigned int x = now[i] + prv[i];
          mod1(x);
          *oitc = x;
        }
        memcpy(prv, now + 4194304, 4194304 << 2);
      }
    }
    for (unsigned int *x = bmb, *y = anb, *t = now, *ed = bmb + 8388608; x < ed;
         ++x, ++y, ++t)
      *t = unsigned long long(*x) * *y % 998244353;
    intt_with_iw(now, 8388608, w);
    unsigned int exl = n + m - 4194304 * (mb + nb);
    if (exl < 4194304) {
      for (unsigned int i = 0; i <= exl; ++i, ++oitc) {
        unsigned int x = now[i] + prv[i];
        mod1(x);
        *oitc = x;
      }
    } else {
      for (unsigned int i = 0; i < 4194304; ++i, ++oitc) {
        unsigned int x = now[i] + prv[i];
        mod1(x);
        *oitc = x;
      }
      for (unsigned int *i = now + 4194304, *ed = now + exl; i <= ed;
           ++i, ++oitc)
        *oitc = *i;
    }
  }
  delete[] w, delete[] now, delete[] prv;
}
__inline__ __attribute__((always_inline)) void times_big_fbstd(cu n, cu m) {
  using std::fread;
  using std::fwrite;
  unsigned int nb = n / 4194304, mb = m / 4194304;
  const pu a = new unsigned int[(nb + 1) * 8388608],
           b = new unsigned int[(mb + 1) * 8388608];
  const pu w = new unsigned int[8388608];
  getw(w, 8388608);
  const pu anb = a + nb * 8388608, bmb = b + mb * 8388608;
  {
    const pu an = a + ((n << 1) - n % 4194304);
    unsigned int *x = a;
    for (; (x + 4194304) <= an; x += 8388608) {
      fread(x, 4, 4194304, stdin);
      memset(x + 4194304, 0, 4194304 << 2);
      ntt_with_w(x, 8388608, w);
    }
    fread(x, 4, an - x + 1, stdin);
    memset(an + 1, 0, 8388608 - (an - x + 1));
    ntt_with_w(x, 8388608, w);
  }
  {
    const pu bm = b + ((m << 1) - m % 4194304);
    unsigned int *x = b;
    for (; (x + 4194304) <= bm; x += 8388608) {
      fread(x, 4, 4194304, stdin);
      memset(x + 4194304, 0, 4194304 << 2);
      ntt_with_w(x, 8388608, w);
    }
    fread(x, 4, bm - x + 1, stdin);
    memset(bm + 1, 0, 8388608 - (bm - x + 1));
    ntt_with_w(x, 8388608, w);
  }
  const pu now = new unsigned int[8388608], prv = new unsigned int[4194304];
  memset(prv, 0, 4194304 << 2);
  getiw_with_w(w, 8388608);
  if (nb <= mb) {
    for (unsigned int i = 0; i <= nb; ++i) {
      memset(now, 0, 8388608 << 2);
      for (unsigned int *x = a, *y = b + i * 8388608; y >= b; y -= 8388608 << 1)
        for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
          *t = (*t + unsigned long long(*x) * *y) % 998244353;
      intt_with_iw(now, 8388608, w);
      for (unsigned int i = 0; i < 4194304; ++i) mod1(now[i] += prv[i]);
      fwrite(now, 4, 4194304, stdout);
      memcpy(prv, now + 4194304, 4194304 << 2);
    }
    if (__builtin_expect((nb), 1)) {
      for (unsigned int i = 1, ed = mb - nb; i <= ed; ++i) {
        memset(now, 0, 8388608 << 2);
        for (unsigned int *x = anb, *y = b + i * 8388608; x >= a;
             x -= 8388608 << 1)
          for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
            *t = (*t + unsigned long long(*x) * *y) % 998244353;
        intt_with_iw(now, 8388608, w);
        for (unsigned int i = 0; i < 4194304; ++i) mod1(now[i] += prv[i]);
        fwrite(now, 4, 4194304, stdout);
        memcpy(prv, now + 4194304, 4194304 << 2);
      }
      for (unsigned int i = nb; --i;) {
        memset(now, 0, 8388608 << 2);
        for (unsigned int *x = anb - i * 8388608, *y = bmb; x <= anb;
             y -= 8388608 << 1)
          for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
            *t = (*t + unsigned long long(*x) * *y) % 998244353;
        intt_with_iw(now, 8388608, w);
        for (unsigned int i = 0; i < 4194304; ++i) mod1(now[i] += prv[i]);
        fwrite(now, 4, 4194304, stdout);
        memcpy(prv, now + 4194304, 4194304 << 2);
      }
    } else {
      for (unsigned int i = 1, ed = mb - nb; i < ed; ++i) {
        memset(now, 0, 8388608 << 2);
        for (unsigned int *x = anb, *y = b + i * 8388608; x >= a;
             x -= 8388608 << 1)
          for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
            *t = (*t + unsigned long long(*x) * *y) % 998244353;
        intt_with_iw(now, 8388608, w);
        for (unsigned int i = 0; i < 4194304; ++i) mod1(now[i] += prv[i]);
        fwrite(now, 4, 4194304, stdout);
        memcpy(prv, now + 4194304, 4194304 << 2);
      }
    }
    for (unsigned int *x = anb, *y = bmb, *t = now, *ed = anb + 8388608; x < ed;
         ++x, ++y, ++t)
      *t = unsigned long long(*x) * *y % 998244353;
    intt_with_iw(now, 8388608, w);
    unsigned int exl = n + m - 4194304 * (nb + mb);
    if (exl < 4194304) {
      for (unsigned int i = 0; i <= exl; ++i) mod1(now[i] += prv[i]);
      fwrite(now, 4, exl + 1, stdout);
    } else {
      for (unsigned int i = 0; i < 4194304; ++i) mod1(now[i] += prv[i]);
      fwrite(now, 4, exl + 1, stdout);
    }
  } else {
    for (unsigned int i = 0; i <= mb; ++i) {
      memset(now, 0, 8388608 << 2);
      for (unsigned int *x = b, *y = a + i * 8388608; y >= a; y -= 8388608 << 1)
        for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
          *t = (*t + unsigned long long(*x) * *y) % 998244353;
      intt_with_iw(now, 8388608, w);
      for (unsigned int i = 0; i < 4194304; ++i) mod1(now[i] += prv[i]);
      fwrite(now, 4, 4194304, stdout);
      memcpy(prv, now + 4194304, 4194304 << 2);
    }
    if (__builtin_expect((mb), 1)) {
      for (unsigned int i = 1, ed = nb - mb; i <= ed; ++i) {
        memset(now, 0, 8388608 << 2);
        for (unsigned int *x = bmb, *y = a + i * 8388608; x >= b;
             x -= 8388608 << 1)
          for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
            *t = (*t + unsigned long long(*x) * *y) % 998244353;
        intt_with_iw(now, 8388608, w);
        for (unsigned int i = 0; i < 4194304; ++i) mod1(now[i] += prv[i]);
        fwrite(now, 4, 4194304, stdout);
        memcpy(prv, now + 4194304, 4194304 << 2);
      }
      for (unsigned int i = mb; --i;) {
        memset(now, 0, 8388608 << 2);
        for (unsigned int *x = bmb - i * 8388608, *y = anb; x <= bmb;
             y -= 8388608 << 1)
          for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
            *t = (*t + unsigned long long(*x) * *y) % 998244353;
        intt_with_iw(now, 8388608, w);
        for (unsigned int i = 0; i < 4194304; ++i) mod1(now[i] += prv[i]);
        fwrite(now, 4, 4194304, stdout);
        memcpy(prv, now + 4194304, 4194304 << 2);
      }
    } else {
      for (unsigned int i = 1, ed = nb - mb; i < ed; ++i) {
        memset(now, 0, 8388608 << 2);
        for (unsigned int *x = bmb, *y = a + i * 8388608; x >= b;
             x -= 8388608 << 1)
          for (pu ed = x + 8388608, t = now; x < ed; ++x, ++y, ++t)
            *t = (*t + unsigned long long(*x) * *y) % 998244353;
        intt_with_iw(now, 8388608, w);
        for (unsigned int i = 0; i < 4194304; ++i) mod1(now[i] += prv[i]);
        fwrite(now, 4, 4194304, stdout);
        memcpy(prv, now + 4194304, 4194304 << 2);
      }
    }
    for (unsigned int *x = bmb, *y = anb, *t = now, *ed = bmb + 8388608; x < ed;
         ++x, ++y, ++t)
      *t = unsigned long long(*x) * *y % 998244353;
    intt_with_iw(now, 8388608, w);
    unsigned int exl = n + m - 4194304 * (mb + nb);
    if (exl < 4194304) {
      for (unsigned int i = 0; i <= exl; ++i) mod1(now[i] += prv[i]);
      fwrite(now, 4, exl + 1, stdout);
    } else {
      for (unsigned int i = 0; i < 4194304; ++i) mod1(now[i] += prv[i]);
      fwrite(now, 4, exl + 1, stdout);
    }
  }
  delete[] w, delete[] now, delete[] prv;
}
__inline__ __attribute__((always_inline)) void inv_small(const cpu &a,
                                                         const pu &b, cu n,
                                                         cu m) {
  if (__builtin_expect((m == 1), 0))
    b[0] = quickpow(a[0], 998244351);
  else {
    unsigned int l = 2;
    for (; l < m; l <<= 1)
      ;
    const pu w = new unsigned int[l], iw = new unsigned int[l],
             f = new unsigned int[l], g = new unsigned int[l];
    b[0] = quickpow(a[0], 998244351);
    getw(w, l);
    memcpy(iw, w, (l >> 1) << 2);
    getiw_with_w(iw, l);
    for (l = 1;; l <<= 1) {
      const unsigned int dl = l << 1;
      if (dl <= n)
        memcpy(f, a, dl << 2);
      else {
        memcpy(f, a, (n + 1) << 2);
        memset(f + n + 1, 0, (dl - n - 1) << 2);
      }
      ntt_with_w(f, dl, w);
      memcpy(g, b, l << 2);
      memset(g + l, 0, l << 2);
      ntt_with_w(g, dl, w);
      for (unsigned int *fi = f + dl, *gi = g + dl; (--gi, --fi) >= f;
           *fi = unsigned long long(*fi) * *gi % 998244353)
        ;
      intt_with_iw(f, dl, iw);
      memset(f, 0, l << 2);
      ntt_with_w(f, dl, w);
      for (unsigned int *fi = f + dl, *gi = g + dl; (--gi, --fi) >= f;
           *fi = unsigned long long(*fi) * *gi % 998244353)
        ;
      intt_with_iw(f, dl, w);
      if (dl >= m) break;
      for (unsigned int i = l; i < dl; ++i)
        b[i] = __builtin_expect((f[i]), 1) ? 998244353 - f[i] : 0;
    }
    for (unsigned int i = l; i < m; ++i)
      b[i] = __builtin_expect((f[i]), 1) ? 998244353 - f[i] : 0;
    delete[] w, delete[] iw, delete[] f, delete[] g;
  }
}
__inline__ __attribute__((always_inline)) void derivative_eq(const pu &a,
                                                             cu n) {
  for (unsigned int *i = a + 1, *ed = a + n; i <= ed; ++i)
    *(i - 1) = unsigned long long(i - a) * *i % 998244353;
  a[n] = 0;
}
__inline__ __attribute__((always_inline)) void integration_eq(const pu &a,
                                                              cu n) {
  unsigned long long now = 1;
  for (unsigned int i = 2; i <= n; ++i)
    a[i] = a[i] * (now = now * i % 998244353) % 998244353;
  now = quickpow(now * (n + 1) % 998244353, 998244351);
  for (unsigned int i = n + 1; i; --i) {
    a[i] = a[i - 1] * now % 998244353;
    now = now * i % 998244353;
  }
  a[0] = 0;
}
__inline__ __attribute__((always_inline)) void ln_eq_non_const_wel_small(
    const pu &a, cu n, cu m) {
  if (__builtin_expect((!n), 0)) {
    memset(a, 0, (m + 1) << 2);
    return;
  }
  const unsigned int l = getl(n + m - 2);
  const pu b = new unsigned int[l];
  inv_small(a, b, n, m);
  derivative_eq(a, n);
  times_eq_non_const_wel_small(a, b, n - 1, m - 1, l);
  integration_eq(a, m - 1);
}
__inline__ __attribute__((always_inline)) void
kth_derivative_value_eq_wel_small(const pu &a, cu n, cu p) {
  const unsigned int l = getl(n << 1);
  const pu b = new unsigned int[l];
  unsigned long long now = 1;
  for (unsigned int i = 2; i <= n; ++i)
    a[i] = a[i] * (now = now * i % 998244353) % 998244353;
  b[n] = now = quickpow(now, 998244353 - 2);
  for (unsigned int i = n; i; --i) b[i - 1] = now = now * i % 998244353;
  now = 1;
  for (unsigned int i = 1; i <= n; ++i)
    b[i] = b[i] * (now = now * p % 998244353) % 998244353;
  std::reverse(a, a + n + 1);
  times_eq_non_const_wel_small(a, b, n, n, l);
  std::reverse(a, a + n + 1);
  delete[] b;
}
__inline__ __attribute__((always_inline)) void taylor_series_eq_wel_small(
    const pu &a, cu n, cu p) {
  const unsigned int l = getl(n << 1);
  const pu b = new unsigned int[l];
  unsigned long long now = 1;
  for (unsigned int i = 2; i <= n; ++i)
    a[i] = a[i] * (now = now * i % 998244353) % 998244353;
  const unsigned int ifacn = b[n] = now = quickpow(now, 998244353 - 2);
  for (unsigned int i = n; i; --i) b[i - 1] = now = now * i % 998244353;
  now = 1;
  for (unsigned int i = 1; i <= n; ++i)
    b[i] = b[i] * (now = now * p % 998244353) % 998244353;
  std::reverse(a, a + n + 1);
  times_eq_non_const_wel_small(a, b, n, n, l);
  std::reverse(a, a + n + 1);
  a[n] = a[n] * (now = ifacn) % 998244353;
  for (unsigned int i = n, *j = a + n - 1; i; --i, --j)
    *j = *j * (now = now * i % 998244353) % 998244353;
  delete[] b;
}
__inline__ __attribute__((always_inline)) void division_eq_non_const_wel_small(
    const pu &a, const pu &b, cu n, cu m) {
  if (__builtin_expect((n < m), 0)) {
    a[0] = 0;
    return;
  }
  if (__builtin_expect((!m), 0)) {
    unsigned long long iv = quickpow(b[0], 998244353 - 2);
    for (pu i = a + n; i >= a; --i) *i = *i * iv % 998244353;
    return;
  }
  const unsigned int n1 = n - m;
  const unsigned int l = getl(n1 << 1);
  const pu c = new unsigned int[l];
  std::reverse(b, b + m + 1);
  inv_small(b, c, m, n1 + 1);
  std::reverse(a, a + n + 1);
  times_eq_non_const_wel_small(a, c, n1, n1, l);
  std::reverse(a, a + n1 + 1);
  delete[] c;
}
__inline__ __attribute__((always_inline)) void modulo_eq_non_const_wel_small(
    const pu &a, const pu &b, const pu &d, cu n, cu m) {
  if (__builtin_expect((n < m), 0)) {
    d[0] = 0;
    return;
  }
  if (__builtin_expect((!m), 0)) {
    unsigned long long iv = quickpow(b[0], 998244353 - 2);
    for (pu i = d + n, j = a + n; i >= d; --i, --j) *i = *j * iv % 998244353;
    a[0] = 0;
    return;
  }
  const unsigned int n1 = n - m;
  const unsigned int l1 = getl(n1 << 1);
  const pu c = new unsigned int[l1];
  std::reverse(b, b + m + 1);
  inv_small(b, c, m, n1 + 1);
  for (pu i = d, j = a + n, ed = d + n1; i <= ed; ++i, --j) *i = *j;
  times_eq_non_const_wel_small(d, c, n1, n1, l1);
  std::reverse(d, d + n1 + 1);
  std::reverse(b, b + m + 1);
  const unsigned int l2 = getl(n);
  const pu e = new unsigned int[l2];
  memcpy(e, d, (n1 + 1) << 2);
  times_eq_non_const_wel_small(b, e, m, n1, l2);
  if (__builtin_expect((m), 1))
    for (pu i = a + m - 1, j = b + m - 1; i >= a; --i, --j) mod2(*i -= *j);
  else
    a[0] = 0;
  delete[] c;
  delete[] e;
}
__inline__ __attribute__((always_inline)) void modulo_eq_non_const_wel_small(
    const pu &a, const pu &b, cu n, cu m) {
  if (__builtin_expect((n < m), 0)) return;
  if (__builtin_expect((!m), 0)) {
    a[0] = 0;
    return;
  }
  const unsigned int n1 = n - m;
  const unsigned int l1 = getl(n1 << 1);
  const unsigned int l2 = getl(n);
  const pu c = new unsigned int[l1];
  std::reverse(b, b + m + 1);
  inv_small(b, c, m, n1 + 1);
  const pu d = new unsigned int[std::max(l1, l2)];
  for (pu i = d, j = a + n, ed = d + n1; i <= ed; ++i, --j) *i = *j;
  times_eq_non_const_wel_small(d, c, n1, n1, l1);
  std::reverse(d, d + n1 + 1);
  std::reverse(b, b + m + 1);
  times_eq_non_const_wel_small(b, d, m, n1, l2);
  for (pu i = a + m - 1, j = b + m - 1; i >= a; --i, --j) mod2(*i -= *j);
  delete[] c;
  delete[] d;
}
}  // namespace f_998244353_poly
using namespace std;
using namespace f_998244353_poly;
constexpr int max_n = 100000;
constexpr int max_l = 1048576;
unsigned int a[max_l];
unsigned int b[max_l];
unsigned int c[max_l];
unsigned int w[max_l];
unsigned int iw[max_l];
int main() {
  int n;
  scanf("%d", &n);
  int now = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 1, ans1 = 1, ans2 = 1;
  for (int i = 1; i <= n; ++i) {
    char str[5];
    scanf("\n%s", str);
    if (str[1] == 'B')
      str[1] = 'W';
    else if (str[1] == 'W')
      str[1] = 'B';
    if (str[0] == str[1]) {
      if (str[0] == '?') ++cnt3, ++now, ans = ans * 2 % 998244353;
      if (str[0] == 'B')
        ans2 = 0;
      else if (str[0] == 'W')
        ans1 = 0;
    } else {
      if (str[0] == '?')
        if (str[1] == 'W')
          ++cnt1, ++now, ans1 = 0;
        else
          ++cnt2, ++now, ans2 = 0;
      else if (str[1] == '?')
        if (str[0] == 'B')
          ++cnt1, ++now, ans2 = 0;
        else
          ++cnt2, ++now, ans1 = 0;
      else {
        if (str[0] == 'B')
          --now;
        else
          ++now;
        ans = ans1 = ans2 = 0;
      }
    }
  }
  if (now < 0) {
    puts("0");
    return 0;
  }
  int l = f_998244353_poly::getl(n * 2);
  memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b)), memset(c, 0, sizeof(c));
  a[1] = a[2] = 1;
  b[0] = b[1] = 1;
  c[0] = c[2] = 1, c[1] = 2;
  f_998244353_poly::getw(w, l);
  f_998244353_poly::ntt_with_w(a, l, w);
  f_998244353_poly::ntt_with_w(b, l, w);
  f_998244353_poly::ntt_with_w(c, l, w);
  for (int i = 0; i < l; ++i)
    a[i] = quickpow(a[i], cnt1) * quickpow(b[i], cnt2) % 998244353 *
           quickpow(c[i], cnt3) % 998244353;
  f_998244353_poly::getiw_with_w(w, l);
  intt_with_iw(a, l, w);
  printf("%u %u %u %u\n%u %u %u %u\n", now, cnt1, cnt2, cnt3, a[now], ans, ans1,
         ans2);
  printf("%llu\n",
         (998244353 * 10000ll + a[now] - ans + ans1 + ans2) % 998244353);
  return 0;
}
