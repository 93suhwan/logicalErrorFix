#include <bits/stdc++.h>
using namespace std;
long long md = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int i = 0;
    while (arr[i] == 0) {
      cout << i + 1 << " ";
      i++;
    }
    cout << n + 1 << " ";
    for (int j = i; j < n; j++) cout << j + 1 << " ";
    cout << "\n";
  }
  return 0;
}
