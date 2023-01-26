#include <bits/stdc++.h>
using namespace std;
bool like(int x) {
  if (x % 3 == 0) {
    return false;
  }
  while (x > 0) {
    if (x % 10 == 3) {
      return false;
    }
    x /= 10;
  }
  return true;
}
int main() {
  int i = 1, num = 1, arr[1001];
  while (i <= 1000) {
    if (like(num)) {
      arr[i] = num;
      i++;
    }
    num++;
  }
  int x;
  cin >> x;
  for (int i = 0; i < x; i++) {
    int k;
    cin >> k;
    cout << arr[k] << endl;
  }
}
