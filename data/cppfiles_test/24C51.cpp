#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  long long n;
  cin >> n;
  cout << (n / 10) + (n % 10 == 9) << "\n";
}
