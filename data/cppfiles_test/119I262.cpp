#include <bits/stdc++.h>
using namespace std;
void solve() {}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    if (sum % n == 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  }
  cout << endl;
}
