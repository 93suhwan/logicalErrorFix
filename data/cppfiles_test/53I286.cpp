#include <bits/stdc++.h>
using namespace std;
int n, t, k;
int const N = 2e5;
pair<int, int> p[N];
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> p[i].first;
      p[i].second = i;
    }
    sort(p, p + n);
    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
      if (p[i].second > p[i + 1].second) cnt++;
    }
    if (cnt <= k)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
