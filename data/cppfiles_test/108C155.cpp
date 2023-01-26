#include <bits/stdc++.h>
using namespace std;
int INF = 1e9 + 5;
const long long int mod = 1e9 + 7;
const int N = 1e5 + 5;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), mxl(n + 2), mxr(n + 2), ans(n);
  vector<pair<pair<int, int>, int>> v;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    v.push_back(make_pair(make_pair(a[i], b[i]), i));
  }
  sort(v.begin(), v.end());
  mxl[0] = mxl[n + 1] = 0;
  int mini, maxi, minact;
  mini = maxi = minact = v[n - 1].first.second;
  for (int i = 0; i < n; i++) {
    mxl[i + 1] = max(mxl[i], v[i].first.second);
  }
  mxr[n + 1] = mxr[0] = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (v[i].first.second > maxi) {
      minact = mini;
      maxi = minact;
    }
    if (v[i].first.second < mini) {
      mini = v[i].first.second;
    }
    mxr[i + 1] = minact;
  }
  for (int i = 0; i < n; i++) {
    if (mxr[i + 2] < mxl[i + 1])
      ans[v[i].second] = 1;
    else
      ans[v[i].second] = 0;
  }
  for (int i = 0; i < n; i++) cout << ans[i];
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
