#include <bits/stdc++.h>
using namespace std;
const long long int num = 1e5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int p = max(a, b) - min(a, b);
    int low = p / 2;
    int high = 2 * (min(a, b)) + (p + 1) / 2;
    if (a != b and a % 2 != b % 2) {
      cout << high - low + 1 << "\n";
      for (int i = low; i <= high; ++i) {
        cout << i << " ";
      }
      cout << "\n";
    } else {
      int cnt = 0;
      for (int i = low; i <= high; i += 2) {
        cnt++;
      }
      cout << cnt << "\n";
      for (int i = low; i <= high; i += 2) {
        cout << i << " ";
      }
      cout << "\n";
    }
  }
}
