#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum += a;
  }
  cout << (sum % n ? "1\n" : "0\n");
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
