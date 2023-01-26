#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if ((n % m) == 0) {
      for (int i = 0; i < k; i++) {
        int at = 0;
        for (int j = 0; j < m; j++) {
          cout << n / m << " ";
          for (int x = 0; x < n / m; x++) {
            cout << at + 1 << " ";
            at = at + 1;
          }
          cout << '\n';
        }
      }
      cout << '\n';
      continue;
    }
    vector<int> w(m);
    {
      int at = 0;
      for (int i = 0; i < n; i++) {
        w[at]++;
        at = (at + 1) % m;
      }
    }
    int mi = *min_element(w.begin(), w.end());
    int peq = 0;
    for (int i : w)
      if (i == mi) peq++;
    int last = 0;
    for (int i = 0; i < k; i++) {
      int ini = last;
      int first = ini;
      for (int j = 0; j < peq; j++) {
        cout << n / m << " ";
        for (int x = 0; x < n / m; x++) {
          cout << ini + 1 << " ";
          ini = (ini + 1) % n;
        }
        cout << '\n';
      }
      last = ini;
      while (first != ini) {
        cout << (n + m - 1) / m << " ";
        for (int x = 0; x < (n + m - 1) / m; x++) {
          cout << ini + 1 << " ";
          ini = (ini + 1) % n;
        }
        cout << '\n';
      }
    }
    cout << '\n';
  }
  exit(0);
}
