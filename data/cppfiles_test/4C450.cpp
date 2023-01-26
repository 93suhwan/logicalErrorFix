#include <bits/stdc++.h>
using namespace std;
long long vis[200001];
bool sortcol(const vector<long long>& b, const vector<long long>& v2) {
  return b[0] < v2[0];
}
void solve() {
  long long n;
  cin >> n;
  if (n % 2 == 1)
    cout << 2 << " " << n - 1;
  else {
    cout << 2 << " " << n / 2;
  }
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
