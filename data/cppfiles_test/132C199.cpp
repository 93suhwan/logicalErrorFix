#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int b[7];
    for (int i = 0; i < 7; ++i) {
      cin >> b[i];
    }
    cout << b[0] << " " << b[1] << " " << b[6] - b[1] - b[0] << "\n";
  }
}
