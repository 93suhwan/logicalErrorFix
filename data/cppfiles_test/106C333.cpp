#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long sum(long long n) { return (n * (n + 1)) / 2.0; }
long long len(string str) { return str.length(); }
long long fact(long long n) {
  if (n > 0)
    return n * fact(n - 1);
  else
    return 1;
}
void solve(void);
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, b % a);
}
bool sortbysec(const pair<string, int> &a, const pair<string, int> &b) {
  return (a.second > b.second);
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << (i + 2) << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1, i = 1;
  cin >> test;
  while (test--) {
    solve();
    cout << '\n';
  }
}
