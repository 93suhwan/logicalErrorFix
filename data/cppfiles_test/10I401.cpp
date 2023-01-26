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
  for (auto& x : a) {
    m[x]++;
  }
  long long int cnt = 0;
  for (auto& x : m) {
    if (x.second < k) cnt++;
  }
  vector<long long int> ans[n + 1];
  long long int kak = 1;
  for (long long int i = 1; i <= n; i++) {
    if (m[i] >= k) {
      for (long long int j = 1; j <= k; j++) {
        ans[i].push_back(j);
      }
    } else if (m[i] >= 1 and cnt > 0) {
      ans[i].push_back(kak);
      kak++;
      if (kak == k) kak = 1;
    }
  }
  map<long long int, long long int> ind;
  for (auto& x : a) {
    if (m[x] >= k) {
      if (ind[x] > k - 1) {
        cout << 0 << " ";
        continue;
      }
      cout << ans[x][ind[x]] << " ";
      ind[x]++;
    } else if (ans[x].size() > 1) {
      if (ind[x] > 0) {
        cout << 0 << " ";
        continue;
      }
      cout << ans[x][ind[x]] << " ";
      ind[x]++;
    } else
      cout << 0 << " ";
  }
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
