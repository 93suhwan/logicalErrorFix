#include <bits/stdc++.h>
using namespace std;
int lg2(const int &x) { return 31 - __builtin_clz(x); }
long long int lg2(const long long int &x) { return 63 - __builtin_clzll(x); }
string alpha = "abcdefghijklmnopqrstuvwxyz";
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s;
int t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int ans = 0;
    int cur = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (v[i] > cur) {
        ans++;
        cur = v[i];
      }
    }
    cout << ans << '\n';
  }
}
