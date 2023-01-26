#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int ttt;
  cin >> ttt;
  while (ttt--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (n % m == 0) {
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j) {
          cout << n / m;
          for (int o = 0; o < n / m; ++o) {
            cout << " " << 1 + j * (n / m) + o;
          }
          cout << "\n";
        }
      }
    }
    int t = 0;
    for (int i = 0; i < k; ++i) {
      set<int> did;
      cout << n / m + 1;
      for (int o = 0; o < n / m + 1; ++o) {
        cout << " " << 1 + t;
        did.insert(t);
        t = (t + 1) % n;
      }
      cout << "\n";
      for (int j = 1; j < m; ++j) {
        cout << n / m;
        int oo = 0;
        for (int o = 0; o < n / m; ++o) {
          while (did.count(oo)) {
            oo++;
          }
          cout << " " << 1 + oo;
          oo++;
        }
        cout << "\n";
      }
    }
  }
}
