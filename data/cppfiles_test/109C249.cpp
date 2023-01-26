#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] != '0') sum += (s[i] - '0') + 1;
  }
  cout << ((s[n - 1] != '0') ? sum - 1 : sum) << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
