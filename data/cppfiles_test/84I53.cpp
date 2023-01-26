#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const long long inf = 1ll << 60;
bool p[N + 5];
int np[N + 5], ps;
long long val[N + 5];
vector<int> d[N + 5];
void prep() {
  p[0] = p[1] = 1;
  val[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!p[i]) val[np[++ps] = i] = i - 1;
    for (int j = 1; i * np[j] <= N; j++) {
      p[i * np[j]] = 1;
      if (i % np[j])
        val[i * np[j]] = val[i] * (np[j] - 1);
      else {
        val[i * np[j]] = val[i] * np[j];
        break;
      }
    }
  }
  for (int i = 2; i <= N; i++) val[i] += val[i - 1];
  for (int i = 1; i <= N; i++)
    for (int j = i; j <= N; j += i) d[j].push_back(i);
}
int T;
long long f[19][N + 5];
int main() {
  prep();
  for (int i = 1; i <= N; i++) f[1][i] = 1ll * i * (i + 1) / 2;
  for (int i = 2; i <= 17; i++) {
    long long s = 0;
    int op = i;
    for (int j = 1; j < i; j++) f[i][j] = j;
    for (int j = i; j <= N; j++) {
      for (auto it : d[j]) {
        if (1ll * it * op > j) break;
        s += val[it] - val[it - 1];
      }
      while (op < j && f[i - 1][op] - f[i - 1][op - 1] <= val[j / op]) {
        s -= val[j / op];
        op++;
      }
      f[i][j] = f[i - 1][op - 1] + s;
    }
  }
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d %d", &n, &k);
    if ((1 << k) > n)
      printf("%d\n", n);
    else
      printf("%lld\n", f[k][n]);
  }
  return 0;
}
