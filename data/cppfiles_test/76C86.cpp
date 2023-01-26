#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 12;
const long long Mod = 1e9 + 7;
const long long oo = 1e18;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n;
long long m, gt[20];
pair<long long, int> f[N];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  f[n] = {1, n};
  gt[0] = 1;
  for (int _ = 1, __ = 10, i = _; i <= __; i++) gt[i] = (gt[i - 1] * i) % m;
  for (int _ = n - 1, __ = 1, i = _; i >= __; i--) {
    long long Value = f[i + 1].first;
    for (int j = 2; i * j <= n; j++) {
      int t = min(i * j + j, n + 1);
      Value = (Value + f[i * j].first - f[t].first) % m;
    }
    f[i] = {(Value + f[i + 1].first) % m, i};
  }
  cout << (f[1].first - f[2].first + m) % m;
}
