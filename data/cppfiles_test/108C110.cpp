#include <bits/stdc++.h>
using namespace std;
int T;
pair<int, int> a[100001], b[100001];
int c[100001];
bool d[100001];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    memset(d, 0, sizeof(d));
    int n, val;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> val;
      a[i] = {val, i};
    }
    for (int i = 0; i < n; ++i) {
      cin >> val;
      b[i] = {val, i};
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; ++i) c[b[i].second] = i;
    int mn = n;
    for (int i = n - 1; i >= 0; i--) {
      mn = min(mn, c[a[i].second]);
      d[a[i].second] = 1;
      if (i == mn) {
        for (int j = 0; j < n; ++j) cout << d[j];
        cout << '\n';
        break;
      }
    }
  }
}
