#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++) {
      arr[i] = i + 2;
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
  }
  return 0;
}
