#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1 || (a + b) > n - 2) {
    cout << "-1" << endl;
    return;
  }
  int l = 1, r = n;
  int arr[n + 5];
  for (int i = 1; i <= n; i++) arr[i] = i;
  if (a > b)
    for (int i = 1; i <= a; i++) swap(arr[r], arr[r - 1]), r -= 2;
  else if (b > a)
    for (int i = 1; i <= b; i++) swap(arr[l], arr[l + 1]), l += 2;
  else {
    if (b > 0)
      swap(arr[l], arr[l + 1]), l += 2, swap(arr[r], arr[r - 1]), r -= 2, b--;
    for (int i = 1; i <= b; i++) swap(arr[l], arr[l + 1]), l += 2;
  }
  for (int i = 1; i <= n; i++) cout << arr[i] << " ";
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
