#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 2e5 + 5;
int LA, LB;
long long prime[5], T[M][5], pre[N][5], S[N][5];
char A[N], B[M];
void Init() {
  prime[0] = 400000000000000013LL;
  prime[1] = 400000000000000117LL;
  prime[2] = 400000000000000193LL;
  prime[3] = 400000000000000247LL;
  prime[4] = 400000000000000291LL;
}
long long mul(long long x, long long y, long long p) {
  long long ret = 0;
  while (y) {
    if (y & 1) {
      ret = (ret + x) % p;
    }
    x = (x << 1) % p;
    y >>= 1;
  }
  return ret;
}
long long Get(int x, int y, int id, long long p) {
  return (S[y][id] - mul(S[x - 1][id], pre[y - x + 1][id], p) + p) % p;
}
void check(int l, int r, int x, int y) {
  if (l < 1 || l > r || r > LA || x < 1 || x > y || y > LA) {
    return;
  }
  for (int i = 0; i < 5; ++i) {
    long long p = prime[i];
    long long A = Get(l, r, i, p), B = Get(x, y, i, p);
    if ((A + B) % p == T[LB][i]) {
      printf("%d %d\n%d %d", l, r, x, y);
      exit(0);
    }
  }
}
bool equal(int st, int L) {
  for (int id = 0; id < 5; ++id) {
    if (Get(st, st + L - 1, id, prime[id]) != T[L - 1][id]) {
      return 0;
    }
  }
  return 1;
}
int main() {
  Init();
  scanf("%s %s", A + 1, B + 1);
  LA = strlen(A + 1);
  LB = strlen(B + 1);
  for (int i = 0; i < 5; ++i) {
    long long p = prime[i];
    pre[0][i] = 1;
    for (int j = 1; j <= LB; ++j) {
      T[j][i] = (T[j - 1][i] * 10 + B[j] - '0') % p;
    }
    for (int j = 1; j <= LA; ++j) {
      pre[j][i] = (pre[j - 1][i] * 10) % p;
      S[j][i] = (S[j - 1][i] * 10 + A[j] - '0') % p;
    }
  }
  for (int i = LB; i <= LA - LB + 2; ++i) {
    check(i - LB + 1, i - 1, i, i + LB - 2);
  }
  for (int i = 2; i <= LA - LB + 1; ++i) {
    int step = 1, x = 0;
    while (step) {
      if (x + step <= LB && equal(i + x, step)) {
        x += step, step <<= 1;
      } else {
        step >>= 1;
      }
    }
    check(i - LB + step, i - 1, i, i + LB - 1);
    check(i - LB + step + 1, i - 1, i, i + LB - 1);
  }
  for (int i = LB + 1; i <= LA - LB + 2; ++i) {
    int step = 1, x = 0;
    while (step) {
      if (x + step <= LB && equal(i - LB + x, step)) {
        x += step, step <<= 1;
      } else {
        step >>= 1;
      }
    }
    check(i - LB, i - 1, i, i + LB - step - 1);
    check(i - LB, i - 1, i, i + LB - step - 2);
  }
  return 0;
}
