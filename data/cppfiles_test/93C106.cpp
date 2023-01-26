#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long cnt = 0;
  long long n, k;
  cin >> n >> k;
  while ((1LL << cnt) < k) {
    cnt++;
  }
  if (n - (1LL << cnt) > 0) cnt += (n - (1LL << cnt) + k - 1) / k;
  cout << cnt << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
