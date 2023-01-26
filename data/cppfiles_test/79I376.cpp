#include <bits/stdc++.h>
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
  int k;
  cin >> k;
  string s;
  cin >> s;
  vector<int> digit(10, 0);
  for (int i = 0; i < k; i++) {
    digit[s[i] - '0']++;
  }
  for (int i = 1; i < 10; i++) {
    if (isPrime(i)) continue;
    if (digit[i] > 0) {
      cout << 1 << '\n';
      cout << i << '\n';
      return;
    }
  }
  for (int i = 1; i < 10; i++) {
    if (digit[i] > 1) {
      cout << 2 << '\n';
      cout << 10 * i + i << '\n';
      return;
    }
  }
  if (digit[2] > 0 && s[0] != '2') {
    cout << 2 << '\n';
    cout << s[0] << 2 << '\n';
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
