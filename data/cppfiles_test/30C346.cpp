#include <bits/stdc++.h>
using namespace std;
char arr[104000];
int n;
int delete_til_end_of_world(int i1, int i2, char c) {
  int dr = 0;
  int dl = 0;
  int a = 0;
  while (i1 < i2) {
    if (arr[i1] != arr[i2]) {
      if (arr[i1] == c)
        while (i1 < i2 && arr[i1] == c) i1++, dl++;
      if (arr[i2] == c)
        while (i1 < i2 && arr[i2] == c) i2--, dr++;
    }
    if ((i1 < i2 && arr[i1] == arr[i2]) ||
        (i1 == i2 && (n - dl - dr) % 2 == 1)) {
      a++;
      i1++;
      i2--;
    } else {
      return -1;
    }
  }
  return dr + dl;
}
int main() {
  int t;
  cin >> t;
  for (decltype(0) tt = 0; tt < t; tt++) {
    cin >> n;
    for (decltype(0) i = 0; i < n; i++) cin >> arr[i];
    int i1 = 0, i2 = n - 1;
    int d = 0;
    while (i2 > i1) {
      if (arr[i1] != arr[i2]) {
        int d1 = delete_til_end_of_world(i1, i2, arr[i1]);
        int d2 = delete_til_end_of_world(i1, i2, arr[i2]);
        if (d1 == -1)
          d = d2;
        else if (d2 == -1)
          d = d1;
        else
          d = min(d1, d2);
        break;
      }
      i1++;
      i2--;
    }
    cout << d << endl;
  }
}
