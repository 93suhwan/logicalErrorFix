#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int i, n, m;
    cin >> n >> m;
    long long int a[m], c[m];
    vector<long long int> b;
    for (i = 0; i < m; i++) {
      cin >> a[i];
      b.push_back(a[i]);
      c[i] = -1;
    }
    sort(b.begin(), b.end());
    long long int incon = 0;
    for (i = 0; i < m; i++) {
      auto ind = lower_bound(b.begin(), b.end(), a[i]);
      long long int x = ind - b.begin();
      long long int j;
      for (j = 0; j < x; j++) {
        if (c[j] != -1) {
          incon++;
        }
      }
      c[j] = a[i];
    }
    cout << incon;
    cout << '\n';
  }
  return 0;
}
