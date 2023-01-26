#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  for (long long i = (1); i <= (n); i++) cin >> a[i];
  vector<long long> b = a;
  sort(begin(b) + 1, end(b));
  map<long long, long long> pos;
  for (long long i = (1); i <= (n); i++) {
    if (pos[a[i]] == 0)
      pos[a[i]] = i;
    else {
      cout << "YES" << endl;
      return;
    }
  }
  long long ans = 0;
  for (long long i = (1); i <= (n); i++)
    if (a[i] != b[i]) {
      swap(a[i], a[pos[b[i]]]);
      swap(pos[a[i]], pos[b[i]]);
      ans++;
    }
  cout << (ans % 2 == 0 ? "YES" : "NO") << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
