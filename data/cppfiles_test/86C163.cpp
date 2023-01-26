#include <bits/stdc++.h>
using namespace std;
int n;
void solver(vector<int> &a, vector<int> &b) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] + b[i] == 1)
      ans += 2;
    else if (a[i] + b[i] == 0) {
      if (i + 1 < n && (a[i + 1] + b[i + 1] == 2)) {
        ans += 2;
        i++;
      } else
        ans += 1;
    } else {
      if (i + 1 < n && (a[i + 1] + b[i + 1] == 0)) {
        ans += 2;
        i++;
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    string a, b;
    vector<int> x(n), y(n);
    cin >> a;
    cin >> b;
    for (int i = 0; i < n; i++) {
      x[i] = a[i] - '0';
      y[i] = b[i] - '0';
    }
    solver(x, y);
  }
  return 0;
}
