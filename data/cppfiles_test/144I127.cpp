#include <bits/stdc++.h>
using namespace std;
long long binpow(long long base, long long ex,
                 long long mod = (long long)1000000007) {
  long long ans = 1;
  base = base % mod;
  if (base == 0) {
    return 0;
  }
  while (ex > 0) {
    if (ex % 2 == 1) {
      ans = (ans * base) % mod;
    }
    base = (base * base) % mod;
    ex = ex / 2;
  }
  return ans;
}
void read(vector<long long> &arr, long long n) {
  if (arr.size() != n) {
    arr.assign(n, 0);
  }
  for (int i = 0; i < n; i++) cin >> arr[i];
}
inline long long min(long long a, long long b) {
  if (a > b) return b;
  return a;
}
inline long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
inline long long dif(long long a, long long b) {
  if (a > b) return a - b;
  return b - a;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
  long long k = gcd(a, b);
  return (a * b) / k;
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<vector<vector<long long>>> ans(k, vector<vector<long long>>(2));
  long long quo = n / m;
  long long rem = n % m;
  long long constant = k * ((n % m) * (n / m + 1));
  long long x = ((constant) + (n - (constant) % n)) / n - 1;
  long long a = (constant % n);
  vector<long long> arr(n, x);
  for (long long i = 0; (i) < long(a); (i)++) {
    arr[i]++;
  }
  for (int curr = 0; curr <= 4 * n; curr++) {
    int i = curr % n;
    for (int game = 0; game < k; game++) {
      if (arr[i] and ans[game][0].size() < (quo + 1) * rem) {
        arr[i]--;
        ans[game][0].push_back(i + 1);
      } else if (ans[game][1].size() < (quo) * (n - rem)) {
        ans[game][1].push_back(i + 1);
      }
    }
  }
  for (int game = 0; game < k; game++) {
    int up = 0;
    for (int count = 0; count < rem; count++) {
      cout << quo + 1 << " ";
      for (int i = 0; i <= quo; i++) {
        cout << ans[game][0][up] << " ";
        up++;
      }
      cout << endl;
    }
    int down = 0;
    for (int count = 0; count < (m - rem); count++) {
      cout << quo << " ";
      for (int i = 0; i < quo; i++) {
        cout << ans[game][1][down] << " ";
        down++;
      }
      cout << endl;
    }
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << showpoint;
  cout << setprecision(12);
  long long test_m = 1;
  cin >> test_m;
  while (test_m--) {
    solve();
  }
}
