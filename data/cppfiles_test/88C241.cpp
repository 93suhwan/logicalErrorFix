#include <bits/stdc++.h>
using namespace std;
pair<int, int> h[100001];
int n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie();
  int t;
  cin >> t;
  while (t--) {
    int res = 0;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
      cin >> h[i].first;
      h[i].second = i;
    }
    sort(h, h + n * m);
    for (int i = 0; i < n; i++) {
      for (int j = i * m; j < i * m + m; j++) {
        for (int k = j + 1; k < i * m + m; k++) {
          if (h[j].second < h[k].second && h[j].first < h[k].first) res++;
        }
      }
    }
    cout << res << "\n";
  }
}
