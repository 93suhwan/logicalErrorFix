#include <bits/stdc++.h>
using namespace std;
int64_t mod;
void Rahul() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  if (a[0] == 1 && a.back() == 1) {
    cout << -1 << endl;
  } else {
    for (int i = 1; i <= n + 1; i++) cout << i << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) Rahul();
  return 0;
}
