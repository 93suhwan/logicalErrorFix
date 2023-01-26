#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
void slv() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int _ = 0; _ < k; _++) {
    for (int i = 0; i < m; i++) {
      cout << (n / m) + (i < n % m) << " ";
      for (int j = 0; j < (n + (i < n % m ? m - 1 : 0)) / m; j++) {
        cout << ((((((n % m) * (n + m - 1) / m)) % n) * (_) % n) % n +
                 i * (n / m) + j + min(i, n % m)) %
                        n +
                    1
             << " ";
      }
      cout << "\n";
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int cs = 0; cs < t; cs++) slv();
  return 0;
}
