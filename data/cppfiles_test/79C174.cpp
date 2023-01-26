#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
long long dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
char dir[] = {'U', 'R', 'D', 'L'};
bool isprime(long long n) {
  for (long long i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
void solve() {
  map<long long, long long> mp;
  mp[1] = 1, mp[4] = 1, mp[6] = 1, mp[8] = 1, mp[9] = 1;
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long cnt2 = 0, cntodd = 0;
  char c1, c2;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    if (mp[s[i] - '0']) {
      cout << 1 << "\n";
      cout << s[i];
      return;
    }
    v.push_back(s[i] - '0');
  }
  for (long long i = 0; i < v.size(); i++) {
    for (long long j = i + 1; j < v.size(); j++) {
      long long num = v[i] * 10 + v[j];
      if (!isprime(num)) {
        cout << 2 << "\n";
        cout << num;
        return;
      }
    }
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q = 1;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
