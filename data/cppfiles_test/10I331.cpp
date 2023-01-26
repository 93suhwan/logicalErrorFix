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
  long long int n;
  cin >> n;
  long long int k;
  cin >> k;
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
  for (long long int i = 0; i <= n - 1; i++) {
    if (m[a[i]] >= k) {
      if (cnt[a[i]] == k) {
        ans[i] = 0;
        continue;
      }
      ans[i] = cnt[a[i]] + 1;
      cnt[a[i]]++;
    }
  }
  long long int sum = 0;
  map<long long int, long long int> temp;
  for (auto& x : m)
    if (x.second < k) sum += x.second;
  long long int c = sum / k;
  long long int kc = c;
  long long int kak = 1;
  for (long long int i = 0; i <= n - 1; i++) {
    if (m[a[i]] < k and c > 0) {
      temp[a[i]]++;
      kak++;
      if (kak == k + 1) kak = 1, c--;
    }
  }
  map<long long int, long long int> t2;
  map<long long int, long long int> ccc;
  long long int kk = 1;
  for (long long int i = 0; i <= n - 1; i++) {
    if (ans[i] == 0) {
      if (temp[a[i]] > 0 and kc > 0) {
        ans[i] = ccc[kk] + 1;
        ccc[kk]++;
        if (ccc[kk] == k) kk++, kc--;
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
