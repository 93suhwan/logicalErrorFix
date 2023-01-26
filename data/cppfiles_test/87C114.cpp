#include <bits/stdc++.h>
using namespace std;
bool cmp(int &a, int &b) { return a > b; }
void solve() {
  int n;
  cin >> n;
  long long int maxi = 0;
  for (int i = 1; i <= n; i++) {
    long long int k;
    cin >> k;
    maxi = max(maxi, k - i);
  }
  cout << maxi;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int l;
  cin >> l;
  while (l--) {
    solve();
    cout << endl;
  }
  return 0;
}
