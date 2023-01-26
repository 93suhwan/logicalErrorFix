#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int solv() {
  int n;
  cin >> n;
  int a[n];
  int s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  if (s % n == 0)
    cout << "0\n";
  else
    cout << "1\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testcases = 1;
  cin >> testcases;
  while (testcases--) solv();
}
