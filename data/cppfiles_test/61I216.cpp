#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    map<int, int> ma, mb;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      ma[a[i]]++;
      mb[b[i]]++;
    }
    long long res = (n * (n - 1) * (n - 2)) / 6;
    for (int i = 1; i <= n; i++) res -= (ma[a[i]] - 1) * (mb[b[i]] - 1);
    cout << res << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
