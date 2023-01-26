#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v;
  long long int temp;
  for (long long int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end(), greater<int>());
  double ans = v[0];
  double s = 0.0;
  for (long long int i = 1; i < n; i++) {
    s += (double)v[i];
  }
  s = s / (double)(n - 1);
  ans += s;
  cout << setprecision(10) << ans << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
