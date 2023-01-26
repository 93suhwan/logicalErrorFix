#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  long long int ans = a[0];
  for (int i = 1; i < n; i++) ans &= a[i];
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
