#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t) {
    int n, k;
    cin >> n >> k;
    int m = n - k;
    int sum = (m * (m - 1)) / 2;
    pair<int, int> p[k];
    for (int x = 0; x < k; x++) {
      int a, b;
      cin >> a >> b;
      p[x].first = min(a, b);
      p[x].second = max(a, b);
    }
    sort(p, p + k);
    for (int x = 0; x < k; x++) {
      int a = p[x].second - p[x].first - 1,
          b = p[x].first + 2 * n - p[x].second - 1;
      for (int y = 0; y < x; y++) {
        if (p[y].second < p[x].second && p[y].second > p[x].first) {
          a--;
          b--;
        } else {
          b -= 2;
        }
      }
      for (int y = x + 1; y < k; y++) {
        if (p[y].first < p[x].second) {
          if (p[y].second > p[x].second) {
            sum++;
            a--;
            b--;
          } else {
            a -= 2;
          }
        } else {
          b -= 2;
        }
      }
      cout << a << b << endl;
      sum += min(a, b);
    }
    cout << sum << endl;
    t--;
  }
}
