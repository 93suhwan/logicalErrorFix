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
    int count = 0;
    for (int i = 0; i <= n - 2; i++) {
      if (s[i] != '0') count = count + s[i] + 1 - '0';
    }
    if (s[n - 1] != '0') count = count + s[n - 1] - '0';
    cout << count << "\n";
  }
  return 0;
}
