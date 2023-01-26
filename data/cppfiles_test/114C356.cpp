#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
void removeallsame(vector<long long>& vec, long long elem) {
  vec.erase(remove(vec.begin(), vec.end(), elem), vec.end());
}
void solve() {
  long long n, a = 0;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end(), greater<long long>());
  for (long long i = 0; a < n / 2; i++) {
    cout << v[i] << " " << v[n - 1] << "\n";
    a += 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt;
  cin >> tt;
  for (int i = 0; i < tt; i++) {
    solve();
    cout << '\n';
  }
}
