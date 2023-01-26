#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    bool flag = true;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (n % 2 == 1) {
      for (int i = 0; i < n - 1; i++) {
        if (arr[i] >= arr[i + 1]) {
          flag = false;
          break;
        }
      }
    }
    if (n % 2 == 1) {
      if (!flag) {
        cout << "NO" << endl;
      }
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
