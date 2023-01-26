#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  int n;
  while (t--) {
    scanf("%d", &n);
    cout << 2;
    auto j = 1, prev = 2;
    for (int i = 1; i < n; i++) {
      while ((prev + j) % prev == 0) j++;
      cout << " " << prev + j;
      prev += j;
      j = 1;
    }
    cout << endl;
  }
}
