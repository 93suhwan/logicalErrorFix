#include <bits/stdc++.h>
using namespace std;
int n, t, k;
int const N = 2e5;
pair<long long, long long> p[N];
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
    for (int i = 1; i < n; i++) {
      if (p[i - 1].second + 1 != p[i].second) cnt++;
    }
    if (cnt <= k)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
