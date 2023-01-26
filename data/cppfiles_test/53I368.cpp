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
    set<long long> s;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (s.find(a[i]) == s.end()) b.push_back(a[i]);
      s.insert(a[i]);
    }
    sort(b.begin(), b.end());
    int idx = -2, cnt = 0;
    for (int i = 0; i < n; i++) {
      auto k = lower_bound(b.begin(), b.end(), a[i]);
      if (k - b.end() != idx + 1 && k - b.end() != idx) cnt++;
      idx = k - b.end();
    }
    if (k >= cnt)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
