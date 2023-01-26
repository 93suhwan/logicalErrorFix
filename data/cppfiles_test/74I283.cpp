#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;
    if (m < n) {
      int t = m;
      m = n;
      n = t;
    }
    int tot = m + n;
    vector<int> ans(tot + 1);
    for (int i = 0; i < tot + 1; i++) {
      ans[i] = i;
    }
    if (tot % 2 == 1) {
      int dif = m - n;
      dif--;
      dif = dif / 2;
      vector<int> fin;
      for (int i = dif; i <= tot - dif; i++) {
        fin.push_back(i);
      }
      cout << fin.size() << "\n";
      for (auto i : fin) {
        cout << i << " ";
      }
      cout << "\n";
    } else {
      int dif = m - n;
      dif = dif / 2;
      if (dif == 0) {
        cout << 2 << "\n";
        cout << 0 << " " << tot << "\n";
      } else {
        vector<int> fin;
        int c = 0;
        for (int i = dif; i <= tot - dif; i += 2) {
          c++;
          fin.push_back(i);
        }
        cout << c << "\n";
        for (auto i : fin) {
          cout << i << " ";
        }
        cout << "\n";
      }
    }
  }
}
