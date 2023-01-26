#include <bits/stdc++.h>
using namespace std;
stack<int> st;
queue<int> q;
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> mpq;
void solve() {
  int n, s;
  cin >> n >> s;
  int mid = ceil(double(n) / 2.0);
  int elem = n - mid + 1;
  cout << s / elem << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
