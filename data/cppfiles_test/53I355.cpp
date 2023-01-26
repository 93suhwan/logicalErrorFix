#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while ((t--)) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    m.clear();
    stable_sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) m[b[i]] = i + 1;
    int i;
    int cnt = 0;
    k--;
    for (i = 1; i < n; i++) {
      if (a[i - 1] <= a[i]) {
        if ((m[a[i]] - m[a[i - 1]]) != 1) {
          cout << "No\n";
          break;
        }
        cnt++;
      } else {
        k--;
        if (k < 0) {
          cout << "No\n";
          break;
        }
      }
    }
    if (i >= n) {
      if (cnt >= k)
        cout << "Yes\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
