#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  long long maxi = INT_MIN;
  for (int i = 1; i <= n; i++) {
    long long aux;
    cin >> aux;
    maxi = max(maxi, aux - i);
  }
  cout << maxi << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
