#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    int N = n;
    if (abs(a - b) > 1) {
      cout << -1 << "\n";
      continue;
    }
    if (a + b > n - 2) {
      cout << -1 << "\n";
      continue;
    }
    bool flag = false;
    if (a < b) {
      swap(a, b);
      flag = true;
    }
    int A = a;
    int B = b;
    int sol[n];
    int i = 1;
    while (a--) {
      sol[i] = n;
      i += 2;
      n--;
    }
    i = 2;
    int temp = 1;
    while (b--) {
      sol[i] = temp;
      i += 2;
      temp++;
    }
    sol[0] = B + 1;
    temp = B + 2;
    int index = A + B + 1;
    if (B == A) {
      while (index != N) {
        sol[index] = temp;
        temp++;
        index++;
      }
    } else {
      temp = N - A;
      while (index != N) {
        sol[index] = temp;
        temp--;
        index++;
      }
    }
    if (flag) {
      for (int i = 0; i < N; i++) {
        sol[i] = N + 1 - sol[i];
      }
    }
    for (int i = 0; i < N; i++) {
      cout << sol[i] << " ";
    }
    cout << "\n";
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
