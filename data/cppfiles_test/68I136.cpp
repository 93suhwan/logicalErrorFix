#include <bits/stdc++.h>
const int N = 1e5;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
void solve() {
  long long int a;
  cin >> a;
  long long int sq = sqrtl(a);
  long long int baki = a - sq * sq;
  if (baki <= sq) {
    cout << baki << ' ' << sq + 1 << endl;
    return;
  }
  baki -= sq;
  cout << sq + 1 << ' ' << sq + 1 - baki + 1 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
