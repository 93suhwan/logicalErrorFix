#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
vector<int> ar[N];
map<int, int> mp, mp2;
int tt = 0;
int vis[N];
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[0] = (a[0] & a[i]);
  }
  cout << a[0] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int te;
  cin >> te;
  while (te--) {
    solve();
  }
}
