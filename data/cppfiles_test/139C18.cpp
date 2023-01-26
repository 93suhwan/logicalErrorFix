#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long n = s.size();
  if (n & 1) {
    cout << "NO" << endl;
  } else {
    for (long long i = 0; i < n / 2; i++) {
      if (s[i] != s[i + n / 2]) {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
