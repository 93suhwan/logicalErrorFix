#include <bits/stdc++.h>
using namespace std;
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main() {
  fast_io();
  int test;
  cin >> test;
  vector<vector<int> > pref(3e5, vector<int>(20));
  for (int i = 1; i <= 3e5; i++) {
    pref[i] = pref[i - 1];
    for (int j = 0; j < 20; j++) pref[i][j] += (i >> j) % 2;
  }
  for (int tc = 0; tc < test; tc++) {
    int l, r;
    cin >> l >> r;
    vector<int> bits = pref[r];
    for (int j = 0; j < 20; j++) bits[j] -= pref[l - 1][j];
    int best = 0;
    for (int j = 0; j < 20; j++) best = max(best, bits[j]);
    cout << r - l + 1 - best << "\n";
  }
}
