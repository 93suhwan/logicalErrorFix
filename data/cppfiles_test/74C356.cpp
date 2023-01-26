#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    bool arr[a + b + 1];
    for (int i = 0; i < a + b + 1; i++) arr[i] = true;
    int c = abs(a - b) / 2;
    for (int j = 0; j < c; j++) {
      arr[j] = false;
      arr[a + b - j] = false;
    }
    if ((a + b) % 2 == 0) {
      if (a % 2 == ((a + b) / 2) % 2) {
        for (int j = 0; j < a + b + 1; j++)
          if (j % 2 == 1) {
            arr[j] = false;
          }
      } else {
        for (int j = 0; j < a + b + 1; j++)
          if (j % 2 == 0) {
            arr[j] = false;
          }
      }
    }
    int co = 0;
    for (int i = 0; i < a + b + 1; i++)
      if (arr[i]) co++;
    cout << co << endl;
    for (int i = 0; i < a + b; i++) {
      if (arr[i]) cout << i << " ";
    }
    if (arr[a + b]) cout << a + b << endl;
  }
  return 0;
}
