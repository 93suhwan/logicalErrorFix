#include <bits/stdc++.h>
using namespace std;
template <class T, class G>
bool chkMax(T &x, G y) {
  return y > x ? x = y, 1 : 0;
}
template <class T, class G>
bool chkMin(T &x, G y) {
  return y < x ? x = y, 1 : 0;
}
const int N = 2e5 + 5;
long long n, m;
long long v[N][2];
long long Ans[N][2];
pair<int, int> f[N];
void solve() {
  cin >> n >> m;
  long long suma = 0, sumb = 0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i][0] >> v[i][1];
    long long x = min(v[i][0], m);
    suma += v[i][0] - x;
    sumb += v[i][1] - m + x;
    f[i] = {x, v[i][1] - m + x};
  }
  if (suma > sumb) {
    cout << suma - sumb << "\n";
    for (int i = 0; i < n; ++i) {
      long long x = min(v[i][0], m);
      cout << x << " " << m + x << "\n";
    }
    return;
  }
  long long add = sumb - suma;
  for (int i = 0; i < n; ++i) {
    int x = min(1ll * min(f[i].first, f[i].second), add / 2);
    f[i].first -= x;
    add -= x * 2;
  }
  cout << add << "\n";
  for (int i = 0; i < n; ++i) {
    cout << f[i].first << " " << m - f[i].first << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int Case;
  cin >> Case;
  while (Case--) solve();
  return 0;
}
