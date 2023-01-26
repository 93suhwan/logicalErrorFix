#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    vector<int> a(3);
    vector<int> b(7);
    for (auto &i : b) {
      cin >> i;
    }
    a[0] = b[0];
    a[1] = b[6] - b[0] - b[1];
    a[2] = b[6] - a[0] - a[1];
    cout << "# ";
    for (auto i : a) cout << i << " ";
    cout << "\n";
  }
  return 0;
}
