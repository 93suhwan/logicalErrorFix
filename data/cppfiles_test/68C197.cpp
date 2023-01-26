#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long k;
  cin >> k;
  long long j = 1;
  for (j; j <= 1e5; j++) {
    if ((1 + (j - 1) * (j - 1)) > k) break;
  }
  j--;
  long long temp = 1 + (j - 1) * (j - 1);
  if ((k - temp) < j) {
    cout << (k - temp + 1) << " " << j << "\n";
  } else {
    cout << j << " " << abs(k - j * j) + 1 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
