#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b;
  cin >> a >> b;
  if (b > a) swap(a, b);
  vector<long long> ans;
  if ((a + b) % 2) {
    long long p = (a + b) / 2 + 1;
    long long mini = (a - p);
    long long maxi = p + b;
    long long i;
    for (i = mini; i <= maxi; i++) ans.push_back(i);
  } else {
    long long p = (a + b) / 2;
    long long mini = (a - p);
    long long maxi = p + b;
    long long i;
    for (i = mini; i <= maxi; i = i + 2) ans.push_back(i);
  }
  cout << ans.size() << endl;
  long long i;
  for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  for (long long ii = 1; ii <= t; ii++) {
    solve();
  }
}
