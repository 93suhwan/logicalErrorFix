#include <bits/stdc++.h>
using namespace std;
long long n;
void solve() {
  cin >> n;
  for (long long ini = 0; ini < n; ini++) {
    for (long long j = 0; j < ini; j++) cout << "()";
    for (long long j = 0; j < n - ini; j++) cout << "(";
    for (long long j = 0; j < n - ini; j++) cout << ")";
    cout << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve();
}
