#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int INF = 1e9;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a;
  long long int mx = 0;
  for (int i = 0; i < n; i++) {
    long long int z;
    cin >> z;
    mx = max(mx, z);
    a.push_back(z);
  }
  for (int i = 0; i < n - 1; i++) {
    mx = max(mx, a[i] * a[i + 1]);
  }
  cout << mx << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
