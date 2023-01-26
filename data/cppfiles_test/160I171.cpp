#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, k;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int count1 = 0;
    if (rb != rd && cb != cd) {
      for (int i = 0; i < (m + n); i++) {
        rb = rb + 1;
        cb = cb + 1;
        count1++;
        if (rb == n || cb == m || rb == rd || cb == cd || rb == 1 || cb == 1) {
          break;
        }
      }
    }
    int count2 = 0;
    int count3 = 0;
    int count4 = 0, count5 = 0, count6 = 0, count7, count8 = 0, count9 = 0;
    if (rb == n && cb == m) {
      for (int i = 0; i < n; i++) {
        {
          rb = rb - 1;
          cb = cb - 1;
        }
        count4++;
        if (rb == rd || cb == cd) {
          break;
        }
      }
    }
    if (rb == 1 && cb == 1) {
      for (int i = 0; i < n; i++) {
        {
          rb = rb + 1;
          cb = cb + 1;
        }
        count5++;
        if (rb == n || cb == m || rb == rd || cb == cd || rb == 1 || cb == 1) {
          break;
        }
      }
    }
    if (rb == n && cb == 1) {
      for (int i = 0; i < n; i++) {
        {
          rb = rb - 1;
          cb = cb + 1;
        }
        count6++;
        if (rb == n || cb == m || rb == rd || cb == cd || rb == 1 || cb == 1) {
          break;
        }
      }
    }
    if (rb == 1 && cb == m) {
      for (int i = 0; i < n; i++) {
        {
          rb = rb + 1;
          cb = cb - 1;
        }
        count7++;
        if (rb == n || cb == m || rb == rd || cb == cd || rb == 1 || cb == 1) {
          break;
        }
      }
    }
    if (rb == 1) {
      for (int i = 0; i < n; i++) {
        {
          rb = rb + 1;
          cb = cb + 1;
        }
        count8++;
        if (rb == n || cb == m || rb == rd || cb == cd || rb == 1 || cb == 1) {
          break;
        }
      }
    }
    if (rb == n) {
      for (int i = 0; i < n; i++) {
        {
          rb = rb - 1;
          cb = cb + 1;
        }
        count2++;
        if (rb == n || cb == m || rb == rd || cb == cd || rb == 1 || cb == 1) {
          break;
        }
      }
    }
    if (cb == 1) {
      for (int i = 0; i < n; i++) {
        {
          rb = rb + 1;
          cb = cb + 1;
        }
        count9++;
        if (rb == n || cb == m || rb == rd || cb == cd || rb == 1 || cb == 1) {
          break;
        }
      }
    }
    if (cb == m) {
      for (int i = 0; i < n; i++) {
        {
          rb = rb + 1;
          cb = cb - 1;
        }
        count3++;
        if (rb == n || cb == m || rb == rd || cb == cd || rb == 1 || cb == 1) {
          break;
        }
      }
      if (rb == rd || cb == cd) {
        cout << count1 + count2 + count3 + count4 + count5 + count6 + count7 +
                    count8 + count9
             << endl;
      }
    }
  }
}
