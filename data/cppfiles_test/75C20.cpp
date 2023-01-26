#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int l = 0;
  int r2 = 0;
  int r = n - 1;
  while (l < n && arr[l] < arr[l + 1]) {
    l++;
  }
  while (r > l && arr[r] < arr[r - 1]) {
    r--;
    r2++;
  }
  if ((r2 + 1) % 2 || (l + 1) % 2) {
    cout << "Alice";
  } else {
    cout << "Bob";
  }
}
