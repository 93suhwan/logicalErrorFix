#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
void solve() {
  long long n;
  cin >> n;
  vector<int> A(n + 1, 0);
  vector<int> B(n + 1, 0);
  vector<pair<int, int>> problems(n);
  int i;
  int a, b;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    A[a]++;
    B[b]++;
    problems[i] = {a, b};
  }
  long long total = n * (n - 1) * (n - 2) / 6;
  for (i = 0; i < n; i++) {
    total -= (A[problems[i].first] - 1) * (B[problems[i].second] - 1);
  }
  cout << total << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
