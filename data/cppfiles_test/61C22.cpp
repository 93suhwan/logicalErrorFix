#include <bits/stdc++.h>
using namespace std;
void find(string A, int n) {
  int k = 0;
  int B = 0;
  int l = -1;
  for (int i = 0; i < n; i++) {
    if (A[i] == '?') {
      continue;
    } else {
      if (A[i] == 'B') {
        B = 1;
      } else {
        B = 0;
      }
      if (i > 0 && A[i - 1] == '?') {
        int j = i - 1;
        while (j >= 0 && A[j] == '?') {
          if (B == 1) {
            A[j] = 'R';
            B = 0;
          } else {
            A[j] = 'B';
            B = 1;
          }
          j--;
        }
      }
      l = i;
    }
  }
  if (l < (n - 1)) {
    if (l == -1) {
      B = 1;
      int i = 0;
      while (i < n) {
        if (B == 0) {
          A[i] = 'B';
          B = 1;
        } else {
          A[i] = 'R';
          B = 0;
        }
        i++;
      }
    } else {
      if (A[l] == 'B') {
        B = 1;
      } else {
        B = 0;
      }
      int i = l + 1;
      while (i < n) {
        if (B == 0) {
          A[i] = 'B';
          B = 1;
        } else {
          A[i] = 'R';
          B = 0;
        }
        i++;
      }
    }
  }
  cout << A;
  cout << "\n";
  return;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    string A;
    cin >> A;
    find(A, n);
  }
  return 0;
}
