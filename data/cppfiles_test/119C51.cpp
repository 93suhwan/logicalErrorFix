#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int INF = 1e9;
vector<long long int> sieve(long long int n) {
  int* arr = new int[n + 1]();
  vector<long long int> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long int modMul(long long int x, long long int y) {
  x %= mod, y %= mod;
  return (x * 1ll * y) % mod;
}
long long int powM(long long int x, long long int y) {
  if (y == 0) {
    return 1;
  } else if (y % 2 == 0) {
    long long int _tmp = powM(x, y / 2);
    return modMul(_tmp, _tmp);
  } else {
    return modMul(x, powM(x, y - 1));
  }
}
long long int binary_search(vector<long long int> v, long long int ans) {
  long long int lo = 0;
  long long int hi = v.size() - 1;
  long long int mid;
  while (lo <= hi) {
    mid = (hi + lo) / 2;
    if (v[mid] == ans) {
      return mid;
    } else if (v[mid] < ans) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return -1;
}
void solve() {
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    long long int sum = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> v[i];
      sum += v[i];
    }
    if (sum % n == 0) {
      cout << 0 << "\n";
    } else {
      cout << 1 << "\n";
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
