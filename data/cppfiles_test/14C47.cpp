#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) c++;
    }
    if (c == n)
      cout << "0"
           << "\n";
    else {
      vector<tuple<int, int, int>> t;
      for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
          if (b[i] == a[j]) {
            t.push_back(make_tuple(i + 1, j + 1, j - i));
            int x = j - i;
            int c[x + 1];
            for (int k = 0; k <= x; k++) {
              c[k] = a[i + ((k + x) % (x + 1))];
            }
            int p = 0;
            for (int k = i; k <= j; k++) {
              a[k] = c[p];
              p++;
            }
            break;
          }
        }
      }
      cout << t.size() << "\n";
      for (int i = 0; i < t.size(); i++) {
        cout << get<0>(t[i]) << " " << get<1>(t[i]) << " " << get<2>(t[i])
             << "\n";
      }
    }
  }
  return 0;
}
