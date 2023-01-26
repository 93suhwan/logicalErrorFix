#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int q;
    cin >> q;
    int num = 1;
    for (int i = 1; i < q; i++) {
      num++;
      while (num % 3 == 0 || num % 10 == 3) num++;
    }
    cout << num << "\n";
  }
  return 0;
}
