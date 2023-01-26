#include <bits/stdc++.h>
using namespace std;
bool canHe(vector<vector<int> > arr, int n, int ind1, int ind2) {
  if (ind1 == 1 && ind2 == n - 1) {
    return true;
  }
  if (ind1 >= 2 || ind1 < 0 || ind2 >= n) {
    return false;
  }
  if (arr[ind1][ind2] == 1) {
    return false;
  }
  if (arr[1][n - 1] == 1) {
    return false;
  }
  return canHe(arr, n, ind1 + 1, ind2 + 1) ||
         canHe(arr, n, ind1 - 1, ind2 + 1) || canHe(arr, n, ind1, ind2 + 1);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int> > arr;
    for (int i = 0; i < 2; i++) {
      vector<int> temp;
      for (int j = 0; j < n; j++) {
        int a;
        cin >> a;
        temp.push_back(a);
      }
      arr.push_back(temp);
    }
    if (canHe(arr, n, 0, 0)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
