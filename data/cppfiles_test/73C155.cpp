#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    vector<int> p = v;
    sort(p.begin(), p.end());
    int i = 0;
    while (p != v) {
      i++;
      if (i % 2 != 0) {
        for (int i = 0; i < n - 1; i += 2) {
          if (v[i] > v[i + 1]) swap(v[i], v[i + 1]);
        }
      } else {
        for (int i = 1; i < n - 1; i += 2) {
          if (v[i] > v[i + 1]) swap(v[i], v[i + 1]);
        }
      }
    }
    cout << i << endl;
  }
}
