#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
vector<T> make_unique(vector<T> a) {
  sort((a).begin(), (a).end());
  a.erase(unique((a).begin(), (a).end()), a.end());
  return a;
}
const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < (int)(n); i++) cin >> a[i], a[i]--;
    vector<int> lis(n);
    int ans = INF;
    for (int i = 0; i < (int)(n); i++)
      if (a[i] <= i) {
        for (int j = 0; j < (int)(i); j++)
          if (a[i] > a[j] && i - a[i] >= j - a[j]) lis[i] = max(lis[i], lis[j]);
        ++lis[i];
        if (lis[i] >= k) ans = min(ans, i - a[i]);
      }
    if (ans >= INF) ans = -1;
    cout << ans << endl;
  }
  return 0;
}
