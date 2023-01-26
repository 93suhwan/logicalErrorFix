#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a = 0;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      a += tmp;
    }
    cout << (a % n != 0) << '\n';
  }
  return 0;
}
