#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (int i = 0; i < n; i += 1) {
    cin >> a[i];
  }
  vector<long long int> b = a;
  sort(b.begin(), b.end());
  if (n % 2 == 0) {
    cout << "YES"
         << "\n";
  } else {
    for (int i = 0; i < n; i += 1) {
      if (b[i] != a[i]) {
        cout << "YES"
             << "\n";
        return;
      }
    }
    cout << "NO"
         << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
