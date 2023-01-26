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
  string second;
  cin >> second;
  if ((int)second.length() % 2 == 0) {
    int i = ((int)second.length() / 2) - 1;
    int j = (int)second.length() - 1;
    while (i >= 0) {
      if (second[i] == second[j]) {
        i--;
        j--;
      } else {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
