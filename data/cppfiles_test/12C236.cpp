#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
vector<T> make_unique(vector<T> a) {
  sort((a).begin(), (a).end());
  a.erase(unique((a).begin(), (a).end()), a.end());
  return a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, hor, ver;
    cin >> n >> m >> hor;
    ver = n * m / 2 - hor;
    if (n % 2) {
      swap(n, m);
      swap(hor, ver);
    }
    bool ans = hor <= m / 2 * n && ver <= n / 2 * m && hor % 2 == 0;
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}
