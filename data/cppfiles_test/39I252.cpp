#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
int dx[2] = {
    -1,
    0,
};
int dy[2] = {0, -1};
int main(void) {
  int n;
  cin >> n;
  int x = 1000;
  vector<pair<int, int> > ans;
  for (int i = -n + 1; i <= n - 1; i++) {
    cout << "? ";
    for (int j = 0; j < n - 1; j++) cout << x + i << ' ';
    cout << x;
    cout << endl;
    int idx;
    cin >> idx;
    if (idx != 0) ans.push_back({i, idx});
  }
  ans.push_back({0, n});
  sort(ans.begin(), ans.end());
  vector<int> res(n + 1);
  int k = 1;
  for (int i = 1; i <= ans.size(); i++) res[ans[i - 1].second] = i;
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << res[i] << ' ';
}
