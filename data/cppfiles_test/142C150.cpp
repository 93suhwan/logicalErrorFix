#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> a;
long long n, m;
bool poss(long long tar) {
  for (long long banda = 0; banda < m; banda++) {
    bool f = false;
    for (long long shop = 0; shop < n; shop++) {
      if (a[shop][banda] >= tar) {
        f = true;
        break;
      }
    }
    if (!f) return false;
  }
  bool f = false;
  for (long long i = 0; i < n; i++) {
    vector<long long> temp = a[i];
    sort(temp.begin(), temp.end());
    if (temp[temp.size() - 2] >= tar) {
      f = true;
      break;
    }
  }
  if (!f) return false;
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin.ignore();
    cin >> n >> m;
    a = vector<vector<long long>>(n, vector<long long>(m));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    long long s = 0;
    long long e = 1e18;
    long long ans;
    while (s <= e) {
      long long mid = (s + e) / 2;
      if (poss(mid)) {
        ans = mid;
        s = mid + 1;
      } else {
        e = mid - 1;
      }
    }
    cout << ans << "\n";
  }
}
