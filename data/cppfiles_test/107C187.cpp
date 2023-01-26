#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, i, j;
    cin >> n >> a >> b;
    int arr[n];
    if (abs(a - b) > 1 || a + b > n - 2) {
      cout << "-1" << endl;
    } else if (a == 0 && b == 0) {
      for (i = 0; i < n; i++) {
        cout << i + 1 << " ";
      }
      cout << endl;
    } else if (a == 0) {
      arr[1] = 1;
      arr[0] = 2;
      for (i = 2; i < n; i++) {
        arr[i] = i + 1;
      }
      for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    } else if (b == 0) {
      arr[0] = n - 1;
      arr[1] = n;
      int x = n - 2;
      for (i = 2; i < n; i++) {
        arr[i] = x;
        x--;
      }
      for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    } else if (a > b) {
      int x = n;
      int y = a;
      int end = 0;
      for (i = 1; i < n - 1; i += 2) {
        if (y == 1) {
          break;
        }
        arr[i] = x;
        x--;
        y--;
        end = i;
      }
      arr[n - 2] = x;
      x--;
      int x1 = 1;
      for (i = 2; i < end; i += 2) {
        arr[i] = x1;
        x1++;
      }
      for (i = end + 1; i < n - 2; i++) {
        arr[i] = x;
        x--;
      }
      arr[n - 1] = x;
      x--;
      arr[0] = x;
      for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    } else if (b > a) {
      int x = 1;
      int y = b;
      int end = 0;
      for (i = 1; i < n - 1; i += 2) {
        if (y == 1) {
          break;
        }
        arr[i] = x;
        x++;
        y--;
        end = i;
      }
      arr[n - 2] = x;
      x++;
      int x1 = n;
      for (i = 2; i < end; i += 2) {
        arr[i] = x1;
        x1--;
      }
      for (i = end + 1; i < n - 2; i++) {
        arr[i] = x1;
        x1--;
      }
      arr[n - 1] = x1;
      x1--;
      arr[0] = x1;
      for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    } else if (a == b) {
      int x = n;
      int y = 1;
      int end = 0;
      for (i = 1; i < n; i += 2) {
        if (a == 0) {
          break;
        }
        arr[i] = x;
        x--;
        a--;
        end = i;
      }
      for (i = 2; i < end; i += 2) {
        arr[i] = y;
        y++;
      }
      for (i = end + 1; i < n; i++) {
        arr[i] = y;
        y++;
      }
      arr[0] = y;
      for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
