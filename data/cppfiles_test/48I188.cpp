#include <bits/stdc++.h>
using namespace std;
void solvetask() {
  int n;
  cin >> n;
  vector<int> a(n), b;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  b = a;
  sort(b.begin(), b.end());
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += a[i] != b[i];
  }
  if (cnt % 3 == 2 && cnt >= n - 1)
    cout << "NO" << '\n';
  else
    cout << "YES" << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solvetask();
}
