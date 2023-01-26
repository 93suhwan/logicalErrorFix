#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long int sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      continue;
    } else if (s[i] - '0' > 0 && i == n - 1) {
      sum += s[i] - '0';
    } else {
      sum += s[i] - '0';
      sum++;
    }
  }
  cout << sum << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
