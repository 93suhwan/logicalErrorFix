#include <bits/stdc++.h>
using namespace std;
long long is_valid(long long a, long long b, long long ex, long long k) {
  long long n = a + b;
  long long c_a = n / 2;
  long long c_b = n / 2;
  if (n % 2) {
    if (ex)
      c_a++;
    else
      c_b++;
  }
  long long x = a + k - c_a;
  if (x % 2) return 0;
  if (x < 0) return 0;
  x /= 2;
  if (k - x <= c_a and x <= c_b and c_b + k - 2 * x == b and
      2 * x - k + c_a == a) {
    return 1;
  }
  return 0;
}
void solve(long long tc) {
  long long a, b;
  cin >> a >> b;
  vector<long long> sol;
  for (long long i = 0; i <= a + b; i++) {
    if (is_valid(a, b, 1, i) or is_valid(a, b, 0, i)) {
      sol.push_back(i);
    }
  }
  cout << sol.size() << endl;
  for (long long i = 0; i < sol.size(); i++) {
    cout << sol[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long t = 1;
  long long tc = 1;
  cin >> t;
  while (t--) {
    solve(tc);
    tc++;
  }
  return 0;
}
