#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  long long h = 1;
  for (long long i = 0; i < n; i++) cin >> a[i];
  h += a[0];
  for (long long i = 1; i < n; i++) {
    if (a[i - 1] == a[i] && a[i] == 0) {
      h = -1;
      break;
    }
    if (a[i] == 1) h += a[i - 1] ? 5 : 1;
  }
  cout << h << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
