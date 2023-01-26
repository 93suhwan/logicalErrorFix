#include <bits/stdc++.h>
using namespace std;
long long int m;
void update(int pos, long long int val, long long int t[]) {
  t[pos] += val;
  t[pos] %= m;
  pos /= 2;
  for (; pos >= 1; pos /= 2) {
    t[pos] = t[2 * pos] + t[2 * pos + 1];
    t[pos] %= m;
  }
}
long long int range(int a, int b, long long int t[]) {
  long long int res = 0;
  while (a <= b) {
    if (a % 2 == 1) res += t[a++];
    if (b % 2 == 0) res += t[b--];
    a /= 2;
    b /= 2;
    res %= m;
  }
  return res % m;
}
void solve() {
  int n, i, j;
  cin >> n >> m;
  long long int sum[n + 1], t[2 * n + 2], val;
  sum[1] = 0;
  sum[2] = 2;
  for (i = n + 1; i < 2 * n + 2; i++) {
    t[i] = (i - n) % 2;
  }
  t[n + 1] = 0;
  t[n + 2] = 2;
  for (i = n; i >= 1; i--) {
    t[i] = t[2 * i] + t[2 * i + 1];
  }
  for (i = 2; i <= n; i++) {
    update(i + n, sum[i - 1], t);
    update(i + n + 1, -sum[i - 1], t);
    val = range(n + 1, n + i, t);
    for (j = 2; j <= n / i; j++) {
      update(j * i + n, val, t);
      if (j * i + n + j < 2 * n + 2) update(j * i + n + j, -val, t);
    }
    sum[i] = sum[i - 1] + range(n + 1, n + i, t);
    sum[i] %= m;
  }
  cout << (range(n + 1, 2 * n, t) % m + m) % m;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
