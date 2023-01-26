#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long int n = s.length();
  if (s[n - 1] == 'E') {
    long long int count = 0;
    for (long long int i = 0; i < n - 1; i++) {
      if (s[i] == 'N') count++;
    }
    if (count == 1) {
      cout << "NO";
      return;
    }
    cout << "YES";
  } else {
    long long int count = 0;
    for (long long int i = 0; i < n - 1; i++) {
      if (s[i] == 'N') count++;
    }
    if (count == 0) {
      cout << "NO";
      return;
    }
    cout << "YES";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
