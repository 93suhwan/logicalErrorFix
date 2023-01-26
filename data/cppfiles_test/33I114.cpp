#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  unordered_map<long long, long long> umap;
  long long vis[512];
  for (long long i = 0; i < 512; i++) vis[i] = 0;
  vis[0] = 1;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  for (long long i = n - 1; i >= 0; i--) {
    umap[arr[i]] = max(umap[arr[i]], arr[i]);
    vis[arr[i]] = 1;
    for (auto it : umap) {
      if (arr[i] < (umap[it.first])) {
        vis[arr[i] ^ (it.first)] = 1;
        umap[arr[i] ^ (it.first)] = max(umap[arr[i] ^ (it.first)], arr[i]);
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i < 512; i++) {
    if (vis[i] == 1) ans++;
  }
  cout << ans << "\n";
  for (long long i = 0; i < 512; i++) {
    if (vis[i]) cout << i << " ";
  }
  return 0;
}
