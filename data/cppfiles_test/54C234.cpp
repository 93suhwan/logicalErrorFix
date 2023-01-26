#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b % a, a);
}
long long int my_pow(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long int half = my_pow(a, b / 2);
  long long int ans = (half * half);
  if (b % 2) {
    ans = (ans * a);
  }
  return ans;
}
long long int my_pow_mod_p(long long int a, long long int b, long long int p) {
  a = (a % p);
  if (b == 0) return 1;
  if (b == 1) return a % p;
  long long int half = my_pow_mod_p(a, b / 2, p);
  long long int ans = (half * half) % p;
  if (b % 2) {
    ans = (ans * a) % p;
  }
  return ans;
}
class combinatorics {
  long long int N;
  long long int P;
  vector<long long int> fact;
  void cal() {
    fact[0] = 1;
    fact[1] = 1;
    for (long long int i = 2; i < N; i++) {
      fact[i] = (i * fact[i - 1]) % P;
    }
  }

 public:
  combinatorics(long long int n1, long long int p1) {
    P = p1;
    N = max(n1 + 1, 2LL);
    fact.resize(N);
    cal();
  }
  long long int nPr(long long int n, long long int r) {
    if (n < r) {
      return 0;
    }
    long long int val = (fact[n] * my_pow_mod_p(fact[n - r], P - 2, P)) % P;
    return val;
  }
  long long int nCr(long long int n, long long int r) {
    if (n < r) {
      return 0;
    }
    long long int val = nPr(n, r);
    val = (val * my_pow_mod_p(fact[r], P - 2, P)) % P;
    return val;
  }
  long long int get_fact(long long int n) { return fact[n]; }
};
void print_vec(vector<long long int> &V, string name) {
  cout << name << " : " << endl;
  long long int n = V.size();
  for (long long int i = 0; i < n; i++) {
    cout << V[i] << " ";
  }
  cout << endl;
}
void handle_even(long long int n, long long int k) {
  long long int eq_val = my_pow_mod_p(2LL, n - 1, 1000000007);
  eq_val = (eq_val - 1 + 1000000007) % 1000000007;
  long long int gr_val = 1LL;
  long long int a = eq_val;
  long long int b = gr_val;
  long long int ans = (a + b) % 1000000007;
  for (long long int i = 1; i < k; i++) {
    long long int val1 = my_pow_mod_p(2LL, i, 1000000007);
    long long int val2 = my_pow_mod_p(val1, n, 1000000007);
    long long int curr_ans = val2;
    long long int val3 = (eq_val * ans) % 1000000007;
    ans = (curr_ans + val3) % 1000000007;
  }
  cout << ans << endl;
}
void handle_odd(long long int n, long long int k) {
  long long int val = my_pow_mod_p(2LL, n - 1, 1000000007);
  val = (val + 1) % 1000000007;
  val = my_pow_mod_p(val, k, 1000000007);
  cout << val << endl;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << 1 << endl;
    return;
  }
  if (n % 2 == 0)
    handle_even(n, k);
  else
    handle_odd(n, k);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
