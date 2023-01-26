#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    long int arr[m];
    for (int i = 0; i < m; i++) {
      cin >> arr[i];
    }
    long int sum = 0;
    for (int i = 1; i < m; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (arr[i] > arr[j]) sum++;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
