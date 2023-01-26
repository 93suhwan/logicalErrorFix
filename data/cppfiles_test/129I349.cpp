#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int test_case, n;
  cin >> test_case;
  while (test_case--) {
    cin >> n;
    long long int ar[n], i, c = 0, b, j = 0;
    vector<long long int> w;
    vector<pair<long long int, long long int>> v;
    map<long long int, long long int> m, p;
    for (i = 0; i < n; i++) {
      cin >> ar[i];
      m[ar[i]] = 1;
    }
    sort(ar, ar + n);
    for (i = 1; i <= n; i++) {
      p[i] = 1;
      if (m[i] == 0) {
        w.push_back(i);
      }
    }
    for (i = 0; i < n; i++) {
      if (p[ar[i]] == 0) {
        v.push_back({ar[i], w[j]});
        j++;
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
