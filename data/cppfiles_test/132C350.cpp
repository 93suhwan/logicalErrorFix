#include <bits/stdc++.h>
using namespace std;
int arr[10];
int main(void) {
  int T;
  cin >> T;
  while (T--) {
    for (int i = 1; i <= 7; i++) scanf("%d", &arr[i]);
    cout << arr[1] << " " << arr[2] << " " << arr[7] - arr[2] - arr[1] << endl;
  }
}
