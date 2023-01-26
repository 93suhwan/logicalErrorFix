#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, k;
int x[N], y[N], id[N];
int cmp(int a, int b) {
  if (x[a] == x[b]) return y[a] < y[b];
  return x[a] < x[b];
}
long long cross(int a, int o, int b) {
  return 1ll * (x[a] - x[o]) * (y[b] - y[o]) -
         1ll * (x[b] - x[o]) * (y[a] - y[o]);
}
double dist(int a, int b) {
  return sqrt(1ll * (x[a] - x[b]) * (x[a] - x[b]) +
              1ll * (y[a] - y[b]) * (y[a] - y[b]));
}
int check(int a, int b) {
  for (int i = 1; i <= n; i++) {
    if (i == a || i == b) continue;
    if (cross(a, b, i)) return 0;
  }
  return 1;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i], id[i] = i;
  if (check(id[2], id[3]))
    swap(id[1], id[3]);
  else if (check(id[1], id[3]))
    swap(id[2], id[3]);
  int out = -1;
  for (int i = 3; i <= n; i++)
    if (cross(id[1], id[2], id[i])) out = id[i];
  swap(id[out], id[n]);
  sort(id + 1, id + n, cmp);
  double sum = 0;
  for (int i = 1; i < n - 1; i++) sum += dist(id[i], id[i + 1]);
  cout.precision(20), cout << fixed;
  if (k == id[n]) {
    cout << sum + min(dist(id[1], id[n]), dist(id[n - 1], id[n])) << endl;
    return 0;
  }
  int pos = -1;
  for (int i = 1; i < n; i++)
    if (id[i] == k) pos = i;
  double res = 1.0 / 0.0;
  if (pos - 1 >= 1) {
    res = min(res, -dist(id[pos], id[pos - 1]) + dist(id[n], id[n - 1]) +
                       min(dist(id[1], id[n]), dist(id[pos - 1], id[n])));
  }
  if (pos + 1 < n) {
    res = min(res, -dist(id[pos], id[pos + 1]) + dist(id[n], id[1]) +
                       min(dist(id[n - 1], id[n]), dist(id[pos + 1], id[n])));
  }
  cout << sum + res << endl;
  return 0;
}
