#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int l = 0;
  while (l + 1 < n and a[l] < a[l + 1]) ++l;
  int r = n - 1;
  while (r - 1 >= 0 and a[r] < a[r - 1]) --r;
  l = l + 1;
  r = n - r;
  if (l % 2 or r % 2)
    cout << "Alice";
  else
    cout << "Bob";
  return 0;
}
