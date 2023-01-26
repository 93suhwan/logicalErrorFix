#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int arr[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (!(n % 3 == 0)) cout << n;
  }
  return 0;
}
