#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "a\n";
      continue;
    }
    if (n % 2) cout << "c";
    for (int j = 0; j < n / 2; j++) cout << "a";
    cout << "b";
    for (int j = 0; j < n / 2 - 1; j++) cout << "a";
    cout << "\n";
  }
  return 0;
}
