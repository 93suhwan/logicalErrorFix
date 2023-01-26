#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
const int MAXN = 1e5 + 10;
int T = 1, n, a[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    int cnt = 1;
    bool b = true;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] == 1) {
        cnt++;
        if (i > 1 && a[i] == a[i - 1]) cnt += 4;
      } else {
        if (i > 1 && a[i] == a[i - 1]) b = false;
      }
    }
    cout << (b ? cnt : -1) << "\n";
  }
}
