#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long get_min[515][2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  get_min[0][0] = 0;
  for (long long i = 1; i < 512; i++) get_min[i][0] = 1000;
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long a;
    cin >> a;
    for (long long x = 0; x < 512; x++)
      get_min[x][i & 1] = get_min[x][(i & 1) ^ 1];
    for (long long x = 0; x < 512; x++) {
      if (get_min[x][(i & 1) ^ 1] <= a)
        get_min[x ^ a][i & 1] = min(get_min[x ^ a][i & 1], a);
    }
  }
  long long cnt = 0;
  for (long long x = 0; x < 512; x++) {
    if (get_min[x][n & 1] != 1000) cnt++;
  }
  cout << cnt << "\n";
  for (long long x = 0; x < 512; x++) {
    if (get_min[x][n & 1] != 1000) cout << x << " ";
  }
  cout << "\n";
}
