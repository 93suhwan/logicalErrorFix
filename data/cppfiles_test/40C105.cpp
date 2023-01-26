#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long th;
  cin >> th;
  while (th--) {
    long long m;
    cin >> m;
    vector<long long> a(m);
    vector<long long> b(m);
    vector<long long> res;
    long long sumt = 0;
    long long sumd = 0;
    for (long long i = 0; i < m; i++) {
      cin >> a[i];
      if (i != 0) sumt += a[i];
    }
    for (long long i = 0; i < m; i++) cin >> b[i];
    res.push_back(max(sumt, sumd));
    for (long long i = 1; i < m; i++) {
      sumt -= a[i];
      sumd += b[i - 1];
      res.push_back(max(sumt, sumd));
    }
    sort(res.begin(), res.end());
    cout << res[0];
    cout << "\n";
  }
  return 0;
}
