#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long count = 0, n = s.length();
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'B') count++;
    }
    if (count == n - count && count >= 2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
