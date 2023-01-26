#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void solve() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    vector<int> a(n, -1);
    for (int i = 0; i < n; i++) {
      if (s[0][i] != s[1][i])
        a[i] = 2;
      else if (s[0][i] == s[1][i] && s[0][i + 1] == s[1][i + 1] &&
               s[0][i] != s[0][i + 1] && i < n - 1) {
        a[i] = 0;
        a[i + 1] = 2;
        i++;
      } else if (s[0][i] == s[1][i] && s[1][i] == '1')
        a[i] = 0;
      else if (s[0][i] == s[1][i] && s[1][i] == '0')
        a[i] = 1;
    }
    int ans = accumulate(a.begin(), a.end(), 0);
    cout << ans << "\n";
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
