#include <bits/stdc++.h>
using namespace std;
const int tam = 200005;
int A[tam];
int B[tam];
int v[tam];
int main() {
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  A[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    A[i] = 1;
    if (v[i] < v[i + 1]) A[i] = A[i + 1] + 1;
  }
  B[1] = 1;
  for (int i = 2; i <= n; i++) {
    B[i] = 1;
    if (v[i] < v[i - 1]) B[i] = B[i - 1] + 1;
  }
  int izq = 1, der = n;
  bool win = 1;
  int last = -1;
  while (1) {
    if (der < izq) break;
    if (v[izq] <= last && v[der] <= last) break;
    if (v[izq] == v[der]) {
      if (A[izq] % 2 or B[der] % 2) win = !win;
      break;
    }
    if (v[der] > last && v[izq] <= last) {
      if (B[der] % 2) win = !win;
      break;
    }
    if (v[izq] > last && v[der] <= last) {
      if (A[izq] % 2) win = !win;
      break;
    }
    if (v[izq] >= v[der]) {
      if (A[izq] % 2) {
        win = !win;
        break;
      }
      last = v[der];
      win = !win;
      der--;
    } else {
      if (B[der] % 2) {
        win = !win;
        break;
      }
      last = v[izq];
      win = !win;
      izq++;
    }
  }
  if (win) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
  return 0;
}
