#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
long long mx = 1e9;
void generate() {
  set<long long> s;
  long long x = 1;
  while (true) {
    if (x * x > mx) break;
    s.insert(x * x);
    x++;
  }
  x = 1;
  while (true) {
    if (x * x * x > mx) break;
    s.insert(x * x * x);
    x++;
  }
  for (long long i : s) v.push_back(i);
}
void solve() {
  long long n;
  cin >> n;
  cout << upper_bound(v.begin(), v.end(), n) - v.begin();
}
signed main() {
  generate();
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
    cout << '\n';
  }
}
