#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long sol = 0;
    vector<int> a(n);
    int contn = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = x;
      if (x <= 0) contn++;
    }
    vector<int> s;
    sort(a.begin(), a.end());
    for (int i = 0; i < contn;) {
      int M = 0;
      for (int x = 0; x < k; x++) {
        M = min(M, a[i]);
        i++;
        if (i == contn) x = k;
      }
      s.push_back(-1 * M);
    }
    for (int i = n - 1; i >= contn;) {
      int M = 0;
      for (int x = 0; x < k; x++) {
        M = max(M, a[i]);
        i--;
        if (i == contn - 1) x = k;
      }
      s.push_back(M);
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size() - 1; i++) {
      sol += s[i] * 2;
    }
    sol += s[s.size() - 1];
    cout << sol << "\n";
  }
}
