#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a[n * m];
  for (long long i = 0; i < n * m; i++) {
    cin >> a[i];
  }
  long long ct = 0;
  for (long long i = 0; i < n * m; i++) {
    for (long long j = 0; j < n * m; j++) {
      if (a[i] < a[j] && i < j) {
        ct++;
      }
    }
  }
  cout << ct << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
