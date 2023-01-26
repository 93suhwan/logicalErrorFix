#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long temp1 = (n / 3);
  long long temp2 = ceil((double)n / (double)3);
  long long res1 = (n - (2 * temp1));
  long long res2 = (n - (2 * temp2));
  long long ans1 = abs(res1 - temp1);
  long long ans2 = abs(res2 - temp2);
  if (ans1 <= ans2) {
    cout << res1 << " " << temp1 << endl;
    return;
  }
  cout << res2 << " " << temp2 << endl;
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
