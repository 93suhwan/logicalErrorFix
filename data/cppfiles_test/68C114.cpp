#include <bits/stdc++.h>
using namespace std;
void fail(string s) {
  cout << s;
  exit(0);
}
void fail(long long s) {
  cout << s;
  exit(0);
}
const long long dx[4] = {-1, 1, 0, 0};
const long long dy[4] = {0, 0, -1, 1};
void run_test_case() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "1 1\n";
    return;
  }
  long long m = sqrt(n - 1), p = m * m;
  long long q = n - p;
  if (q <= m + 1) {
    cout << q << " " << m + 1 << "\n";
  } else {
    q = 2 * m + 2 - q;
    cout << m + 1 << " " << q << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test_cases = 1;
  cin >> test_cases;
  while (test_cases--) run_test_case();
  return 0;
}
