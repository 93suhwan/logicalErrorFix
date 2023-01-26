#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, mod = 1e9 + 7;
int a[N], n;
long long t[3][N];
void add(long long t[], int p, long long x) {
  p += 5;
  for (; p < N; p += p & -p) t[p] += x;
}
long long que(long long t[], int p) {
  p += 5;
  long long s = 0;
  for (; p; p -= p & -p) s += t[p];
  return s;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = a[i]; j < N; j += a[i]) {
      long long num = que(t[0], min(j + a[i] - 1, N - 1)) - que(t[0], j - 1);
      long long sum = que(t[1], min(j + a[i] - 1, N - 1)) - que(t[1], j - 1);
      ans += sum - num * j;
      ans += num * a[i];
    }
    long long num = que(t[0], a[i]);
    long long sum = que(t[2], a[i]);
    ans += num * a[i] - sum;
    ans += que(t[1], a[i]);
    add(t[0], a[i], 1);
    add(t[1], a[i], a[i]);
    for (int j = a[i]; j < N; j += a[i]) {
      add(t[2], j, a[i]);
    }
    printf("%lld%c", ans, " \n"[i == n]);
  }
  return 0;
}
