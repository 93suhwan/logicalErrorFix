#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long k;
  cin >> k;
  vector<long long> v;
  for (long long i = 1; i <= 1000; i++) {
    if (i % 3 == 0 || i % 10 == 3) continue;
    v.push_back(i);
  }
  cout << v[k - 1] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
