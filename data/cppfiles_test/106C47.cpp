#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, inf = 1e18;
const int N = 5e5 + 100;
void print(long long a) {
  cout << a;
  cout << endl;
  ;
}
void print(std::vector<long long> a) {
  for (auto i : a) cout << i << " ";
  cout << endl;
  ;
}
void print(string s) { cout << s << endl; }
void solve() {
  long long n;
  cin >> n;
  ;
  for (long long i = 2; i <= n + 1; i++) cout << i << " ";
  cout << endl;
  ;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
