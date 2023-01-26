#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int i = 0;
    while (i < n && a[i] == 0) {
      cout << i + 1 << ' ';
      i++;
    }
    cout << n + 1 << ' ';
    while (i < n) {
      cout << i + 1 << ' ';
      i++;
    }
    cout << endl;
  }
}
