#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  set<int, greater<int> >::iterator itr;
  cin >> t;
  while (t--) {
    int n, k;
    set<int> s;
    cin >> n >> k;
    vector<int> ar(2 * n, -1);
    int ans = 0;
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      s.clear();
      for (int j = min(x, y) - 1; j < max(x, y); j++) {
        if (ar[j] != -1) {
          if (s.count(ar[j]))
            s.erase(ar[j]);
          else
            s.insert(ar[j]);
        }
      }
      ar[x - 1] = ar[y - 1] = i;
      ans += s.size();
    }
    for (int i = 0; i < 2 * n; i++) {
      if (k == n) break;
      if (ar[i] != -1) continue;
      s.clear();
      int max_el = -1, max_count = 0, non_line_elem = 0,
          specific_non_line_elem = 0;
      for (int j = i + 1; j < 2 * n; j++) {
        if (ar[j] != -1) {
          if (s.count(ar[j]))
            s.erase(ar[j]);
          else
            s.insert(ar[j]);
        } else {
          if (max_el == -1) {
            max_el = j;
            max_count = s.size();
            specific_non_line_elem = non_line_elem;
          } else if (max_count < s.size()) {
            max_el = j;
            max_count = s.size();
            specific_non_line_elem = non_line_elem;
          } else if (max_count == s.size() &&
                     abs((n - k - 1) - specific_non_line_elem) >
                         abs((n - k - 1) - non_line_elem)) {
            max_el = j;
            max_count = s.size();
            specific_non_line_elem = non_line_elem;
          }
          non_line_elem++;
        }
      }
      ar[i] = ar[max_el] = k;
      k++;
      ans += max_count;
    }
    cout << ans << "\n";
  }
  return 0;
}
