#include <bits/stdc++.h>
using namespace std;
int arr[6][200005];
int main() {
  int n, m, l, r, min, a = 0;
  char ref1[] = {'a', 'b', 'c'};
  char ref2[] = {'a', 'c', 'b'};
  string s;
  cin >> n >> m;
  cin >> s;
  for (int i = 0; i < 6; i++) {
    a = i;
    if (a < 3) {
      for (int j = 0; j < n; j++) {
        if (s.at(j) == ref1[a])
          arr[i][j + 1] = 0;
        else
          arr[i][j + 1] = 1;
        a = (a + 1) % 3;
      }
    } else {
      a = a % 3;
      for (int j = 0; j < n; j++) {
        if (s.at(j) == ref2[a])
          arr[i][j + 1] = 0;
        else
          arr[i][j + 1] = 1;
        a = (a + 1) % 3;
      }
    }
  }
  for (int i = 0; i < 6; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum = sum + arr[i][j + 1];
      arr[i][j + 1] = sum;
    }
  }
  for (int q = 0; q < m; q++) {
    cin >> l >> r;
    int min = arr[1][r] - arr[1][l - 1];
    for (int i = 0; i < 6; i++) {
      if (arr[i][r] - arr[i][l - 1] < min) min = arr[i][r] - arr[i][l - 1];
    }
    cout << min << endl;
  }
  return 0;
}
