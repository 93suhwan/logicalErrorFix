#include <bits/stdc++.h>
using namespace std;
void print_err() { cerr << "\n"; }
template <class T, class... Arg>
void print_err(T x, Arg &&...args) {
  cerr << x << " ";
  print_err(args...);
}
template <class T>
void print_container(T &cont) {
  for (auto iter : cont) {
    cerr << iter << " ";
  }
  cerr << "\n";
}
int mod = 998244353;
long long ceil(long long a, long long b) { return (a + b - 1) / b; }
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
vector<int> d4x{0, 0, 1, -1};
vector<int> d4y{-1, 1, 0, 0};
vector<int> d8x{0, 0, 1, -1, 1, 1, -1, -1};
vector<int> d8y{1, -1, 0, 0, -1, 1, 1, -1};
vector<long long> B(1e5 + 1, -1), C(1e5 + 1, -1);
void solve(int test) {
  ;
  int n;
  cin >> n;
  vector<int> A(n);
  for (int &a : A) {
    cin >> a;
  }
  long long ans = 0;
  vector<long long> dp1, dp2;
  int j;
  long long val;
  for (int i = n - 1; i >= 0; --i) {
    for (auto iter : dp1) {
      j = iter;
      val = B[j];
      if (val < 0) {
        ;
      }
      if (val > 0) {
        if (j >= A[i]) {
          if (C[A[i]] == -1) {
            dp2.push_back(A[i]);
            C[A[i]] = val;
            C[A[i]] %= mod;
          } else {
            C[A[i]] += val;
            C[A[i]] %= mod;
          }
        } else {
          if (C[A[i] / ceil(A[i], j)] == -1) {
            dp2.push_back(A[i] / ceil(A[i], j));
            C[A[i] / ceil(A[i], j)] = val;
            ans += (i + 1) * (ceil(A[i], j) - 1) * val;
            ans %= mod;
            C[A[i] / ceil(A[i], j)] %= mod;
          } else {
            C[A[i] / ceil(A[i], j)] += val;
            ans += (i + 1) * (ceil(A[i], j) - 1) * val;
            ans %= mod;
            C[A[i] / ceil(A[i], j)] %= mod;
          }
        }
      }
      B[j] = -1;
    }
    dp1.clear();
    swap(dp1, dp2);
    swap(B, C);
    if (B[A[i]] == -1) {
      dp1.push_back(A[i]);
      B[A[i]] = 1;
    } else {
      B[A[i]]++;
      B[A[i]] %= mod;
    }
  }
  for (int j : dp1) {
    B[j] = -1;
  }
  cout << ans << endl;
}
int main() {
  int i = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_cases;
  cin >> test_cases;
  for (i = 1; i <= test_cases; ++i) solve(i);
  return 0;
}
