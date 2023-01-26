#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int M = 5e5 + 5;
const int INF = 2e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, t, i, j, k, index;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<long long int, long long int>> v(n);
    for (i = 0; i < n; i++) {
      cin >> v[i].first;
      v[i].second = i + 1;
    }
    long long int flag = 0;
    for (i = 0; i < n; i++) {
      if (v[i].first == 0) {
        flag = 1;
      }
    }
    if (flag == 0) {
      cout << n + 1 << " ";
      for (i = 0; i < n; i++) {
        cout << v[i].second << " ";
      }
      cout << '\n';
      continue;
    }
    flag = 0;
    if (v[n - 1].first == 0) {
      for (i = 0; i < n; i++) {
        cout << v[i].second << " ";
      }
      cout << n + 1 << '\n';
      continue;
    }
    for (i = 0; i < n; i++) {
      if (v[i].first == 0) {
        index = i;
        break;
      }
    }
    for (i = index; i < n; i++) {
      if (v[i].first == 1) {
        index = i;
        break;
      }
    }
    for (i = 0; i < index; i++) {
      cout << v[i].second << " ";
    }
    cout << n + 1 << " ";
    for (i = index; i < n; i++) {
      cout << v[i].second << " ";
    }
    cout << '\n';
  }
}
