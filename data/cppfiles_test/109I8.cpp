#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0;
    sum += (s[n - 1] - 48);
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != 0) {
        sum += (s[n - 1] - 48 + 1);
      }
    }
    cout << sum << "\n";
  }
  return 0;
}
