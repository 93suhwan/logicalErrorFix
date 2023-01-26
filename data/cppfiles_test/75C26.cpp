#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  int l = 0;
  while (l + 1 < n && arr[l] < arr[l + 1]) {
    ++l;
  }
  int r = n - 1;
  while (r - 1 >= 0 && arr[r] < arr[r - 1]) {
    --r;
  }
  l = l + 1;
  r = n - r;
  if (l % 2 || r % 2)
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
  return 0;
}
