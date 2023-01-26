#include <bits/stdc++.h>
using namespace std;
int n;
char aa[1234][1234];
bool f[1234];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> aa[i];
  }
  for (int i = 0; i < n; i++) {
    if (strlen(aa[i]) % 2 == 1) {
      f[i] = true;
    } else {
      for (int j = 0; j < strlen(aa[i]) / 2; j++) {
        if (aa[i][j] != aa[i][strlen(aa[i]) / 2 + j]) {
          f[i] = true;
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (f[i]) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
