#include <bits/stdc++.h>
using namespace std;
long long n, a[200200], k, b, c;
vector<int> v;
bool prime[1000100];
void sieve() {
  int i;
  for (i = 1; i <= 100010; i++) {
    prime[i] = 1;
  }
  prime[1] = 0;
  i = 1;
  for (i = 1; i <= 1000; i++) {
    if (prime[i] == 1) {
      v.push_back(i);
      for (int j = i * i; j <= 100010; j += i) {
        prime[j] = 0;
      }
    }
  }
}
void solve() {
  cin >> n;
  int i = 0;
  int cnt = 0;
  for (i; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    bool can = false;
    for (int j = 0; j < v.size() and v[j] <= i + 2; j++) {
      if (a[i] % v[j] != 0) can = true;
    }
    if (can) {
      cnt++;
    }
  }
  if (cnt == n)
    cout << "YES";
  else
    cout << "NO";
}
int main() {
  sieve();
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
