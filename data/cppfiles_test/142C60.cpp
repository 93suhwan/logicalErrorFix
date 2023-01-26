#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> m >> n;
    vector<int> store(n, 0);
    int c = 0;
    for (int i = 0; i < m; i++) {
      int gifts[n];
      for (int j = 0; j < n; j++) {
        cin >> gifts[j];
        store[j] = max(gifts[j], store[j]);
      }
      sort(gifts, gifts + n);
      c = max(c, gifts[n - 2]);
    }
    cout << min(c, *min_element(store.begin(), store.end())) << endl;
  }
  return 0;
}
