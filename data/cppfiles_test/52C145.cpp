#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  long long int num = INT_MIN, sum = 0;
  int in;
  for (int i = 0; i < n; i++) {
    cin >> in;
    if (in > num) num = in;
    sum += in;
  }
  float ans = num * 1.0 + (sum * 1.0 - num) / (n - 1);
  cout << setprecision(8);
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
