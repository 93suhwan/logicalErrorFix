#include <bits/stdc++.h>
using namespace std;
bool like(int x) {
  if (x % 3 == 0 || x % 10 == 3) {
    return false;
  }
  return true;
}
int main() {
  int i = 1, num = 1, arr[1001];
  while (i <= 1000) {
    if (like(num)) {
      arr[i] = num;
      i++;
      cout << num << endl;
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
