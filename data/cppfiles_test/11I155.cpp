#include <bits/stdc++.h>
using namespace std;
int z;
const int N = 1e6;
vector<long long> primes;
vector<bool> isprime(N + 1, true);
vector<int> factors;
vector<long long> fact(1e6, 1);
int prime_fact[N + 1];
void sieve() {
  isprime[0] = false;
  isprime[1] = false;
  for (long long i = 2; i <= N; i++) {
    if (isprime[i]) {
      primes.push_back(i);
      for (long long j = i * i; j <= N; j += i) {
        isprime[j] = false;
      }
    }
  }
}
bool ifprime(long long n) {
  if (n <= 1e6) {
    return (isprime[n]);
  } else {
    for (auto i : primes) {
      if (i > sqrt(n)) return true;
      if (n % i == 0) return false;
    }
    return true;
  }
}
int gcd(long long a, long long b) {
  if (b == 0) return a;
  return (gcd(b, a % b));
}
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
long long primefactors(long long n) {
  long long index = 0;
  long long pf = primes[index];
  long long cnt = 0;
  while (pf * pf <= n) {
    while (n % pf == 0) {
      n = n / pf;
      factors.push_back(pf);
      cnt++;
    }
    pf = primes[++index];
  }
  if (n != 1) {
    factors.push_back(n);
    cnt++;
  }
  return cnt;
}
vector<long long> factorial(int n) {
  for (int i = 2; i <= n; i++) {
    fact[i] = i * fact[i - 1];
  }
  return (fact);
}
long long power(long long base, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n % 2 != 0) {
      res = res * base;
      n = n - 1;
    } else {
      base = base * base;
      n = n / 2;
    }
  }
  return res;
}
void sieve_prime_factorization() {
  for (int i = 1; i <= N; i++) {
    prime_fact[i] = -1;
  }
  for (int i = 1; i * i <= N; i++) {
    if (prime_fact[i] == -1) {
      for (int j = i * i; j <= N; j += i) {
        if (prime_fact[j] == -1) {
          prime_fact[j] = i;
        }
      }
    }
  }
}
int count_set_bits(long long n) {
  int cnt = 0;
  while (n > 0) {
    if (n & 1) {
      cnt++;
    }
    n = n >> 1;
  }
  return cnt;
}
bool check_jth_bit(long long n, int j) { return (n & (1 << j)); }
long long set_jth_bit(long long n, int j) { return (n | (1 << j)); }
long long unset_jth_bit(long long n, int j) { return (n & ~(1 << j)); }
long long flip_jth_bit(long long n, int j) { return (n ^ (1 << j)); }
long long poweroftwo(long long n) { return (n && !(n & (n - 1))); }
void solve1() {
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  int arr[200001];
  for (int i = 0; i < 200001; i++) {
    arr[i] = m;
  }
  for (int i = 0; i < n; i++) {
    if (arr[a[i]] > 0) {
      a[i] = arr[a[i]];
      arr[a[i]]--;
    } else {
      a[i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != 0) {
      cnt++;
    }
  }
  int d = cnt % m;
  int maxm = cnt / m;
  for (int i = 0; i < n; i++) {
  }
}
int cal(int n, int **arr, int ind) {
  vector<int> v;
  int cnt = 0;
  int cnt_a = 0;
  int cnt_sum = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < 5; j++) {
      if (j != ind) sum += arr[i][j];
    }
    if (sum < arr[i][ind]) {
      cnt++;
      cnt_a += arr[i][ind];
      cnt_sum += sum;
    } else {
      v.push_back(sum - arr[i][ind]);
    }
  }
  sort(v.begin(), v.end());
  int kk = 0;
  while (cnt_a > cnt_sum) {
    cnt_sum += v[kk++];
    if (cnt_a > cnt_sum) {
      cnt++;
    } else {
      break;
    }
  }
  return cnt;
}
void solve() {
  int n;
  cin >> n;
  int **arr = new int *[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new int[5];
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int cnt1 = std::count(s.begin(), s.end(), 'a');
    int cnt2 = std::count(s.begin(), s.end(), 'b');
    int cnt3 = std::count(s.begin(), s.end(), 'c');
    int cnt4 = std::count(s.begin(), s.end(), 'd');
    int cnt5 = std::count(s.begin(), s.end(), 'e');
    arr[i][0] = cnt1;
    arr[i][1] = cnt2;
    arr[i][2] = cnt3;
    arr[i][3] = cnt4;
    arr[i][4] = cnt5;
  }
  int ans1 = cal(n, arr, 0);
  int ans2 = cal(n, arr, 1);
  int ans3 = cal(n, arr, 2);
  int ans4 = cal(n, arr, 3);
  int ans5 = cal(n, arr, 4);
  vector<int> v1;
  v1.push_back(ans1);
  v1.push_back(ans2);
  v1.push_back(ans3);
  v1.push_back(ans4);
  v1.push_back(ans5);
  sort(v1.begin(), v1.end());
  cout << v1[4] << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
