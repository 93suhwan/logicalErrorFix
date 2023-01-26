#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
vector<pair<int, int> > va, v1, v2;
int sum1, sum2;
vector<pair<int, int> > ans;
void solve() {
  sort(va.begin(), va.end());
  sum1 = sum2 = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (sum1 < sum2) {
      v1.push_back(va[i]);
      sum1 += va[i].first;
    } else {
      sum2 += va[i].first;
      v2.push_back(va[i]);
    }
  }
  int cnt = 0, i = 0, j = 0;
  while (true) {
    if (i >= v1.size() || j >= v2.size()) break;
    int mi = min(v1[i].first, v2[j].first);
    v1[i].first -= mi, v2[j].first -= mi;
    cnt += mi;
    for (int k = 0; k < mi; k++) ans.push_back({v1[i].second, v2[j].second});
    if (v1[i].first <= 0) i++;
    if (v2[j].first <= 0) j++;
  }
  cout << cnt << endl;
  for (int k = 0; k < cnt; k++) {
    auto &[a, b] = ans[k];
    cout << a << " " << b << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    va.clear();
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      va.push_back({a, i + 1});
    }
    solve();
  }
  return 0;
}
