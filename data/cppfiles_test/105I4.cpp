#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), m(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i] >> m[i];
    }
    map<int, vector<int>> decomposition;
    for (int i = 0; i < n; ++i) {
      decomposition[a[i] + b[i] - m[i]].push_back(i);
    }
    int answer = n;
    vector<int> x(n);
    for (auto& now : decomposition) {
      sort(now.second.begin(), now.second.end(),
           [&](int i, int j) { return a[i] > a[j]; });
      int mi = a[now.second[0]] - m[now.second[0]];
      int last = 0;
      for (int i = 1; i < now.second.size(); ++i) {
        int ind = now.second[i];
        if (a[ind] < mi) {
          for (int j = last; j < i; ++j) {
            x[now.second[j]] = mi;
          }
          mi = a[ind] - m[ind];
        } else {
          --answer;
        }
        mi = max(mi, a[ind] - m[ind]);
      }
      for (int j = last; j < now.second.size(); ++j) {
        x[now.second[j]] = mi;
      }
    }
    cout << answer << '\n';
    for (int i = 0; i < n; ++i) {
      int res_left = max(x[i], 0);
      int res_right = a[i] + b[i] - m[i] - res_left;
      cout << a[i] - res_left << ' ' << b[i] - res_right << '\n';
    }
  }
  return 0;
}
