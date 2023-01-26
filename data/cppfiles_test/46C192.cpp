#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> b = v;
    sort(b.begin(), b.end());
    int m = b[n - 1];
    int x = v[n - 1];
    if (x == m) {
      cout << 0 << endl;
      continue;
    }
    bool check = true;
    int count = 0;
    int max = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (v[i] == m) {
        check = false;
        continue;
      }
      if (check) {
        if (v[i] > x and v[i] > max) {
          count++;
          max = v[i];
        }
      }
    }
    cout << count + 1 << endl;
  }
}
