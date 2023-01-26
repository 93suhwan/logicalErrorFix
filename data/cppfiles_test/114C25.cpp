#include <bits/stdc++.h>
using namespace std;
void solv() {
  long long len;
  cin >> len;
  long long arr[len];
  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + len);
  for (int i = 1; i <= len / 2; i++) {
    cout << arr[i] << " " << arr[0] << endl;
  }
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    solv();
  }
  return 0;
}
