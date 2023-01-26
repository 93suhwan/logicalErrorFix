#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
bool sortbysec(const pair<long long, char> &a, const pair<long long, char> &b) {
  return (a.second < b.second);
}
bool checksorted(vector<long long> a) {
  for (int i = 1; i < ((int)(a).size()); i++) {
    if (a[i - 1] > a[i]) {
      return false;
    }
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  vector<long long> temp(n);
  bool flag = 1;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long p = v[n - 1];
  long long m = *max_element((v).begin(), (v).end());
  if (v[n - 1] == m) {
    cout << 0;
    return;
  }
  for (long long i = n - 1; i >= 0 && p != m; i--) {
    if (v[i] > p) {
      p = v[i];
      ans++;
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt;
  cin >> tt;
  for (int i = 0; i < tt; i++) {
    solve();
    cout << endl;
  }
}
