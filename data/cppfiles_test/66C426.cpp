#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int main() {
  std::ios::sync_with_stdio(false);
  int i = 0;
  int k = 1;
  while (i < 1000) {
    if (k % 3 != 0 and k % 10 != 3) {
      arr[i] = k;
      k++;
      i++;
    } else {
      k++;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    n--;
    cout << arr[n] << "\n";
  }
}
