#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 2147483647;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ans &= x;
    }
    cout << ans << endl;
  }
  return 0;
}
