#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    map<int, int> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < 0) a[i] = -a[i];
      m[a[i]]++;
      if (m[a[i]] > 1) {
        cnt++;
      }
    }
    if (n == 1) {
      if (a[0])
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
      continue;
    }
    v.push_back(a[0]);
    for (int i = 1; i < n; i++) {
      int p = v.size();
      for (int j = 0; j < p; j++) {
        v.push_back(a[i] + v[j]);
        m[a[i] + v[j]]++;
        if (a[i] - v[j] > 0) {
          v.push_back(a[i] - v[j]);
          m[a[i] - v[j]]++;
        } else {
          v.push_back(v[j] - a[i]);
          m[-a[i] + v[j]]++;
        }
      }
    }
    int f = 0;
    for (int i = 0; i < n; i++) {
      if (m[a[i]] < 2) {
        f++;
      }
    }
    if (f > cnt) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
