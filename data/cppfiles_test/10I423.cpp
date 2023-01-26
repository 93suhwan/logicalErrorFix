#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> make_pair;
    for (int i = 0; i < n; i++) {
      make_pair[arr[i]].push_back(i);
      freq[arr[i]]++;
    }
    int curr = 0;
    for (auto i : freq) {
      curr += min(i.second, k);
    }
    int ans = curr / k;
    cout << ans << "\n";
    int ret[n];
    memset(ret, 0, sizeof(ret));
    int cols = 1;
    int tcount = 0;
    for (auto i : make_pair) {
      int count = 0;
      for (auto j : i.second) {
        count++;
        tcount++;
        ret[j] = cols;
        cols++;
        if (cols == k + 1) cols = 1;
        if (count >= k) break;
        if (tcount >= k * ans) break;
      }
      if (tcount >= k * ans) break;
    }
    for (int i = 0; i < n; i++) {
      cout << ret[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
