#include <bits/stdc++.h>
using namespace std;
const int maxk = 1e3 + 4;
vector<int> values(maxk, 0);
void solve() {
  int k;
  cin >> k;
  cout << values[k - 1] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int count = 1;
  for (int i = 0; i < maxk; i++) {
    while (count % 3 == 0 || count % 10 == 3) {
      count++;
    }
    values[i] = count;
    count++;
  }
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
