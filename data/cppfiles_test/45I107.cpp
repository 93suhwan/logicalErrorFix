#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  long long int h = 1;
  for (long long int i = 0; i < n; i++) {
    if (i > 0 && arr[i] && arr[i - 1])
      h += 5;
    else if (arr[i])
      h++;
    else if (i > 1 && !arr[i] && !arr[i - 1]) {
      h = -1;
      break;
    }
  }
  cout << h;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
