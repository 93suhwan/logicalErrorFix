#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k, res = 0, l = 0;
    cin >> n >> k;
    vector<int> v(n);
    unordered_map<int, int> m, s;
    for (int p = 0; p < n; p++) {
      cin >> v[p];
      m[v[p]]++;
    }
    for (auto j : m) {
      if (j.second >= k) {
        s[j.first] = 1;
        m[j.first] = k;
      }
    }
    int r = 1;
    for (int p = 0; p < n; p++) {
      if (s[v[p]] == 1) {
        if (m[v[p]] > 0) {
          cout << m[v[p]] << " ";
          m[v[p]]--;
        } else
          cout << "0"
               << " ";
      } else {
        cout << r << " ";
        m[v[p]]--;
        if ((r + 1) % k == 0)
          r = 1;
        else
          r = (r + 1) % k;
      }
    }
    cout << endl;
  }
  return 0;
}
