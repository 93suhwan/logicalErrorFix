#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long int n, t, i, cou = 0, ans;
  vector<long int> v;
  cin >> t;
  while (t--) {
    cou = ans = 0;
    cin >> n;
    for (i = 1; i <= sqrt(n); i++) {
      if (pow(i, 2) <= n) {
        v.push_back(pow(i, 2));
      }
      if (pow(i, 3) <= n) {
        v.push_back(pow(i, 3));
      }
    }
    sort(v.begin(), v.end());
    ans = unique(v.begin(), v.end()) - v.begin();
    cout << ans << "\n";
    v.clear();
  }
  return 0;
}
