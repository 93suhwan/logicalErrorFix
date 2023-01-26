#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, total, i;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    total = 0;
    for (i = 0; i < n; i++) {
      if (i == n - 1)
        total += s[i] - '0';
      else if (s[i] != '0')
        total += s[i] - '0' + 1;
    }
    cout << total << "\n";
  }
  return 0;
}
