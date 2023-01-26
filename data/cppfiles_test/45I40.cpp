#include <bits/stdc++.h>
using namespace std;
map<long long, long long> fib;
bool isprime(int n) {
  int cnt = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      cnt += 2;
      if (i * i == n) {
        cnt--;
      }
    }
  }
  if (cnt == 2)
    return true;
  else
    return false;
}
int XOR(int n) {
  int ans;
  if (n % 4 == 0) {
    ans = 0;
  } else if (n % 2 == 0) {
    ans = 1;
  } else {
    if (abs(n - 1) % 4 == 0) {
      ans = n - 1;
    } else {
      ans = n;
    }
  }
  return ans;
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int height = 1;
  int flag = -1;
  if (v[0] == 1) {
    flag = 1;
  } else {
    flag = 0;
  }
  for (int i = 1; i < n; i++) {
    if (flag == 0 && v[i] == 0) {
      cout << -1 << endl;
      return;
    } else if (flag == 1 && v[i] == 1) {
      height += 5;
    } else if (v[i] == 1) {
      height += 1;
    }
    flag = v[i];
  }
  cout << height << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
