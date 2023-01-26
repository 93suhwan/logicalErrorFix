#include <bits/stdc++.h>
using namespace std;
int main() {
  cout.precision(15);
  cout << fixed;
  long long t;
  cin >> t;
  while (t-- > 0) {
    long long n, k;
    cin >> n >> k;
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
      int cur;
      cin >> cur;
      ve.push_back({cur, i});
    }
    sort(ve.begin(), ve.end());
    int cnts = 0;
    for (int i = 0; i < n; i++) {
      cnts++;
      int val = ve[i].second;
      while (ve[i + 1].second == val + 1) {
        i++;
        val++;
      }
    }
    if (cnts <= k && k <= n)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
