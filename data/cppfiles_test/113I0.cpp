#include <bits/stdc++.h>
using namespace std;
vector<bool> prime(200002, true);
void seive(long long mx) {
  prime[0] = prime[1] = false;
  for (long long i = 2; i * i <= mx; i++) {
    if (prime[i]) {
      for (long long j = i * i; j <= mx; j += i) {
        prime[j] = false;
      }
    }
  }
}
bool cmp(long long x, long long y) {
  if (x > y)
    return true;
  else
    return false;
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
void solve() {
  long long x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  long long a = x1 * pow(10, p1);
  long long b = x2 * pow(10, p2);
  if (a > b) {
    cout << ">" << endl;
  } else if (a == b) {
    cout << "=" << endl;
  } else {
    cout << "<" << endl;
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
