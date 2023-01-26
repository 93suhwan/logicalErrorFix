#include <bits/stdc++.h>
using namespace std;
void helper(vector<int>& arr, int i) {
  if (i >= arr.size() - 1) return;
  if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
  helper(arr, i + 2);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int c = 0;
    while (true) {
      int i = 0;
      for (; i < n - 1 && arr[i] < arr[i + 1]; i++)
        ;
      if (i >= n - 1) break;
      c++;
      if (c % 2)
        helper(arr, 0);
      else
        helper(arr, 1);
    }
    cout << c << "\n";
  }
}
