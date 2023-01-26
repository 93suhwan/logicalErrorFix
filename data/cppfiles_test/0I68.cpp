#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int t, n, m;
pair<string, int> a[N];
bool check(pair<string, int> a, pair<string, int> b) {
  for (int i = 0; i <= m - 1; ++i)
    if ((i & 1 && a.first[i] < b.first[i]) ||
        (!(i & 1) && a.first[i] > b.first[i]))
      return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i <= n - 1; ++i) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a, a + n, check);
  for (int i = 0; i <= n - 1; ++i) cout << a[i].second << " ";
}
