#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << ' ' << H;
  debug_out(T...);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long s, n, k;
    cin >> s >> n >> k;
    if (s == k)
      cout << "YES\n";
    else {
      long long tot = s / (2 * k) * k, r = s % (2 * k);
      if (r == k)
        r--;
      else
        r = min(r, k);
      if (tot + r >= n)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
  return 0;
}
