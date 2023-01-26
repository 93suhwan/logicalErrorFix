#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long rem, i, root, x, b, knapsack, y, l, c, u, even, odd,
      maxn = -1, mid, s, d, a, low, high, k, q, sum = 0, cnt = 0, n, p, m, r,
      ans = 0, j = -1, t, minn, len;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<pair<long long, long long>> vec;
    for (i = 1; i <= m; i++) {
      cin >> a;
      vec.push_back(make_pair(a, (-i)));
    }
    long long check[309] = {0};
    sum = 0;
    sort(vec.begin(), vec.end());
    for (i = 1; i <= m; i++) {
      for (j = 0; j < m; j++) {
        if (vec[j].second == (-i)) {
          for (k = 1; k <= j; k++)
            if (check[k] > 0) sum++;
          check[j + 1] = 1;
        }
      }
    }
    cout << sum;
    cout << "\n";
  }
  return 0;
}
