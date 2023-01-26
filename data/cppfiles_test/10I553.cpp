#include <bits/stdc++.h>
using namespace std;
long long factorial(long long n) {
  long long res = 1, i;
  for (i = 2; i <= n; i++) {
    res *= i;
    res = res % 1000000007;
  }
  return res;
}
vector<long long> digits(long long n) {
  vector<long long> v;
  while (n) {
    v.push_back(n % 10);
    n /= 10;
  }
  return v;
}
vector<long long> SieveOfEratosthenes(long long n) {
  std::vector<long long> v(n + 1, 0);
  vector<long long> vb(n + 1, 1);
  long long i, j;
  std::vector<long long> ans;
  for (i = 2; i <= n; i++) {
    if (vb[i] == 1) {
      v[i] = i;
      ans.push_back(i);
      for (j = i * i; j <= n; j += i) {
        if (vb[i] == 1) {
          v[j] = i;
        }
        vb[j] = 0;
      }
    }
  }
  return ans;
}
map<long long, long long> get_prime_exponent(long long n) {
  std::vector<long long> v = SieveOfEratosthenes(n);
  long long i;
  long long cur = v[n];
  long long count = 0;
  map<long long, long long> m;
  while (n > 1) {
    cur = v[n];
    count = 0;
    while (n > 1 && n % cur == 0) {
      count++;
      n /= cur;
    }
    m[cur] = count;
  }
  return m;
}
void solve() {
  long long i, j, k, t, n;
  cin >> n >> j;
  std::vector<long long> v;
  for (i = 0; i <= n - 1; i++) {
    cin >> t;
    v.push_back(t);
  }
  unordered_map<long long, long long> m;
  std::vector<long long> fin(n);
  long long ans = 0;
  long long color = 0;
  for (i = 0; i <= n - 1; i++) {
    if (m.find(v[i]) != m.end()) {
      if (m[v[i]] < j) {
        fin[i] = color % j;
        color++;
      } else {
        fin[i] = -1;
      }
      m[v[i]]++;
    } else {
      m[v[i]] = 1;
      fin[i] = color % (j);
      color++;
    }
  }
  for (i = n - 1; i >= 0; i--) {
    if (fin[i] == -1) {
      continue;
    } else if (fin[i] != j - 1) {
      fin[i] = -1;
      for (t = i - 1; t >= 0; t--) {
        if (fin[t] == j - 1) {
          goto X;
        } else {
          fin[t] = -1;
        }
      }
    } else
      break;
  }
X:;
  for (i = 0; i <= n - 1; i++) {
    if (fin[i] != -1) {
      cout << fin[i] + 1;
    } else
      cout << 0;
    cout << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
