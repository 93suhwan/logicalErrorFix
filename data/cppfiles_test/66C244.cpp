#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, curr = 1;
  cin >> t;
  vector<int> arr(1000, 0);
  for (int i = 0; i < 1000; i++) {
    while (curr % 10 == 3 || curr % 3 == 0) {
      curr++;
    }
    arr[i] = curr;
    curr++;
  }
  while (t--) {
    int n;
    cin >> n;
    cout << arr[n - 1] << endl;
  }
}
