#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long power(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) {
      res = (res * a) % M;
    }
    n >>= 1;
    a = (a * a) % M;
  }
  return res;
}
const int N = 1e5 + 5;
void solve() {
  float n;
  cin >> n;
  vector<float> a(n);
  float sum = 0;
  for (auto &x : a) {
    cin >> x;
    sum += x;
  }
  sort(a.begin(), a.end());
  cout << fixed << setprecision(9) << (sum - a[n - 1]) / (n - 1) + a[n - 1]
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
