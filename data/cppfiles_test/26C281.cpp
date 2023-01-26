#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkMax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void chkMin(T &x, T y) {
  if (x > y) x = y;
}
template <typename T>
void inline read(T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 1) + (x << 3) + (s ^ 48);
    s = getchar();
  }
  x *= f;
}
const int N = 200010, Mod = 1e9 + 7;
int fact[N];
int qmi(int a, int k, int p) {
  int res = 1;
  while (k) {
    if (k & 1) res = (long long)res * a % p;
    a = (long long)a * a % p;
    k >>= 1;
  }
  return res;
}
int main() {
  int T;
  read(T);
  fact[0] = 1;
  int base = qmi(2, Mod - 2, Mod);
  for (int i = 1; i < N; i++) fact[i] = (long long)fact[i - 1] * i % Mod;
  while (T--) {
    int n;
    read(n);
    int res = (long long)fact[n * 2] * base % Mod;
    printf("%d\n", res);
  }
}
