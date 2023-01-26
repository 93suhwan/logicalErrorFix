#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
int minSwapsToSort(vector<int> arr, int n) {
  pair<int, int> arrPos[n];
  for (int i = 0; i < n; i++) {
    arrPos[i].first = arr[i];
    arrPos[i].second = i;
  }
  sort(arrPos, arrPos + n);
  vector<bool> vis(n, false);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] || arrPos[i].second == i) continue;
    int cycle_size = 0;
    int j = i;
    while (!vis[j]) {
      vis[j] = 1;
      j = arrPos[j].second;
      cycle_size++;
    }
    ans += (cycle_size - 1);
  }
  return ans;
}
int minSwapToMakeArraySame(vector<int> a, vector<int> b, int n) {
  map<int, int> mp;
  for (int i = 0; i < n; i++) mp[b[i]] = i;
  for (int i = 0; i < n; i++) b[i] = mp[a[i]];
  return minSwapsToSort(b, n);
}
bool check(int sft) {
  vector<int> b;
  for (int i = n - sft + 1; i <= n; i++) b.push_back(i);
  for (int i = 1; i <= n - sft; i++) b.push_back(i);
  if (minSwapToMakeArraySame(a, b, n) <= k) return true;
  return false;
}
void solve() {
  cin >> n >> k;
  a.resize(n);
  int freq[n];
  memset(freq, 0, sizeof(freq));
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
    int idx = (i - a[i] + 1 + n) % n;
    freq[idx]++;
  }
  vector<int> ans;
  for (int i = 0; i < (n); i++) {
    if (n - freq[i] <= 2 * k) {
      if (check(i)) ans.push_back(i);
    }
  }
  cout << ans.size() << " ";
  for (auto i : ans) cout << i << " ";
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
