#include <bits/stdc++.h>
using namespace std;
int T, n;
vector<int> a;
int main() {
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> n;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1; i < 1 + n / 2; i++) cout << a[i] << " " << a[0] << "\n";
  }
  return 0;
}
