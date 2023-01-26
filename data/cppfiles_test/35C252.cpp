#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void solve() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, m;
    cin >> n >> m;
    m++;
    long long ans = 0;
    for (int i = 30; i >= 0 and n < m; i--) {
      if ((n & (1 << i)) && !(m & (1 << i)))
        break;
      else if (!(n & (1 << i)) && (m & (1 << i)))
        ans |= (1 << i);
    }
    cout << ans << '\n';
  }
}
int main() {
  auto starttime = high_resolution_clock::now();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  auto endtime = high_resolution_clock::now();
  double duration = duration_cast<microseconds>(endtime - starttime).count();
  duration /= 1000000;
  cerr << "Time Taken : " << fixed << setprecision(6) << duration << " secs"
       << '\n';
  return 0;
}
