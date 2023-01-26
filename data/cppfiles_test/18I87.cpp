#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> pos(2 * n + 1, 0), sum(2 * n + 1, 0);
    set<int> st;
    for (int i = 1; i <= k; i++) {
      int a, b;
      cin >> a >> b;
      if (a > b) swap(a, b);
      pos[a] = b;
      pos[b] = a;
    }
    vector<int> as;
    for (int tt = 0; tt < 50; tt++) {
      as.clear();
      for (int i = 1; i <= 2 * n; i++) {
        if (!pos[i]) as.push_back(i);
      }
      if (!as.size()) break;
      sort(as.begin(), as.end());
      int a = as[0];
      int b = as[as.size() / 2];
      pos[a] = b;
      pos[b] = a;
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
      int a = min(i, pos[i]), b = max(i, pos[i]);
      for (int j = a + 1; j < b; j++) {
        if (pos[j] > b || pos[j] < a) {
          ans++;
        }
      }
    }
    cout << ans / 4 << endl;
  }
  return 0;
}
