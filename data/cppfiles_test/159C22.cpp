#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> sm_prime(1000006, 0);
unordered_map<int, long long> hash_prime;
mt19937_64 rng;
void print(vector<int> avoid) {
  cout << n - avoid.size() << "\n";
  for (int i = 1; i <= n; i++) {
    if (find(avoid.begin(), avoid.end(), i) == avoid.end()) {
      cout << i << " ";
    }
  }
  exit(0);
}
void solve() {
  cin >> n;
  vector<long long> num_hash(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    num_hash[i] = num_hash[i / sm_prime[i]] ^ hash_prime[sm_prime[i]];
  }
  vector<long long> fac_hash(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    fac_hash[i] = fac_hash[i - 1] ^ num_hash[i];
  }
  long long all_hash = 0;
  for (int i = 1; i <= n; i++) {
    all_hash ^= fac_hash[i];
  }
  if (all_hash == 0) {
    print({});
  }
  for (int i = 1; i <= n; i++) {
    if (all_hash == fac_hash[i]) {
      print({i});
    }
  }
  unordered_map<long long, int> index;
  for (int i = 1; i <= n; i++) {
    long long wanted = all_hash ^ fac_hash[i];
    if (index.count(wanted) > 0) {
      print({i, index[wanted]});
    }
    index[fac_hash[i]] = i;
  }
  print({2, (n - 1) / 2, n});
}
void pre() {
  vector<bool> is_prime(1000006, true);
  for (int i = 2; i < 1000006; i++) {
    if (is_prime[i]) {
      sm_prime[i] = i;
      hash_prime[i] = rng();
      if ((long long)i * i >= 1000006) continue;
      for (int j = i * i; j < 1000006; j += i) {
        if (is_prime[j]) {
          is_prime[j] = false;
          sm_prime[j] = i;
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  rng = mt19937_64(time(NULL));
  pre();
  int t = 1;
  while (t--) {
    solve();
  }
}
