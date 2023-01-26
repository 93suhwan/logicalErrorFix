#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    string s;
    cin >> s;
    vector<pair<int, int>> one, zero;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        one.push_back({p[i], i});
      } else {
        zero.push_back({p[i], i});
      }
    }
    sort(one.begin(), one.end(), greater<pair<int, int>>());
    sort(zero.begin(), zero.end(), greater<pair<int, int>>());
    int q[n];
    int v = n;
    for (auto i : one) {
      q[i.second] = v;
      v--;
    }
    for (auto i : zero) {
      q[i.second] = v;
      v--;
    }
    for (int i = 0; i < n; i++) {
      cout << q[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
