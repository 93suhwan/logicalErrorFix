#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    vector<int> vec;
    for (int i = 0; i < 7; i++) {
      int n;
      cin >> n;
      vec.push_back(n);
    }
    for (int a = 0; a < 6; a++) {
      for (int b = a + 1; b < 6; b++) {
        for (int c = b + 1; c < 6; c++) {
          if (vec[a] + vec[b] + vec[c] == vec[6]) {
            cout << vec[a] << " " << vec[b] << " " << vec[c] << "\n";
            continue;
          }
        }
      }
    }
  }
  return 0;
}
