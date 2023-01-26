#include <bits/stdc++.h>
using namespace std;
template <class X>
void print_v(vector<X> A) {
  for (auto a : A) cout << a << " ";
  cout << "\n";
}
template <class X>
void scan_v(vector<X> &A, int n) {
  for (int i = 0; i < n; i++) cin >> A[i];
}
void test() {
  long long w, h;
  cin >> w >> h;
  long long x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long w1, h1;
  cin >> w1 >> h1;
  long long ans = INT_MAX;
  long long shift;
  shift = max(0ll, w1 - x1);
  if (x2 + shift <= w) ans = min(ans, shift);
  shift = max(0ll, w1 - w + x2);
  if (x1 - shift >= 0) ans = min(ans, shift);
  shift = h1 - y1;
  if (y2 + shift <= h) ans = min(ans, shift);
  shift = max(0ll, h1 - h + y2);
  if (y1 - shift >= 0) ans = min(ans, shift);
  if (ans != INT_MAX)
    cout << ans;
  else
    cout << -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    test();
    cout << "\n";
  }
  return 0;
}
