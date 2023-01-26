#include <bits/stdc++.h>
const long long M = 1e9 + 7;
const long long MAXN = 3e5 + 5;
using namespace std;
long long dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
vector<bool> is_prime(MAXN, true);
void test_cases() {
  long long n;
  char c;
  string s;
  cin >> n >> c >> s;
  if (count(s.begin(), s.end(), c) == n) {
    cout << 0 << '\n';
    ;
    return;
  }
  for (long long i = n / 2; i < n; i++) {
    if (s[i] == c) {
      cout << 1 << '\n';
      ;
      cout << i + 1 << '\n';
      ;
      return;
    }
  }
  cout << 2 << '\n';
  ;
  cout << n << ' ' << n - 1 << '\n';
  ;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  is_prime[0] = is_prime[1] = false;
  for (long long i = 2; i * i <= MAXN; i++) {
    if (is_prime[i]) {
      for (long long j = i + i; j < MAXN; j += i) {
        is_prime[j] = false;
      }
    }
  }
  long long t;
  cin >> t;
  while (t--) {
    test_cases();
  }
}
