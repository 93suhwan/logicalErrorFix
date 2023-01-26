#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
long long dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
char dir[] = {'U', 'R', 'D', 'L'};
void solve() {
  long long n, sum = 0, val = 0;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  val = (n * (n + 1)) / 2;
  if (sum % val or sum / val < n) {
    cout << "NO";
  } else {
    long long xx = 0;
    vector<long long> ans(n);
    sum /= val;
    for (long long i = 1; i < n; i++) {
      long long t = sum - v[i] + v[i - 1];
      if (t % n or t < 1) {
        cout << "NO";
        return;
      } else {
        ans[i] = t / n;
        xx += ans[i];
      }
    }
    if (sum - xx < 1) {
      cout << "NO";
      return;
    } else {
      cout << "YES"
           << "\n";
      ans[0] = sum - xx;
      for (long long i = 0; i < n; i++) {
        cout << ans[i] << " ";
      }
    }
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q = 1;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
