#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 1e9, MAX = 4000001, MOD = 1000000007;
int t, n, k, ans[200001];
vector<int> cnt[200001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int sum = 0;
    fill(ans, ans + n + 1, 0);
    for (int i = 0; i < n + 1; i++) cnt[i].clear();
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (cnt[a].size() < k) cnt[a].push_back(i);
    }
    int curr = 1, aa = 0;
    for (int i = 1; i <= n; i++) {
      aa += cnt[i].size();
    }
    aa -= aa % k;
    for (int i = 1; i <= n; i++) {
      int s = min(k, (int)cnt[i].size());
      for (int j = 0; j < s; j++) {
        ans[cnt[i][j]] = curr;
        curr = curr % k + 1;
        aa--;
        if (aa == 0) break;
      }
      if (aa == 0) break;
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
