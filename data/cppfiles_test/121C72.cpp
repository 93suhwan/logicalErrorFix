#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  string a, b;
  while (t--) {
    int n;
    cin >> n;
    cin >> a;
    cin >> b;
    int diff = 0, litA = 0, litB = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        ++diff;
      }
      if (a[i] == '1') {
        ++litA;
      }
      if (b[i] == '1') {
        ++litB;
      }
    }
    int mi = n + 1;
    if (litA == litB) {
      mi = diff;
    }
    if (n - litA + 1 == litB) {
      mi = min(mi, (n - 1 - diff) + 1);
    }
    if (mi == n + 1) {
      mi = -1;
    }
    cout << mi << '\n';
  }
}
