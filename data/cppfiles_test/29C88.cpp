#include <bits/stdc++.h>
using namespace std;
char Buf[1 << 23], *P1 = Buf, *P2 = Buf;
template <typename T = int>
inline T read() {
  T x = 0;
  bool f = false;
  char ch =
      (P1 == P2 && (P2 = (P1 = Buf) + fread(Buf, 1, (1 << 23) - 10, stdin),
                    P1 == P2)
           ? EOF
           : *P1++);
  while (ch < '0' || ch > '9') {
    f |= (ch == '-');
    ch = (P1 == P2 && (P2 = (P1 = Buf) + fread(Buf, 1, (1 << 23) - 10, stdin),
                       P1 == P2)
              ? EOF
              : *P1++);
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = (P1 == P2 && (P2 = (P1 = Buf) + fread(Buf, 1, (1 << 23) - 10, stdin),
                       P1 == P2)
              ? EOF
              : *P1++);
  }
  return f ? -x : x;
}
constexpr int Max = 300000 + 100, top = 300000, block = 550,
              block_count = Max / block + 3;
int a[Max], n;
int bel[Max], lpos[block_count], rpos[block_count], tot;
void init(const int &n) {
  tot = n / block + bool(n % block);
  for (int i = 1; i <= tot; ++i)
    lpos[i] = rpos[i - 1] + 1, rpos[i] = rpos[i - 1] + block;
  rpos[tot] = n;
  for (int i = 1; i <= tot; ++i)
    for (int j = lpos[i]; j <= rpos[i]; ++j) bel[j] = i;
}
struct block_array {
  long long s1[Max], s2[block_count];
  inline void add(const int &x, const int &k) {
    for (int i = x; i <= rpos[bel[x]]; ++i) s1[i] += k;
    for (int i = bel[x]; i <= tot; ++i) s2[i] += k;
  }
  inline long long query(const int &x) {
    if (!x) return 0;
    return s1[x] + s2[bel[x] - 1];
  }
  inline long long query(const int &l, const int &r) {
    return query(r) - query(l - 1);
  }
} s1, s2;
long long sum[Max];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + (a[i] = read());
  init(top);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    s1.add(a[i], 1), s2.add(a[i], a[i]);
    ans += sum[i];
    for (int l = a[i], r; l <= top; l = r + 1) {
      r = min(l + a[i] - 1, top);
      ans -= 1ll * s1.query(l, r) * (l / a[i]) * a[i];
    }
    ans += 1ll * i * a[i];
    for (int l = 1, r; l <= a[i]; l = r + 1) {
      r = min(a[i], a[i] / (a[i] / l));
      ans -= 1ll * (a[i] / l) * s2.query(l, r);
    }
    printf("%lld ", ans);
  }
  putchar('\n');
  return 0;
}
