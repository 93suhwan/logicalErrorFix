#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 500;
int arr[maxn];
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int l = 1, r = n;
  while (l + 1 <= n && arr[l] < arr[l + 1]) l++;
  while (r - 1 >= 1 && arr[r - 1] > arr[r]) r--;
  r = n - r + 1;
  if (l % 2 || r % 2)
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
  return 0;
}
