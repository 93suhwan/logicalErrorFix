#include <bits/stdc++.h>
using namespace std;
int A, B, a, b, n;
vector<int> v;
int Abs(int x) { return x > 0 ? x : -x; }
bool check(int x) {
  int dist = max(Abs(A - a), Abs(B - b));
  if (x < dist) return false;
  if (x > dist + min(a, b) * 2) return false;
  return ((x - dist) % 2 == 0);
}
void solve() {
  cin >> a >> b;
  n = a + b;
  A = n / 2, B = n - A;
  for (int i = 0; i <= n; i++) {
    if (check(i)) {
      v.push_back(i);
    }
  }
  swap(A, B);
  for (int i = 0; i <= n; i++) {
    if (check(i)) {
      v.push_back(i);
    }
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  cout << v.size() << "\n";
  for (auto a : v) {
    cout << a << " ";
  }
  cout << "\n";
  v.clear();
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
