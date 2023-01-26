#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[1001] = {0};
  int count = 1;
  for (int i = 1; count <= 1666;) {
    if (count % 10 != 3 && count % 3 != 0) {
      arr[i] = count;
      i++;
    }
    count++;
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << arr[n] << "\n";
    ;
  }
}
