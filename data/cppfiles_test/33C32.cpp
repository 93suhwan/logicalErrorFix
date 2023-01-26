#include <bits/stdc++.h>
using namespace std;
int pake[1001];
int n;
int main() {
  memset(pake, -1, sizeof(pake));
  cin >> n;
  pake[0] = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if (pake[a] == -1) {
      pake[a] = a;
    } else if (pake[a] > i) {
      pake[a] = a;
    }
    for (int j = 0; j <= 1000; j++) {
      if (pake[j] != -1 && pake[j] <= a) {
        if (pake[j ^ a] == -1) {
          pake[j ^ a] = a;
        } else if (pake[j ^ a] > a) {
          pake[j ^ a] = a;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= 1000; i++) {
    if (pake[i] != -1) {
      ans++;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i <= 1000; i++) {
    if (pake[i] != -1) {
      cout << i << " ";
    }
  }
  cout << "\n";
}
