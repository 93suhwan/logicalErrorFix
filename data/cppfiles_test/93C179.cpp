#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long tmp = 1;
  long long ans = 0;
  while (tmp <= k) {
    tmp = tmp * 2;
    ans++;
  }
  ans = ans + (ceil((n - tmp) / (double)k));
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}
