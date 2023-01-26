#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << ' ' << H;
  debug_out(T...);
}
template <class T>
ostream &operator<<(ostream &io, vector<T> a) {
  io << "{";
  for (auto I : a) io << I << " ";
  io << "}";
  return io;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long &x : a) cin >> x;
    sort((a).begin(), (a).end());
    long long sum = 0;
    for (auto e : a) sum += e;
    long long ans = max(0ll, sum - k), tmp = 0, t = 0;
    for (int i = n - 1; i >= 1; i--) {
      tmp += a[i] - a[0];
      t++;
      long long left = sum - tmp - k;
      long long x = 0;
      if (left > 0) {
        x = (left + t) / (t + 1);
      }
      ans = min(ans, x + t);
    }
    cout << ans << '\n';
  }
  return 0;
}
