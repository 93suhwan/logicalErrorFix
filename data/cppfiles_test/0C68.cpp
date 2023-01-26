#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int t, n, m;
pair<string, int> a[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i <= n - 1; ++i) {
    cin >> a[i].first;
    for (int j = 0; j <= m - 1; ++j)
      if (j & 1) a[i].first[j] = char(155 - int(a[i].first[j]));
    a[i].second = i + 1;
  }
  sort(a, a + n);
  for (int i = 0; i <= n - 1; ++i) cout << a[i].second << " ";
}
