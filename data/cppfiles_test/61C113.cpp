#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a[n], b[n];
  map<long long int, long long int> mp1;
  map<long long int, long long int> mp2;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    mp1[a[i]]++;
    mp2[b[i]]++;
  }
  long long int ans = (n * (n - 1) * (n - 2)) / 6;
  for (long long int i = 0; i < n; i++) {
    ans -= (mp1[a[i]] - 1) * (1LL) * (mp2[b[i]] - 1);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t t1 = clock();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "Time elapsed: " << (double)(clock() - t1) / 1000 << " s" << endl;
}
