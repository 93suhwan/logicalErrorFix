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
    long long l = 0, r = 1e12;
    const long long inf = 1e18;
    auto cost = [&](long long x) {
      vector<long long> b(a);
      long long sum = accumulate((b).begin(), (b).end(), 0);
      b[0] -= x;
      sum -= x;
      long long need = x;
      if (sum <= k) return need;
      for (int i = n - 1; i >= 1; i--) {
        sum -= (b[i] - b[0]);
        need++;
        if (sum <= k) return need;
      }
      return inf - x;
    };
    while (l < r) {
      long long m = l + r + 1 >> 1;
      if (cost(m) < cost(m - 1))
        l = m;
      else
        r = m - 1;
    }
    cout << cost(l) << '\n';
  }
  return 0;
}
