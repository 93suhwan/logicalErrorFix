#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN = 1e5 + 3;
long long gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b, a % b);
}
void solve() {
  long long n;
  char c;
  string s;
  cin >> n >> c;
  cin >> s;
  bool issame = 1;
  bool divby[n + 1];
  for (int i = 1; i <= n; i++) divby[i] = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != c) {
      issame = 0;
      for (int j = 1; j * j <= i + 1; j++) {
        if ((i + 1) % j == 0) {
          divby[j] = 1;
          divby[(i + 1) / j] = 1;
        }
      }
    }
  }
  if (issame) {
    cout << 0 << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (divby[i] == 0) {
      cout << 1 << endl;
      cout << i << endl;
      return;
    }
  }
  cout << 2 << endl;
  for (int i = 2; i < n; i++) {
    if (n % i != 0) {
      cout << n << " " << i << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
