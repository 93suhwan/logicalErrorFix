#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  long long cnt = 0, i = 1;
  long long req = n / 2;
  while (cnt < req) {
    cout << v[i] << " " << v[0] << endl;
    cnt++;
    i++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
