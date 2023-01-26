#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int arr[n];
    int i;
    for (i = 0; i < n; i++) cin >> arr[i];
    long long int m = 0;
    for (i = 0; i < n; i++) {
      m = max(m, arr[i] - 1 - i);
    }
    cout << m;
    cout << '\n';
  }
}
