#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> m >> n;
    vector<vector<int> > p(m, vector<int>(n, 0));
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) cin >> p[i][j];
    }
    vector<int> max_fr(n, 0), max2(m, 0);
    for (long long j = 0; j < n; j++) {
      int mx = 0;
      for (long long i = 0; i < m; i++) {
        mx = max(mx, p[i][j]);
      }
      max_fr[j] = mx;
    }
    for (long long i = 0; i < m; i++) {
      int m1 = 0, m2 = 0;
      for (long long j = 0; j < n; j++) {
        if (p[i][j] > m1) {
          m2 = m1;
          m1 = p[i][j];
        } else if (p[i][j] > m2)
          m2 = p[i][j];
      }
      max2[i] = m2;
    }
    cout << min(*max_element(max2.begin(), max2.end()),
                *min_element(max_fr.begin(), max_fr.end()))
         << endl;
  }
}
