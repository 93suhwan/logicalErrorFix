#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      arr.push_back(temp);
    }
    int k = 1;
    int die = 0;
    for (int i = 0; i < n; i++) {
      if (i > 0 && (arr[i] == 0 && arr[i - 1] == 0)) {
        k = -1;
        break;
      } else if (i > 0 && (arr[i] == 1 && arr[i - 1] == 1)) {
        k += 5;
      } else if (arr[i] == 1) {
        k++;
      }
    }
    cout << k << endl;
  }
  return 0;
}
