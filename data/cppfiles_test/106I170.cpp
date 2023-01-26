#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int val = 1;
  for (int i = 0; i < n; i++) {
    cout << val << " ";
    val = val + 2;
  }
  cout << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
