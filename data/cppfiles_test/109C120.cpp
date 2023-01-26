#include <bits/stdc++.h>
using namespace std;
long long multi(long long a, long long b, long long mod) {
  return (a * b) % mod;
}
long long power(long long a, long long b, long long mod) {
  long long powans = 1;
  for (; b > 0; a = multi(a, a, mod), b /= 2)
    if (b % 2 == 1) powans = multi(powans, a, mod);
  return powans;
}
struct compare {
  bool operator()(const pair<int, int>& value, const int& key) {
    return (value.first < key);
  }
  bool operator()(const int& key, const pair<int, int>& value) {
    return (key < value.first);
  }
};
int gcd(int a, int b) {
  if (a == 0 || b == 0) return a ^ b;
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int sol = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      sum = sum + s[i] - '0';
    } else {
      if (s[i] != '0') sum = sum + s[i] - '0' + 1;
    }
  }
  cout << sum << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
