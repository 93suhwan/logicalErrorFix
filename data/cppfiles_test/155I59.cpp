#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    string s;
    cin >> s;
    vector<int> ans(n);
    int tmp = 1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        arr[i] = tmp;
        ++tmp;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        arr[i] = tmp;
        ++tmp;
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}
