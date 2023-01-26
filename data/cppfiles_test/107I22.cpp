#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 7;
long long int mE(long long int x, long long int n, long long int M) {
  long long int result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
void light_yagami() {
  int n, a, b;
  cin >> n >> a >> b;
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  if (a + b > n - 2) {
    cout << "-1" << endl;
    return;
  }
  if (n % 2 == 0) {
    if (a > (n / 2) - 1 || b > (n / 2) - 1) {
      cout << "-1" << endl;
      return;
    }
  }
  if (n % 2 == 1) {
    if (a > (n / 2) || b > (n / 2)) {
      cout << "-1" << endl;
      return;
    }
  }
  int x = a, y = b;
  for (int i = 0; i < n; i = i + 2) {
    if (y == 0)
      break;
    else {
      swap(arr[i], arr[i + 1]);
      y--;
    }
  }
  for (int i = n - 1; i >= 0; i = i + 2) {
    if (x == 0)
      break;
    else {
      swap(arr[i], arr[i - 1]);
      x--;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    light_yagami();
  }
}
