#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
using vi = vector<long long>;
void slv() {
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long _ = 0; _ < k; _++) {
    for (long long i = 0; i < m; i++) {
      cout << (n / m) + (i < n % m) << " ";
      for (long long j = 0; j < (n + (i < n % m ? m - 1 : 0)) / m; j++) {
        cout << ((_ * (n % m) * ((n + m - 1) / m)) % n + i * (n / m) + j +
                 min(i, n % m)) %
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
  long long t;
  cin >> t;
  for (long long cs = 0; cs < t; cs++) slv();
  return 0;
}
