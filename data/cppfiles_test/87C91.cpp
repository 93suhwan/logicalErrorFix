#include <bits/stdc++.h>
using namespace std;
string apb = "abcdefghijklmnopqrstuvwxyz";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
long long pd = 1000000007;
long long tc;
void solve() {
  int n, m;
  cin >> n >> m;
  pair<int, int> a[m + 10];
  int b[m + 10];
  for (int i = 1; i <= m; i++) {
    cin >> a[i].first;
    a[i].second = -i;
    b[i] = a[i].first;
  }
  sort(a + 1, a + 1 + m);
  int seat[m + 10];
  for (int i = 1; i <= m; i++) seat[-a[i].second] = i;
  int kq = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j < i; j++) {
      if (seat[j] <= seat[i]) kq++;
    }
  }
  cout << kq << endl;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while (tc--) solve();
}
