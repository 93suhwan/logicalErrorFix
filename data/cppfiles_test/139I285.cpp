#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long n = s.size();
  long long cnt = 0;
  for (long long i = 0; i < n / 2; i++) {
    if (s[i] != s[i + n / 2]) {
      cnt++;
      break;
    }
  }
  if (!cnt) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
