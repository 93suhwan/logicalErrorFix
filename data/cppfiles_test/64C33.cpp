#include <bits/stdc++.h>
using namespace std;
const int N = 500000;
mt19937 Rand(time(0));
int mod[3];
struct hasher {
  int a[3];
  hasher(int x = 0) { a[0] = a[1] = a[2] = x; }
  friend hasher operator+(const hasher &a, const hasher &b) {
    hasher res;
    for (int i = 0; i < 3; ++i) {
      res.a[i] = a.a[i] + b.a[i];
      if (res.a[i] >= mod[i]) res.a[i] -= mod[i];
    }
    return res;
  }
  friend hasher operator-(const hasher &a, const hasher &b) {
    hasher res;
    for (int i = 0; i < 3; ++i) {
      res.a[i] = a.a[i] - b.a[i];
      if (res.a[i] < 0) res.a[i] += mod[i];
    }
    return res;
  }
  friend hasher operator*(const hasher &a, const hasher &b) {
    hasher res;
    for (int i = 0; i < 3; ++i) res.a[i] = 1LL * a.a[i] * b.a[i] % mod[i];
    return res;
  }
  friend bool operator==(const hasher &a, const hasher &b) {
    for (int i = 0; i < 3; ++i)
      if (a.a[i] != b.a[i]) return 0;
    return 1;
  }
  hasher inv() {
    hasher res = 1;
    for (int i = 0; i < 3; ++i) {
      int k = mod[i] - 2, x = a[i];
      for (; k; k >>= 1, x = 1LL * x * x % mod[i])
        if (k & 1) res.a[i] = 1LL * res.a[i] * x % mod[i];
    }
    return res;
  }
} pw[N + 9];
void Get_pw() {
  pw[0] = 1;
  pw[1] = 10;
  for (int i = 2; i <= N; ++i) pw[i] = pw[i - 1] * pw[1];
}
hasher Get_hash(hasher *h, int l, int r) {
  return h[r] - h[l - 1] * pw[r - l + 1];
}
hasher Get_hash(vector<hasher> &h, int l, int r) {
  return h[r] - h[l - 1] * pw[r - l + 1];
}
char s[N + 9], t[N + 9];
int n, m;
void into() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
}
int Get_mod0() { return 19260817; }
bool Check_prime(int n) {
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) return 0;
  return 1;
}
int Get_prime(int n) {
  for (; !Check_prime(n); ++n)
    ;
  return n;
}
int Get_mod1() {
  int sum = 0;
  for (int i = 1; i <= n; ++i) sum += s[i];
  for (int i = 1; i <= m; ++i) sum += t[i];
  int n = Rand() % 200000000 + 300000000 + sum;
  return Get_prime(n);
}
int Get_mod2() {
  int x = Rand() % 200000000 + 300000000;
  double y = 1.0 * (Rand() % 10);
  int sum = 0;
  for (int i = 1; i <= n; ++i) sum += (Rand() & 1 ? 1 : -1) * (s[i] - '0');
  for (int i = 1; i <= m; ++i) sum += (Rand() & 1 ? 1 : -1) * (t[i] - '0');
  return Get_prime((int)(x + exp(y) + cos(sum) * sum));
}
void Get_mod() {
  mod[0] = Get_mod0();
  mod[1] = Get_mod1();
  mod[2] = Get_mod2();
}
hasher hs[N + 9], ht[N + 9];
void Get_hash() {
  for (int i = 1; i <= n; ++i) hs[i] = hs[i - 1] * pw[1] + (s[i] - '0');
  for (int i = 1; i <= m; ++i) ht[i] = ht[i - 1] * pw[1] + (t[i] - '0');
}
int Get_lcp(int p) {
  int l = 1, r = m, res = 0;
  for (int mid; l <= r;) {
    mid = l + r >> 1;
    Get_hash(hs, p, p + mid - 1) == Get_hash(ht, 1, mid)
        ? (res = mid, l = mid + 1)
        : r = mid - 1;
  }
  return res;
}
void Get_ans() {
  for (int i = 1; i <= n; ++i) {
    if (i - (m - 1) >= 0 || i + (m - 1) <= n) {
      if (Get_hash(hs, i - (m - 1) + 1, i) + Get_hash(hs, i + 1, i + (m - 1)) ==
          ht[m]) {
        printf("%d %d\n%d %d\n", i - (m - 1) + 1, i, i + 1, i + (m - 1));
        return;
      }
    }
    if (i + m <= n) {
      int t = m - Get_lcp(i + 1);
      if (t >= 1 && i >= t &&
          Get_hash(hs, i + 1, i + m) + Get_hash(hs, i - t + 1, i) == ht[m]) {
        printf("%d %d\n%d %d\n", i - t + 1, i, i + 1, i + m);
        return;
      }
      if (t >= 2 && i >= t - 1 &&
          Get_hash(hs, i + 1, i + m) + Get_hash(hs, i - t + 2, i) == ht[m]) {
        printf("%d %d\n%d %d\n", i - t + 2, i, i + 1, i + m);
        return;
      }
    }
    if (i - m >= 0) {
      int t = m - Get_lcp(i - m + 1);
      if (t >= 1 && i + t <= n &&
          Get_hash(hs, i - m + 1, i) + Get_hash(hs, i + 1, i + t) == ht[m]) {
        printf("%d %d\n%d %d\n", i - m + 1, i, i + 1, i + t);
        return;
      }
      if (t >= 2 && i + t - 1 <= n &&
          Get_hash(hs, i - m + 1, i) + Get_hash(hs, i + 1, i + t - 1) ==
              ht[m]) {
        printf("%d %d\n%d %d\n", i - m + 1, i, i + 1, i + t - 1);
        return;
      }
    }
  }
}
void work() {
  Get_mod();
  Get_pw();
  Get_hash();
  Get_ans();
}
void outo() {}
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
