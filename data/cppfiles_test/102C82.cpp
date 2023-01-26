#include <bits/stdc++.h>
const int N = 1e2 + 5;
const long long M = 998244353;
int n, a, m, b[N], cmpa[N], cmpb[N];
int r[N], d[N];
long long c[N];
std::map<long long, long long> Map[60];
void pre() {
  c[0] = 1;
  for (int i = 1; i < 50; i++) {
    c[i] = c[i - 1] * a % M;
  }
}
long long pw(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) {
      res = res * x % M;
    }
    x = x * x % M;
    y >>= 1;
  }
  return res;
}
long long check(int s) {
  int k = n - 1;
  for (int i = 0; i < n; i++) {
    b[i] = i;
    r[i] = 0;
  }
  for (int i = 0; i < k; i++) {
    r[(s & (1 << i)) ? b[cmpb[i]] : b[cmpa[i]]] = d[i];
    b[cmpa[i]] = (s & (1 << i)) ? b[cmpa[i]] : b[cmpb[i]];
  }
  r[b[0]] = 1;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res = (res + (i + 1) * c[r[i]]) % M;
  }
  return res;
}
long long check2(int s) {
  int k = n - 1;
  for (int i = 0; i < n; i++) {
    b[i] = i;
    r[i] = 0;
  }
  for (int i = 0; i < k; i++) {
    r[(s & (1 << i)) ? b[cmpb[i]] : b[cmpa[i]]] = d[i];
    b[cmpa[i]] = (s & (1 << i)) ? b[cmpa[i]] : b[cmpb[i]];
  }
}
void pre2() {
  int sum = 0, p = 0;
  int tn = 1;
  while (tn < (1 << n)) {
    for (int i = 0; i < (1 << n); i += (tn << 1)) {
      cmpa[p] = i;
      cmpb[p] = i + tn;
      d[p] = ((1 << n) / (tn << 1)) + 1;
      p++;
    }
    tn <<= 1;
  }
}
void out() {
  for (int i = 0; i < n; i++) {
    printf("%d ", r[i]);
  }
}
void out(int s1, int p1, int s2, int p2) {
  check2(s1);
  for (int i = 0; i < n; i++) {
    if (r[i] != 0) {
      r[i] = (r[i] - 1) << 1 | 1;
    } else {
      r[i] = p1;
    }
    printf("%d ", r[i]);
  }
  check2(s2);
  for (int i = 0; i < n; i++) {
    if (r[i] != 0) {
      r[i] = (r[i] - 1) << 1 | 1;
    } else {
      r[i] = p2;
    }
    printf("%d ", r[i]);
  }
}
void sol_1() {
  pre2();
  n = 1 << n;
  int k = n - 1;
  for (int s = 0; s < (1 << k); s++) {
    if (check(s) == m) {
      out();
      return;
    }
  }
  puts("-1");
}
void sol_2() {
  n -= 1;
  pre2();
  n = 1 << n;
  int k = n - 1;
  for (int s = 0; s < (1 << k); s++) {
    check2(s);
    int tmp = 0;
    long long sum_1 = 0, sum_2 = 0;
    for (int i = 0; i < n; i++) {
      if (r[i] != 0) {
        r[i] = (r[i] - 1) * 2 + 1;
        sum_1 = (sum_1 + (i + 1) * c[r[i]]) % M;
        sum_2 = (sum_2 + (i + 1 + n) * c[r[i]]) % M;
      } else {
        tmp = i;
      }
    }
    Map[tmp][sum_1] = s;
    Map[tmp + n][sum_2] = s;
  }
  for (int i = 0; i < n; i++) {
    for (auto v : Map[i]) {
      long long tmp1 = (v.first + (i + 1) * c[1]) % M;
      long long tmp2 = (v.first + (i + 1) * c[2]) % M;
      for (int e = n; e < n * 2; e++) {
        long long tp1 = (m - (tmp1 + (e + 1) * c[2]) % M + M) % M;
        long long tp2 = (m - (tmp2 + (e + 1) * c[1]) % M + M) % M;
        decltype(Map[e].begin()) t;
        if ((t = Map[e].find(tp1)) != Map[e].end()) {
          out(v.second, 1, t->second, 2);
          return;
        }
        if ((t = Map[e].find(tp2)) != Map[e].end()) {
          out(v.second, 2, t->second, 1);
          return;
        }
      }
    }
  }
  puts("-1");
}
int main() {
  scanf("%d%d%d", &n, &a, &m);
  pre();
  if (n < 5) {
    sol_1();
  } else {
    sol_2();
  }
  return 0;
}
