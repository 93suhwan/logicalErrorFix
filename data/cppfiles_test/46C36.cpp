#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    vector<int> arr2;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
      while (!arr2.empty() && *(arr2.end() - 1) <= arr[i]) {
        arr2.pop_back();
      }
      arr2.push_back(arr[i]);
    }
    cout << arr2.size() - 1 << endl;
  }
}
