#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int w, h, k;
    cin >> w >> h;
    int max1 = 0;
    int max2 = 0;
    int first, tmp;
    for (int i = 0; i < 2; i++) {
      cin >> k;
      cin >> first;
      for (int j = 1; j < k; j++) {
        cin >> tmp;
      }
      max1 = max(max1, tmp - first);
    }
    for (int i = 0; i < 2; i++) {
      cin >> k;
      cin >> first;
      for (int j = 1; j < k; j++) {
        cin >> tmp;
      }
      max2 = max(max2, tmp - first);
    }
    cout << max(max1 * h, max2 * w) << '\n';
  }
  return 0;
}
