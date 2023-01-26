#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    string s;
    cin >> s;
    int zero = 1;
    int one = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        one++;
      }
    }
    one++;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      int p = v[i].second;
      if (s[p] == '0') {
        a[p] = zero;
        ;
        zero++;
      } else {
        a[p] = one;
        one++;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
