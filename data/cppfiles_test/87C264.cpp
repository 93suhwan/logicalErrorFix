#include <bits/stdc++.h>
using namespace std;
long long t;
void solve() {
  long long n;
  cin >> n;
  long long a[n + 1];
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long maxx = 0;
  for (long long i = n; i >= 1; i--) {
    if (a[i] > i) {
      long long tmp = a[i] - i;
      maxx = max(maxx, tmp);
    }
  }
  cout << maxx << endl;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
