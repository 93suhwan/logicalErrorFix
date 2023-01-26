#include <bits/stdc++.h>
using namespace std;
long long int hcf(long long int a, long long int b) {
  if (b == 0) return a;
  return hcf(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / hcf(a, b);
}
bool isprime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a;
  for (long long int i = 1; i <= n; i++) {
    long long int qq;
    cin >> qq;
    a.push_back(qq);
  }
  map<long long int, long long int> m;
  for (auto& x : a) m[x]++;
  vector<long long int> ans(n, 0);
  map<long long int, long long int> cnt;
  vector<long long int> temp;
  for (long long int i = 0; i <= n - 1; i++) {
    if (m[a[i]] >= k and cnt[a[i]] < k) {
      ans[i] = cnt[a[i]] + 1;
      cnt[a[i]]++;
    } else if (m[a[i]] < k)
      temp.push_back(a[i]);
  }
  if (temp.size() == 0) {
    for (auto& x : ans) cout << x << " ";
    cout << "\n";
    return;
  }
  sort(temp.begin(), temp.end());
  long long int c = temp.size() / k;
  map<long long int, vector<long long int> > final;
  for (long long int i = 0; i <= (c * k) - 1; i++) {
    long long int t = (i + 1) % k;
    if (t == 0) t = k;
    final[temp[i]].push_back(t);
  }
  for (long long int i = 0; i <= n - 1; i++) {
    if (ans[i] == 0) {
      if (final[a[i]].size() > 0) {
        ans[i] = final[a[i]].back();
        final[a[i]].pop_back();
      }
    }
  }
  for (auto& x : ans) cout << x << " ";
  cout << "\n";
}
void onlinejudge() {}
int main() {
  onlinejudge();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int ttt;
  ttt = 1;
  cin >> ttt;
  cout << fixed << setprecision(16);
  while (ttt--) solve();
  return 0;
}
