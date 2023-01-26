#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int ans = 0;
    for (char c : {'a', 'b', 'c', 'd', 'e'}) {
      vector<int> x;
      for (const string& s : a) {
        int cnt1 = count(s.begin(), s.end(), c);
        int cnt2 = (int)s.size() - cnt1;
        x.push_back(cnt1 - cnt2);
      }
      sort(x.rbegin(), x.rend());
      int sum = 0;
      for (int i = 0; i < (int)x.size(); ++i) {
        sum += x[i];
        if (sum <= 0) break;
        ans = max(ans, i + 1);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
