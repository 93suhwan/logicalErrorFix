#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int n, alice = 0, bob = 0;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  if (n % 2 != 0)
    cout << "Alice"
         << "\n";
  else
    cout << "Bob"
         << "\n";
  return 0;
}
