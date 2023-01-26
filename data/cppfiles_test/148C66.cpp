#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const long long int N = 1e5 + 5;
void JAISHREERAM() {
  long long int n, ans = 0, w, h;
  cin >> w >> h;
  vector<vector<long long int>> a(4);
  for (long long int i = 0; i < 4; i++) {
    long long int k;
    cin >> k;
    for (long long int j = 0; j < k; j++) {
      long long int x;
      cin >> x;
      a[i].emplace_back(x);
    }
    sort(a[i].begin(), a[i].end());
  }
  long long int mxx = max(a[0].back() - a[0][0], a[1].back() - a[1][0]);
  long long int mxy = max(a[2].back() - a[2][0], a[3].back() - a[3][0]);
  mxx *= h;
  mxy *= w;
  ans = max(mxx, mxy);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    JAISHREERAM();
  }
  return 0;
}
