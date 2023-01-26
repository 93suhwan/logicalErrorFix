#include <bits/stdc++.h>
using namespace std;
const long long int N = 200005;
const long long int LOG = 17;
void solve() {
  int n;
  cin >> n;
  int ar[n];
  for (int i = 0; i < n; i++) cin >> ar[i];
  if (n % 2 == 0) {
    cout << "YES" << '\n';
  } else {
    map<int, int> f;
    for (int i = 0; i < n; i++) f[ar[i]]++;
    for (auto x : f)
      if (x.second >= 2) {
        cout << "YES" << '\n';
        return;
      }
    cout << "NO" << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
