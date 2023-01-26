#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    if (!(arr[i] / 10 == 3) && !(arr[i] == 3)) cout << arr[i] << "\n";
  }
  return 0;
}
