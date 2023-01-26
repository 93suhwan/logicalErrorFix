#include <bits/stdc++.h>
using namespace std;
int t, n;
int arr[55555][5];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> arr[i][j];
      }
    }
    int x = 0;
    for (int i = 1; i < n; i++) {
      int f = 0;
      for (int j = 0; j < 5; j++) {
        if (arr[i][j] < arr[x][j]) f++;
      }
      if (f >= 3) x = i;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int f = 0;
      for (int j = 0; j < 5; j++) {
        if (arr[x][j] < arr[i][j]) f++;
      }
      if (f >= 3) cnt++;
    }
    if (cnt != n - 1) {
      puts("-1");
    } else {
      printf("%d\n", x + 1);
    }
  }
  return 0;
}
