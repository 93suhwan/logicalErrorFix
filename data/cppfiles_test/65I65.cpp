#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(int a, int b, const vector<ll>& as, const string& tar) {
  int k = b - a + 1;
  if (k & 1) {
    solve(a, b - 1, as, tar);
    cout << as[b] << ' ' << tar[k - 1] << endl;
  } else if (k > 0) {
    char pre = (k == 2 ? '?' : tar[k - 3]);
    char cur = tar[k - 2];
    char nxt = tar[k - 1];
    char oth = cur ^ ('L' ^ 'R');
    if (cur != pre && nxt != pre) {
      solve(a + 1, b - 1, as, tar);
      cout << as[b] << ' ' << cur << endl;
      cout << as[a] << ' ' << oth << endl;
    } else if (cur == pre && nxt != pre) {
      solve(a + 1, b - 1, as, tar);
      cout << as[a] << ' ' << cur << endl;
      cout << as[b] << ' ' << oth << endl;
    } else if (cur != pre && nxt == pre) {
      solve(a, b - 2, as, tar);
      cout << as[b - 1] << ' ' << cur << endl;
      cout << as[b] << ' ' << nxt << endl;
    } else if (cur == pre && nxt == pre) {
      solve(a, b - 2, as, tar);
      cout << as[b] << ' ' << cur << endl;
      cout << as[b - 1] << ' ' << nxt << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> as(n);
  for (ll& a : as) cin >> a;
  sort(as.begin(), as.end());
  string tar;
  cin >> tar;
  solve(0, n - 1, as, tar);
}
