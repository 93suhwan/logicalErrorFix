#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n, i, j, curr, ind;
    vector<vector<long long int>> v;
    cin >> n;
    vector<long long int> a(n);
    for (i = 0; i < n; i++) cin >> a[i];
    j = 0;
    while (j < n) {
      curr = a[j];
      for (i = j + 1; i < n; i++) {
        if (a[i] < curr) {
          curr = a[i];
          ind = i;
        }
      }
      if (curr == a[j]) {
        j++;
        continue;
      }
      for (i = ind; i > j; i--) a[i] = a[i - 1];
      a[j] = curr;
      v.push_back({j, ind, ind - j});
      j++;
    }
    cout << v.size() << "\n";
    for (i = 0; i < v.size(); i++)
      cout << v[i][0] + 1 << " " << v[i][1] + 1 << " " << v[i][2] << "\n";
  }
}
