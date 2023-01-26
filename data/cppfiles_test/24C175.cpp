#include <bits/stdc++.h>
using namespace std;
const long long int M = 1000000007;
const long long int N = 1e5 + 1;
double PI = 2 * acos(0.0);
vector<long long int> isprime(N, true);
vector<long long int> prime;
vector<long long int> spf(N);
void seive() {
  isprime[0] = isprime[1] = false;
  for (long long int i = 2; i < N; i++) {
    if (isprime[i]) {
      prime.push_back(i);
      spf[i] = i;
    }
    for (long long int j = 0; j < (long long int)prime.size() &&
                              i * prime[j] < N && prime[j] <= spf[i];
         j++) {
      isprime[i * prime[j]] = false;
      spf[i * prime[j]] = prime[j];
    }
  }
}
vector<long long int> getPrimeFacts(long long int x) {
  vector<long long int> ret;
  while (x != 1) {
    ret.push_back(spf[x]);
    x = x / spf[x];
  }
  return ret;
}
long long int fast_pow(long long int a, long long int p) {
  long long int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % M;
      p /= 2;
    } else {
      res = res * 1ll * a % M;
      p--;
    }
  }
  return res;
}
long long int modDiv(long long int a, long long int b) {
  return a * fast_pow(b, M - 2) % M;
}
long long int modSub(long long int a, long long int b) {
  return ((a - b) % M + M) % M;
}
long long int fact(long long int n) {
  long long int res = 1;
  for (long long int i = 1; i <= n; i++) {
    res = res * 1ll * i % M;
  }
  return res;
}
long long int ncr(long long int n, long long int k) {
  return fact(n) * 1ll * fast_pow(fact(k), M - 2) % M * 1ll *
         fast_pow(fact(n - k), M - 2) % M;
}
bool isPowerOfTwo(long long int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
long long int strtoint(string s) {
  stringstream geek(s);
  long long int x = 0;
  geek >> x;
  return x;
}
void getVec(vector<long long int>& v, long long int n) {
  for (long long int i = 0; i < n; i++) {
    long long int a;
    cin >> a;
    v.push_back(a);
  }
}
unsigned long long int getFirstSetBitPos(long long int n) {
  return log2(n & -n) + 1;
}
void solve() {
  long long int n;
  cin >> n;
  if (n < 10) {
    if (n == 9)
      cout << 1;
    else
      cout << 0;
    return;
  }
  long long int ans = n / 10;
  if (n % 10 == 9) ans++;
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tes = 1;
  cin >> tes;
  while (tes--) {
    solve();
    cout << "\n";
  }
}
