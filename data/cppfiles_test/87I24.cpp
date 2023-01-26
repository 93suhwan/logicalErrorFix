#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> arr(m);
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
  }
  vector<long long int> temp;
  temp = arr;
  sort(temp.begin(), temp.end());
  vector<long long int> ans(m);
  long long int sum = 0;
  for (int i = 0; i < m; i++) {
    int ind = upper_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
    ind -= 1;
    ans[ind] = 1;
    for (int j = 0; j < ind; j++) {
      if (ans[j] == 1) sum += 1;
    }
  }
  cout << sum << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
