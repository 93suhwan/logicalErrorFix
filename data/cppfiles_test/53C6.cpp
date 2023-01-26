#include <bits/stdc++.h>
using namespace std;
long long a[100010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> b;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    map<int, int> mp;
    int idx = -2, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (idx + 1 == n || a[i] != b[idx + 1]) {
        auto k = lower_bound(b.begin(), b.end(), a[i]);
        idx = (k - b.begin()) + mp[a[i]];
        cnt++;
        mp[a[i]]++;
      } else {
        idx++;
      }
    }
    if (k >= cnt)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
