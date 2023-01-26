#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
const int N = 1e5 + 169;
int a[N], pos[N];
long long cal(int x, int n) {
  int cnt[2] = {1 + (x != 0), 1 + (x != 1)};
  vector<long long> before[2];
  vector<long long> after[2];
  for (int i = 1; i <= n; ++i) {
    before[a[i] % 2].push_back(i);
    after[a[i] % 2].push_back(cnt[a[i] % 2]);
    cnt[a[i] % 2] += 2;
  }
  long long res = 1e18;
  for (int i = 0; i < 2; ++i) {
    int Count = 0;
    for (int j = 0; j < before[i].size(); ++j) {
      if (before[i][j] > n || after[i][j] > n) return 1e18;
      Count += abs(before[i][j] - after[i][j]);
    }
    amin(res, Count);
  }
  return res;
}
int Solve() {
  int n;
  cin >> n;
  int cnt[2] = {0, 0};
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    cnt[a[i] % 2]++;
  }
  if (abs(cnt[0] - cnt[1]) > 1) return cout << "-1\n", 0;
  cout << min(cal(0, n), cal(1, n)) << '\n';
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}
