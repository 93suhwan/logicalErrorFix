#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int test_case, n;
  cin >> test_case;
  while (test_case--) {
    cin >> n;
    long long int ar[n + 1], i, c = 0, b;
    ar[0] = 0;
    vector<pair<long long int, long long int>> v;
    for (i = 1; i <= n; i++) {
      cin >> ar[i];
    }
    sort(ar, ar + n + 1);
    for (i = 1; i <= n; i++) {
      if (ar[i] != i) {
        v.push_back({ar[i], i});
      }
    }
    for (i = 0; i < v.size(); i++) {
      b = v[i].first - v[i].second;
      if (b <= v[i].second) {
        c = 1;
        break;
      }
    }
    if (c) {
      cout << "-1" << endl;
    } else {
      cout << v.size() << endl;
    }
  }
}
