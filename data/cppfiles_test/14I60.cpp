#include <bits/stdc++.h>
using namespace std;
const int P = 13331;
const int N = 50, M = 2 * N, MOD = 998244353;
int a[N];
int n;
vector<pair<int, int> > b;
void bubble_sort() {
  b.clear();
  for (int i = 1; i < n; i++) {
    for (int j = n; j > i; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        b.push_back({j - 1, j});
      }
    }
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  bubble_sort();
  cout << b.size() << '\n';
  for (int i = 0; i < b.size(); i++)
    cout << b[i].first << " " << b[i].second << " " << 1 << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
