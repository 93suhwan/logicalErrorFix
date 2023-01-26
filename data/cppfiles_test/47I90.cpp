#include <bits/stdc++.h>
using namespace std;
int input[] = {1, 6, 4, 2, 3, 5, 4};
int query(int i, int j, bool flag) {
  int ans;
  if (flag) {
    cout << "and " << i + 1 << ' ' << j + 1 << endl;
    cin >> ans;
  } else {
    cout << "or " << i + 1 << ' ' << j + 1 << endl;
    cin >> ans;
  }
  return ans;
}
int main() {
  int n, k;
  cin >> n >> k;
  int a[n][30];
  memset(a, -1, sizeof(a));
  int a1, a2, a3;
  int b1, b2, b3;
  a1 = query(0, 1, 0);
  a2 = query(1, 2, 0);
  a3 = query(0, 2, 0);
  b1 = query(0, 1, 1);
  b2 = query(1, 2, 1);
  b3 = query(0, 2, 1);
  for (int j = 0; j < 30; j++) {
    bool flag1 = (a1 & (1 << j)) > 0;
    bool flag2 = (b1 & (1 << j)) > 0;
    if (flag1 && flag2) {
      a[0][j] = 1;
      a[1][j] = 1;
    } else if (!flag1 && !flag2) {
      a[0][j] = 0;
      a[1][j] = 0;
    }
  }
  for (int j = 0; j < 30; j++) {
    bool flag1 = (a2 & (1 << j)) > 0;
    bool flag2 = (b2 & (1 << j)) > 0;
    if (flag1 && flag2) {
      a[1][j] = 1;
      a[2][j] = 1;
    } else if (!flag1 && !flag2) {
      a[1][j] = 0;
      a[2][j] = 0;
    }
  }
  for (int j = 0; j < 30; j++) {
    bool flag1 = (a3 & (1 << j)) > 0;
    bool flag2 = (b3 & (1 << j)) > 0;
    if (flag1 && flag2) {
      a[0][j] = 1;
      a[2][j] = 1;
    } else if (!flag1 && !flag2) {
      a[0][j] = 0;
      a[2][j] = 0;
    }
  }
  for (int j = 0; j < 30; j++) {
    bool flag1 = (a1 & (1 << j)) > 0;
    bool flag2 = (b1 & (1 << j)) > 0;
    if (flag1 != flag2) {
      if (a[1][j] == -1)
        a[1][j] = 1 - a[0][j];
      else
        a[0][j] = 1 - a[1][j];
    }
  }
  for (int i = 3; i < n; i++) {
    int val1 = query(0, i, 0);
    int val2 = query(0, i, 1);
    for (int j = 0; j < 30; j++) {
      bool flag1 = (val1 & (1 << j)) > 0;
      bool flag2 = (val2 & (1 << j)) > 0;
      if (flag1 == flag2)
        a[i][j] = a[0][j];
      else
        a[i][j] = 1 - a[0][j];
    }
  }
  int arr[n];
  memset(arr, 0, sizeof(arr));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 30; j++) {
      if (a[i][j]) arr[i] += (1 << j);
    }
  }
  sort(arr, arr + n);
  cout << "finish " << arr[k - 1] << endl;
  return 0;
}
