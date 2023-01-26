#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    const int L = 26;
    int arr[L];
    string str;
    cin >> str;
    memset(arr, 0, sizeof(arr));
    for (auto i : str) {
      arr[i - 'a']++;
    }
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < L; i++) {
      if (arr[i] == 1) {
        c1++;
      } else if (arr[i] > 0) {
        c2++;
      }
    }
    cout << c2 + (c1 / 2) << endl;
  }
  return 0;
}
