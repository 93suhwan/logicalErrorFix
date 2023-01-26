#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int cases;
  cin >> cases;
  for (int j = 0; j < cases; j++) {
    int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << "\n";
    } else if (n % 3 == 1) {
      cout << (n / 3) + 1 << " " << n / 3 << "\n";
    } else {
      cout << (n / 3) << " " << (n / 3) + 1 << "\n";
    }
  }
  return 0;
}
