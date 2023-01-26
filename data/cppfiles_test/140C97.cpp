#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  cin >> t;
  set<long long> s;
  vector<long long> v;
  for (long long i = 1; i <= 1e5; i++) {
    s.insert(i * i);
  }
  for (long long i = 1; i <= 1e3; i++) {
    s.insert(i * i * i);
  }
  v = vector<long long>(s.begin(), s.end());
  while (t--) {
    int n;
    cin >> n;
    int ans = upper_bound(v.begin(), v.end(), n) - v.begin();
    cout << ans << "\n";
  }
  return 0;
}
