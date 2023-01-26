#include <bits/stdc++.h>
using namespace std;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long n;
string s;
bool prime[100];
void solve() {
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
        s[i] == '9') {
      cout << 1 << '\n';
      cout << s[i] << '\n';
      return;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (!prime[(s[i] - '0') * 10 + (s[j] - '0')]) {
        cout << 2 << '\n';
        cout << s[i] << s[j] << '\n';
        return;
      }
    }
  }
  exit(42);
}
signed main() {
  io();
  for (long long i = 2; i < 100; i++) {
    prime[i] = true;
    for (long long j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        prime[i] = false;
      }
    }
  }
  long long t = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    solve();
  }
  return 0;
}
