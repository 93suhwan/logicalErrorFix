#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
long long m;
bool CMP(pair<int, int> x, pair<int, int> y) {
  int temp, temp2;
  temp = (x.second) / x.first;
  if ((x.second) % x.first != 0) {
    temp++;
  }
  temp2 = (y.second) / y.first;
  if ((y.second) % y.first != 0) {
    temp2++;
  }
  return temp < temp2;
}
void solve(int param) {
  long long n;
  cin >> n;
  long long v[105];
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    ans = max(ans, v[i] - i);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  int j = t;
  while (t) {
    solve(t);
    --t;
  }
  return 0;
}
