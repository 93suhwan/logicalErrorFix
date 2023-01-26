#include <bits/stdc++.h>
using namespace std;
long long gcd(long long A, long long B) { return (B == 0) ? A : gcd(B, A % B); }
long long lcm(long long A, long long B) { return A * B / gcd(A, B); }
const long long N = 2e6 + 10;
const long long NN = 1e9 + 10;
const long long mod = 1e9 + 7;
long long bmul(long long a, long long b) {
  long long ans = 0;
  while (b > 0) {
    if (b & 1) {
      ans = (ans + a) % mod;
    }
    a = (a + a) % mod;
    b >>= 1;
  }
  return ans;
}
long long bexpo(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = bmul(ans, a);
    }
    a = bmul(a, a);
    b >>= 1;
  }
  return ans;
}
long long hp[N + 10];
long long factormultiple[N + 10];
void precompute() {
  for (long long i = 2; i < N; i++) {
    if (hp[i] == 0) {
      for (long long j = i; j < N; j += i) {
        hp[j] = i;
      }
    }
  }
}
vector<long long> distinctpf(long long num) {
  vector<long long> ans;
  while (num > 1) {
    long long val = hp[num];
    while (num % val == 0) {
      num /= val;
    }
    ans.push_back(val);
  }
  return ans;
}
long long hsh[N];
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}
pair<bool, long long> check(vector<pair<long long, long long>>& arr,
                            long long x, long long l, long long r) {
  long long lll = x - 1;
  long long rr = x + 1;
  long long pos = 0;
  for (auto it : arr) {
    if (it.first == l and it.second == lll) {
      if (!(it.first == l and it.second == r)) {
        long long index = 0;
        for (auto itt : arr) {
          if (index == pos) {
            index++;
            continue;
          }
          if (itt.first == rr and itt.second == r) {
            return {true, x};
          }
          index++;
        }
      }
    }
    if (it.first == l and it.second == lll) {
      return {true, x};
    }
    if (it.first == rr and it.second == r) {
      return {true, x};
    }
    pos++;
  }
  return {false, -1};
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> arr(n);
  for (pair<long long, long long>& it : arr) {
    cin >> it.first >> it.second;
  }
  map<pair<long long, long long>, long long> m;
  for (auto it : arr) {
    long long l = it.first;
    long long r = it.second;
    if (l == r) {
      m[{l, r}] = l;
      continue;
    }
    for (long long i = l; i <= r; i++) {
      pair<bool, long long> tt = check(arr, i, l, r);
      if (tt.first) {
        m[{l, r}] = tt.second;
        break;
      }
    }
  }
  for (auto it : arr) {
    cout << it.first << " " << it.second << " " << m[{it.first, it.second}];
    cout << "\n";
    ;
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
}
