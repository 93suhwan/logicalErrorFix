#include <bits/stdc++.h>
using namespace std;
long long power(long long, long long);
void solution() {
  long long n, maxm;
  cin >> n;
  string s;
  cin >> s;
  maxm = n / 2;
  if (n & 1) maxm++;
  for (long long i = n - 1; i >= maxm; i--) {
    if (s[i] == '0') {
      cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
      return;
    }
  }
  for (int i = maxm - 1; i >= 0; i--) {
    if (s[i] == '0') {
      cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
      return;
    }
  }
  if (n & 1) {
    cout << 1 << " " << maxm << " " << maxm << " " << n << "\n";
  } else {
    cout << 1 << " " << maxm << " " << maxm + 1 << " " << n << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
long long power(long long x, long long y) {
  long long p = 1e9 + 7;
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
