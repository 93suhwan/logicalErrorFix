#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5;
long long int dx[4] = {-1, 1, 0, 0};
long long int dy[4] = {0, 0, -1, 1};
bool is_prime(long long int x) {
  if (x == 2) return 1;
  if (x == 1) return 0;
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  for (long long int i = 0; i < n; i++) {
    if (!is_prime((s[i] - '0'))) {
      cout << "1\n" << s[i] << '\n';
      goto f;
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = i + 1; j < n; j++) {
      long long int x = ((s[i] - '0')) * 10 + ((s[j] - '0'));
      if (!is_prime(x)) {
        cout << "2\n" << x << '\n';
        goto f;
      }
    }
  }
f:;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
