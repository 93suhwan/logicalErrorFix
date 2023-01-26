#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
long long in() {
  long long x;
  cin >> x;
  return x;
}
int In() {
  int x;
  cin >> x;
  return x;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  int ca = 0, cb = 0;
  for (long long i = 0; i < n; i++) {
    long long ca = 0, cb = 0;
    for (long long j = i; j < n; j++) {
      if (s[j] == 'a') {
        ca++;
      } else {
        cb++;
      }
      if (ca == cb && ca != 0 && cb != 0) {
        cout << i + 1 << " " << j + 1 << '\n';
        return;
      }
    }
  }
  cout << -1 << " " << -1 << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
