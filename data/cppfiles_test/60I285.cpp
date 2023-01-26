#include <bits/stdc++.h>
using namespace std;
double startTime;
double gct() { return ((double)clock() - startTime) / CLOCKS_PER_SEC; }
void suraj();
int main() {
  startTime = (double)clock();
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(15) << fixed << "\n";
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    suraj();
  }
  return 0;
}
const long long mod = 1e9 + 7;
void suraj() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v) cin >> i;
  vector<int> v2 = v;
  sort(v2.begin(), v2.end());
  int maxVal = v2[n - 1];
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    ans = min(ans, v[i] & maxVal);
  }
  cout << ans << "\n";
}
