#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
void solve() {
  int n, cnt = 0;
  cin >> n;
  int mod = n % 10;
  if (mod < 9)
    cnt = (n / 10);
  else
    cnt = (n / 10) + 1;
  cout << cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
