#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i].first = a[i];
    b[i].second = i;
  }
  sort(b.begin(), b.end());
  for (int i = 1; i < n; i++) {
    if (b[i].first == b[i - 1].first) {
      cout << "YES\n";
      return;
    }
  }
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    a[b[i].second] = i;
  }
  for (int i = 0; i < n; i++) {
    pos[a[i]] = i;
  }
  for (int i = 0; i < n - 2; i++) {
    if (a[i] == i)
      continue;
    else if (a[i] != n - 1 && a[i] != n - 2) {
      pos[a[i]] = pos[n - 1];
      pos[n - 1] = pos[i];
      a[pos[n - 1]] = n - 1;
      a[pos[a[i]]] = a[i];
    } else if (a[i] == n - 1) {
      pos[n - 1] = pos[n - 2];
      pos[n - 2] = pos[i];
      a[pos[n - 1]] = n - 1;
      a[pos[n - 2]] = n - 2;
    } else if (a[i] == n - 2) {
      pos[n - 2] = pos[n - 1];
      pos[n - 1] = pos[i];
      a[pos[n - 1]] = n - 1;
      a[pos[n - 2]] = n - 2;
    }
  }
  if (pos[n - 1] == n - 1) {
    cout << "YES\n";
  } else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
