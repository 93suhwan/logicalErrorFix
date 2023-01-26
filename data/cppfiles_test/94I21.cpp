#include <bits/stdc++.h>
using namespace std;
long long PM(long long a, long long b) { return ((a % b) + b) % b; }
void solve() {
  long long n, k;
  cin >> n >> k;
  int b = 0;
  for (long long i = (0); i < (n); i++) {
    int y;
    cin >> y;
    b |= (1 << y);
  }
  k += 1;
  long long t = 0, z = 9;
  string ans = "";
  for (long long i = (0); i < (11); i++) {
    if (i == 10)
      ans = to_string(k - t) + ans;
    else if (b & (1 << (i + 1))) {
      ans = to_string(min(z, k - t)) + ans;
      t += min(z, k - t);
      z = 9;
    } else {
      z *= 10ll;
      z += 9ll;
    }
    if (k - t <= z) {
      ans = to_string(k - t) + ans;
      t = k;
    }
    if (t >= k) break;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
