#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 9;
const long long INF = 1e12;
int n = 100000;
long long a[MAXN];
int phi[MAXN];
void init() {
  for (int i = 1; i < MAXN; i++) {
    phi[i] = i;
  }
  for (int i = 2; i < MAXN; i++) {
    if (phi[i] == i) {
      for (int j = i; j < MAXN; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
}
long long c(int l, int r) {
  if (l > r) return INF;
  long long ans = 0;
  int lst = 0;
  for (int i = l; i <= r; i = lst + 1) {
    lst = r / (r / i);
    int x = 0;
    if (i >= l) {
      x = lst - i + 1;
    } else if (lst >= l) {
      x = lst - l + 1;
    }
    ans += a[r / i] * x;
  }
  return ans;
}
long long f[MAXN][20];
void work(int k, int l, int r, int L, int R) {
  if (l > r) return;
  int mid = (l + r) / 2;
  f[mid][k] = INF;
  int opt = L;
  long long cost = c(min(mid, R) + 1, mid);
  for (int i = min(mid, R); i >= L; i--) {
    long long newf = f[i][k - 1] + cost;
    if (newf <= f[mid][k]) {
      f[mid][k] = newf;
      opt = i;
    }
    if (i <= mid) {
      if (cost == INF)
        cost = a[mid / i];
      else
        cost += a[mid / i];
    }
  }
  work(k, l, mid - 1, L, opt);
  work(k, mid + 1, r, opt, R);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init();
  for (int i = 1; i < MAXN; i++) {
    a[i] = a[i - 1] + phi[i];
  }
  int n = 10000;
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    f[i][0] = INF;
  }
  for (int i = 1; i <= n; i++) {
    f[i][1] = 1ll * i * (i + 1) / 2;
  }
  for (int i = 2; i <= 16; i++) {
    work(i, 1, n, 1, n);
  }
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (k < 20 && (1 << k) <= n) {
      cout << f[n][k] << endl;
    } else {
      cout << n << endl;
    }
  }
  return 0;
}
