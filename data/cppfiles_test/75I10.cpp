#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, a[N];
int main() {
  cin >> n;
  a[0] = a[n + 1] = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1, r = n, cntl = 0, cntr = 0;
  while (a[l + cntl] > a[l - 1 + cntl]) cntl++;
  while (a[r - cntr] > a[r + 1 - cntr]) cntr++;
  int prev = -1, qnt = 0;
  while (l <= r && max(a[l], a[r]) > prev) {
    if (qnt % 2 == 0) {
      if (a[l] >= a[r] && cntl % 2 == 1) {
        cout << "Alice";
        return 0;
      }
      if (a[r] >= a[l] && cntr % 2 == 1) {
        cout << "Alice";
        return 0;
      }
    } else {
      if (a[l] >= a[r] && cntl % 2 == 1) {
        cout << "Bob";
        return 0;
      }
      if (a[r] >= a[l] && cntr % 2 == 1) {
        cout << "Bob";
        return 0;
      }
    }
    if (min(a[l], a[r]) > prev) {
      if (a[l] < a[r]) {
        cntl--;
        l++;
        prev = a[l];
      } else if (a[r] < a[l]) {
        cntr--;
        r--;
        prev = a[r];
      } else {
        if (qnt % 2 == 0) {
          cout << "Bob";
          return 0;
        } else {
          cout << "Alice";
          return 0;
        }
      }
    } else {
      if (qnt % 2 == 0) {
        cout << "Bob";
        return 0;
      } else {
        cout << "Alice";
        return 0;
      }
    }
    qnt++;
  }
}
