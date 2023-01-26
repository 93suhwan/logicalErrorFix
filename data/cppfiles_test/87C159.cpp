#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      res = max(a - i, res);
    }
    cout << res << endl;
  }
}
