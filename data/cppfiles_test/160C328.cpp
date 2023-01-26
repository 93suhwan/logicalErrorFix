#include <bits/stdc++.h>
const long long INF = (1ll) * 1e18;
using namespace std;
void test_case() {
  int n, m;
  cin >> n >> m;
  int rb, rd, cb, cd, dr = 1, dc = 1;
  cin >> rb >> cb >> rd >> cd;
  int ans = 0;
  while (rb != rd && cb != cd) {
    if (rb + dr > n || rb + dr < 1) dr *= -1;
    if (cb + dc > m || cb + dc < 1) dc *= -1;
    rb += dr;
    cb += dc;
    ans++;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start = chrono::high_resolution_clock::now();
  int testno = 1;
  cin >> testno;
  for (int i = 1; i <= testno; i++) {
    test_case();
    cout << '\n';
  }
  auto end = chrono::high_resolution_clock::now();
  double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  time_taken *= 1e-9;
  cerr << fixed << time_taken << setprecision(9) << " sec" << endl;
  return 0;
}
