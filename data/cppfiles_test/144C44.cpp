#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      a.push_back(i + 1);
    }
    int up = n / m + (n % m != 0);
    int down = n / m;
    for (int i = 0; i < k; i++) {
      int cnt = 0;
      for (int j = 0; j < m; j++) {
        if (j < n % m) {
          cout << up << " ";
          for (int l = 0; l < up; l++) {
            cout << a[cnt++] << " ";
          }
          cout << endl;
        } else {
          cout << down << " ";
          for (int l = 0; l < down; l++) {
            cout << a[cnt++] << " ";
          }
          cout << endl;
        }
      }
      rotate(a.begin(), a.begin() + up * (n % m), a.end());
      cout << endl;
    }
  }
  return 0;
}
