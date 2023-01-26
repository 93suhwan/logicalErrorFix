#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = LLONG_MAX;
const long long NINF = LLONG_MIN;
void solve() {
  long long num, k;
  cin >> num >> k;
  vector<long long> d;
  while (num) {
    d.push_back(num % 10);
    num /= 10;
  }
  reverse(d.begin(), d.end());
  long long n = d.size();
  while (1) {
    set<long long> s;
    long long in;
    for (long long i = 0; i < n; i++) {
      s.insert(d[i]);
      if (s.size() > k) {
        in = i;
        break;
      }
    }
    if (s.size() <= k) break;
    while (d[in] == 9) in--;
    d[in]++;
    for (long long i = in + 1; i < n; i++) d[i] = 0;
  }
  for (long long i = 0; i < n; i++) cout << d[i];
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
}
