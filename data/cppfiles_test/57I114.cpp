#include <bits/stdc++.h>
using namespace std;
void swap_h(int i, int val, vector<int> &a, vector<int> &v) {
  if (a[i] == val) return;
  for (int j = i + 1; j < a.size(); j++) {
    if (a[j] == val) {
      v.push_back(i + 1);
      v.push_back(j + 1);
      v.push_back(i + 1);
      swap(a[i], a[j]);
      return;
    }
  }
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b = a, c = a;
    sort(b.begin(), b.end());
    sort(c.rbegin(), c.rend());
    bool in = true, de = true;
    for (int i = 0; i < n; i++) {
      if (i % 2) {
        if (b[i] != a[i]) in = false;
        if (c[i] != a[i]) de = false;
      }
    }
    if (!in && !de) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> v;
    if (in) {
      for (int i = 0; i < n; i++) swap_h(i, i + 1, a, v);
    } else if (de) {
      v.push_back(n);
      reverse(a.begin(), a.end());
      for (int i = 0; i < n; i++) swap_h(i, i + 1, a, v);
    }
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    if (v.size() != 0) cout << '\n';
  }
}
