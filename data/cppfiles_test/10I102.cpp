#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[a[i]]++;
    for (int i = 0; i < n; i++) {
      if (k < mp[a[i]])
        cout << "0 ";
      else if (0 < mp[a[i]] && mp[a[i]] <= k)
        cout << mp[a[i]] << " ";
      mp[a[i]]--;
    }
    cout << "\n";
  }
  return 0;
}
