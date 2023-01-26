#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int count = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] > '0' and s[i] <= '9') {
      count += 1 + s[i] - '0';
    }
  }
  cout << count + s[n - 1] - '0' << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
