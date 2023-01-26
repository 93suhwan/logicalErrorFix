#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    map<int, int> pos;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      pos[arr[i]] = i;
    }
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      int req = (pos[i + 1] - i + n) % n;
      cnt[req]++;
    }
    vector<int> ans;
    for (auto var : cnt) {
      if (n - var.second <= m + 1) {
        ans.push_back(var.first);
      }
    }
    cout << ans.size() << " ";
    for (int nums : ans) cout << nums << " ";
    cout << "\n";
  }
  return 0;
}
