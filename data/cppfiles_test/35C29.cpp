#include <bits/stdc++.h>
using namespace std;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;
const long double PI = 3.14159265358979323846;
const long double E = 2.718281828459;
long long MOD = 1e9 + 7;
long long M(long long n) { return (n % MOD + MOD) % MOD; }
long long pow2(long long n) { return 1ll << n; }
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
const long long MX = 1e6 + 2;
const long long MAXN = MX;
vector<int> prime;
bool is_composite[MAXN];
vector<int> minDiv(MAXN);
void sieve(long long n) {
  std::fill(is_composite, is_composite + n, false);
  for (long long i = 2; i < n; ++i) {
    if (!is_composite[i]) {
      prime.push_back(i);
      minDiv[i] = i;
    }
    for (long long j = 0; j < prime.size() && i * prime[j] < n; ++j) {
      is_composite[i * prime[j]] = true;
      minDiv[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
}
unordered_map<int, stack<int>> suf;
int main(int argn, char **argv) {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  sieve(MX);
  ;
  int T = 1;
  for (long long(I) = (0); (I) <= ((T)-1); (I)++) {
    long long n;
    cin >> n;
    vector<int> a(n);
    for (long long(i) = (0); (i) <= ((n)-1); (i)++) cin >> a[i];
    string s;
    cin >> s;
    long long ans = 0;
    set<int> lim;
    lim.emplace(n);
    for (long long(i) = (n - 1); (i) >= (0); (i)--) {
      if (s[i] == '/' && a[i] > 1) lim.emplace(i);
      long long tmp = a[i];
      while (tmp > 1) {
        long long pr = minDiv[tmp], c = 0;
        while (minDiv[tmp] == pr) {
          tmp /= pr, c++;
        }
        if (s[i] == '*') {
          while (!suf[pr].empty() && c) {
            auto idx = suf[pr].top();
            c--, a[idx] /= pr;
            if (a[idx] % pr) suf[pr].pop();
            if (a[idx] == 1) lim.erase(idx);
          }
        } else {
          suf[pr].emplace(i);
        }
      };
      long long maxPos = *lim.begin(), earn = maxPos - i;
      ;
      ans += earn;
    }
    cout << ans << endl;
  }
  return 0;
}
