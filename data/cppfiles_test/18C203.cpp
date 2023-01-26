#include <bits/stdc++.h>
using namespace std;
bool check(long long int x1, long long int y1, long long int x2,
           long long int y2) {
  if (x1 > y1) swap(x1, y1);
  if (x2 > y2) swap(x2, y2);
  if (x2 > x1 && x2 < y1 && y2 > y1) return true;
  if (x2 < x1 && y2 > x1 && y2 < y1) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int x[n], y[n];
    map<int, int> used;
    for (int i = 0; i < k; i++) {
      cin >> x[i] >> y[i];
      used[x[i]] = 1;
      used[y[i]] = 1;
    }
    vector<int> rem;
    for (int i = 1; i <= 2 * n; i++) {
      if (used[i] == 0) rem.push_back(i);
    }
    for (int i = 0, j = k; i < rem.size() / 2; i++, j++) {
      x[j] = rem[i];
      y[j] = rem[i + rem.size() / 2];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (check(x[i], y[i], x[j], y[j])) ans++;
      }
    }
    cout << ans << endl;
  }
}
