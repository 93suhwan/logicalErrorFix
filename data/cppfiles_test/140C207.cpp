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
vector<long long int> prime;
void solve() {
  long long int mid, i, j, k, l, m, n,
      ans = 0, minn = INT_MAX, maxx = INT_MIN, x, sum = 0, c = 0, cc = 0,
      odd = 0, even = 0, q, ab = 0, ba = 0, y, a, b, r, nn, xx;
  string ss;
  vector<long long int> v, vv;
  set<long long int> s;
  map<long long int, long long int> mp;
  cin >> n;
  for (i = 1; i <= sqrt(n); i++) {
    if (i * i <= n) {
      s.insert(i * i);
    }
    if (i * i * i <= n) {
      s.insert(i * i * i);
      continue;
    }
  }
  cout << s.size() << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
