#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, arr[1010][5];
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d %d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3],
            &arr[i][4]);
    bool result = false;
    for (int i = 0; i < 5; i++) {
      for (int j = i + 1; j < 5; j++) {
        int a = 0, b = 0, c = 0;
        bool possible = true;
        for (int k = 0; k < n; k++) {
          if (arr[k][i] == 1 && arr[k][j] == 0)
            a++;
          else if (arr[k][i] == 0 && arr[k][j] == 1)
            b++;
          else if (arr[k][i] == 1 && arr[k][j] == 1)
            c++;
          else {
            possible = false;
            break;
          }
        }
        if (possible && abs(a - b) <= c) {
          result = true;
          break;
        }
      }
      if (result) break;
    }
    if (result)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
