#include <bits/stdc++.h>
using namespace std;
const long long int mod = 109 + 7;
int main() {
  int t;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, m, s;
  cin >> n;
  vector<int> v(n);
  for (auto &a : v) cin >> a;
  long long int l = 0;
  while (l + 1 < n && v[l] < v[l + 1]) l++;
  long long int r = n - 1;
  while (r - 1 >= 0 && v[r] < v[r - 1]) r--;
  l++;
  r -= n;
  if (l % 2 || r % 2)
    cout << "Alice";
  else
    cout << "Bob";
  cout << endl;
  return 0;
}
