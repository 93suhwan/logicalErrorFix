#include <bits/stdc++.h>
using namespace std;
bool pake[501];
int n;
int main() {
  memset(pake, 0, sizeof(pake));
  pake[0] = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    for (int j = 0; j <= a; j++) {
      if (pake[j]) {
        pake[j ^ a] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= 500; i++) {
    if (pake[i]) {
      ans++;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i <= 500; i++) {
    if (pake[i]) {
      cout << i << " ";
    }
  }
  cout << "\n";
}
