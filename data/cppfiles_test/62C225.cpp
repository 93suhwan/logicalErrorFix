#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  iota(B.begin(), B.end(), 1);
  for (auto &x : A) cin >> x;
  if (A[0] == 1)
    B.insert(B.begin(), n + 1);
  else if (A[n - 1] == 0)
    B.push_back(n + 1);
  else {
    for (int(i) = int(0); i <= int(n - 2); i++)
      if (A[i] == 0 and A[i + 1] == 1) {
        B.insert(B.begin() + i + 1, n + 1);
        break;
      }
  }
  for (int(i) = int(0); i <= int(B.size() - 1); i++) cout << B[i] << " ";
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
