#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 5e5 + 5;
const int M = 2e5 + 5;
int LA, LB;
int prime[5], pre[N][5];
int T[M][5], S[N][5];
char A[N], B[M];
void Init() {
  prime[0] = 1000000007;
  prime[1] = 1000000009;
  prime[2] = 1000000021;
  prime[3] = 1000000033;
  prime[4] = 1000000087;
}
inline int GetA(int x, int y, int id, int p) {
  return (S[y][id] - (long long)S[x - 1][id] * pre[y - x + 1][id] % p + p) % p;
}
inline int GetB(int x, int y, int id, int p) {
  return (T[y][id] - (long long)T[x - 1][id] * pre[y - x + 1][id] % p + p) % p;
}
void check(int l, int r, int x, int y) {
  if (l < 1 || l > r || r > LA || x < 1 || x > y || y > LA) {
    return;
  }
  for (int i = 0; i < 5; ++i) {
    int p = prime[i];
    int A = GetA(l, r, i, p), B = GetA(x, y, i, p);
    if ((A + B) % p == T[LB][i]) {
      printf("%d %d\n%d %d", l, r, x, y);
      exit(0);
    }
  }
}
bool equal(int x, int y, int L) {
  for (int id = 0; id < 5; ++id) {
    long long p = prime[id];
    if (GetA(x, x + L - 1, id, p) != GetB(y, y + L - 1, id, p)) {
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
    int p = prime[i];
    pre[0][i] = 1;
    for (int j = 1; j <= LB; ++j) {
      T[j][i] = ((long long)T[j - 1][i] * 10 + B[j] - '0') % p;
    }
    for (int j = 1; j <= LA; ++j) {
      pre[j][i] = ((long long)pre[j - 1][i] * 10) % p;
      S[j][i] = ((long long)S[j - 1][i] * 10 + A[j] - '0') % p;
    }
  }
  for (int i = LB; i <= LA - LB + 2; ++i) {
    check(i - LB + 1, i - 1, i, i + LB - 2);
  }
  for (int i = 2; i <= LA - LB + 1; ++i) {
    int step = 1, x = 0;
    while (step) {
      if (x + step <= LB && equal(i + x, x + 1, step)) {
        x += step, step <<= 1;
      } else {
        step >>= 1;
      }
    }
    check(i - LB + x, i - 1, i, i + LB - 1);
    check(i - LB + x + 1, i - 1, i, i + LB - 1);
  }
  for (int i = LB + 1; i <= LA - LB + 2; ++i) {
    int step = 1, x = 0;
    while (step) {
      if (x + step <= LB && equal(i - LB + x, x + 1, step)) {
        x += step, step <<= 1;
      } else {
        step >>= 1;
      }
    }
    check(i - LB, i - 1, i, i + LB - x - 1);
    check(i - LB, i - 1, i, i + LB - x - 2);
  }
  assert(LB == 200000);
  return 0;
}
