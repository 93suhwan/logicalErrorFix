#include <bits/stdc++.h>
using namespace std;
bool f(long long len, vector<long long> &v, long long h) {
  for (int i = 0; i < v.size() - 1; i++) {
    if (v[i] + len >= v[i + 1]) {
      h -= (v[i + 1] - v[i]);
    } else {
      h -= len;
    }
    if (h <= 0) return true;
  }
  return false;
}
void solve() {
  int n;
  long long h;
  cin >> n >> h;
  vector<long long> v(n + 1, LONG_LONG_MAX);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long s = 1;
  long long e = 1e18;
  while (s != e) {
    long long mid = (s + e) / 2;
    if (f(mid, v, h) == true) {
      e = mid;
    } else {
      s = mid + 1;
    }
  }
  cout << s << '\n';
}
int main() {
  int t;
  cin >> t;
  for (int asd = 0; asd < t; asd++) {
    solve();
  }
}
