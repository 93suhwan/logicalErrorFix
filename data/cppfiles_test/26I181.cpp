#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int a[10];
    int b[10];
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        a[i] = 0;
      } else if (s[i] == '1') {
        a[i] = 1;
      } else {
        a[i] = -1;
      }
    }
    for (int i = 0; i < 10; i++) {
      if (a[i] != -1) {
        b[i] = a[i];
      } else {
        if (i % 2 == 0) {
          b[i] = 0;
        } else {
          b[i] = 1;
        }
      }
    }
    int ans_b = 9;
    int left = 5;
    int d = 0;
    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0) {
        left--;
        if (b[i] == 1) {
          d--;
        }
      } else {
        if (b[i] == 1) {
          d++;
        }
      }
      if (left < d) {
        ans_b = i;
        break;
      }
    }
    for (int i = 0; i < 10; i++) {
      if (a[i] != -1) {
        b[i] = a[i];
      } else {
        if (i % 2 == 1) {
          b[i] = 0;
        } else {
          b[i] = 1;
        }
      }
      cout << b[i];
    }
    cout << '\n';
    int ans_a = 9;
    left = 5;
    d = 0;
    for (int i = 0; i < 10; i++) {
      if (i % 2 == 1) {
        left--;
        if (b[i] == 1) {
          d--;
        }
      } else {
        if (b[i] == 1) {
          d++;
        }
      }
      if (left < d) {
        ans_a = i;
        break;
      }
    }
    if (ans_a < ans_b) {
      cout << ans_a + 1 << '\n';
    } else {
      cout << ans_b + 1 << '\n';
    }
  }
  return 0;
}
