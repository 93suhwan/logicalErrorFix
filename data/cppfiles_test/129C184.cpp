#include <bits/stdc++.h>
using namespace std;
long long int Mod = 1e9 + 7;
vector<bool> status(1e6 + 1, 1);
vector<long long int> primes;
void test_case() {
  int n, x;
  cin >> n;
  int hash[n + 1];
  memset(hash, 0, sizeof hash);
  vector<int> a;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x <= n)
      hash[x]++;
    else
      a.push_back(x);
  }
  int ans[n + 1];
  memset(ans, 0, sizeof ans);
  for (int i = 1; i < n + 1; i++) {
    if (hash[i] > 0) {
      ans[i] = i;
      hash[i]--;
    }
    while (hash[i] > 0) {
      a.push_back(i);
      hash[i]--;
    }
  }
  int j = 0, cnt = a.size();
  sort(a.begin(), a.end());
  for (int i = 1; i < n + 1; i++) {
    if (ans[i] == 0) {
      if (a[j] >= 2 * i + 1) {
        ans[i] = i;
        j++;
      } else {
        cout << -1 << '\n';
        return;
      }
    }
  }
  cout << cnt << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    test_case();
  }
}
