#include <bits/stdc++.h>
using namespace std;
const long long large = 1e10;
const long long remi = 1000000007;
const long long remi2 = 998244353;
const long long inf = 1e18 + 1e17 + 1e16 + 1e15 + 1e14;
vector<vector<int> > g;
vector<int> vis;
long long PowI(long long a, long long b, long long m) {
  long long ans = 1 % m;
  while (b > 0) {
    if (b % 2) ans = (((ans % m) * (a % m)) % m);
    a = (((a % m) * (a % m)) % m);
    b = (long long)(b / ((long long)2));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j;
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<vector<long long> > v(n);
    vector<pair<long long, long long> > mn;
    long long sum = 0;
    for (i = 0; i < n; i++) {
      long long k;
      cin >> k;
      long long mini = 0;
      for (j = 0; j < k; j++) {
        long long num;
        cin >> num;
        v[i].push_back(num);
        mini = max(mini, num - j + 1);
      }
      mn.push_back({mini, k});
    }
    sort(mn.begin(), mn.end());
    long long ans = mn[0].first;
    long long power = mn[0].first;
    for (i = 1; i < n; i++) {
      power += mn[i - 1].second;
      if (power < mn[i].first) {
        long long diff = mn[i].first - power;
        ans += diff;
        power += diff;
      }
    }
    cout << ans << "\n";
  }
}
