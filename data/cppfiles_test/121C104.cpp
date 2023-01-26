#include <bits/stdc++.h>
using namespace std;
void find(string A, string B, int n) {
  int same0 = 0;
  int same1 = 0;
  int dif0 = 0;
  int dif1 = 0;
  if (A == B) {
    cout << "0\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    if (A[i] == B[i]) {
      if (A[i] == '0') {
        same0++;
      } else {
        same1++;
      }
    } else {
      if (A[i] == '1') {
        dif1++;
      } else {
        dif0++;
      }
    }
  }
  if ((same0 + same1) == 1 && same1 == 1) {
    cout << "1\n";
    return;
  }
  int mi = INT_MAX;
  if (dif0 == dif1) {
    mi = min(2 * dif0, mi);
  }
  if (same1 == (same0 + 1)) {
    mi = min(mi, 2 * same0 + 1);
  }
  if (mi == INT_MAX) {
    cout << "-1\n";
  } else {
    cout << mi << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int n;
    cin >> n;
    string A;
    string B;
    cin >> A;
    cin >> B;
    find(A, B, n);
  }
  return 0;
}
