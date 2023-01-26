#include <bits/stdc++.h>
using namespace std;
template <typename T, typename S>
ostream& operator<<(ostream& out, const pair<T, S>& p) {
  out << "(" << p.first << " " << p.second << ")";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<vector<T> >& m) {
  for (int i = 0; i < m.size(); ++i) {
    out << m[i] << "\n";
  }
  return out;
}
template <typename H1>
ostream& show(ostream& out, const char* label, H1&& value) {
  return out << label << " = " << value << '\n';
}
template <typename H1, typename... T>
ostream& show(ostream& out, const char* label, H1&& value, T&&... rest) {
  const char* first_comma = strchr(label, ',');
  const char* left_parenthesis = strchr(label, '(');
  if (left_parenthesis != nullptr && left_parenthesis < first_comma) {
    const char* right_parenthesis = strchr(left_parenthesis, ')');
    assert(right_parenthesis != nullptr);
    const char* pcomma = strchr(right_parenthesis, ',');
    return show(out.write(label, pcomma - label) << " = " << value << ',',
                pcomma + 1, rest...);
  }
  return show(out.write(label, first_comma - label) << " = " << value << ',',
              first_comma + 1, rest...);
}
const int MAX_N = 200 + 2;
long long fact[MAX_N];
long long fact_inv[MAX_N];
int m, n, M;
long long dp[MAX_N][MAX_N][MAX_N];
long long power(long long a, int pow) {
  if (pow == 0) {
    return 1;
  }
  long long half = power(a, pow / 2);
  return ((half * half % M) * (pow & 1 ? a : 1)) % M;
}
void preprocess() {
  fact[0] = 1;
  fact_inv[0] = 1;
  for (int i = 1; i < MAX_N; ++i) {
    fact[i] = fact[i - 1] * i % M;
    fact_inv[i] = power(fact[i], M - 2);
  }
}
long long solve(int i, int k, int s) {
  if (k > n + 1) {
    return 0;
  }
  if (k == n + 1) {
    return fact_inv[n - i + 1];
  }
  if (i == n) {
    return 1;
  }
  long long& ans = dp[i][k][s];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  const int min_t = max(0, (k + 1 - m) * (n - i) + s - 2 * m + n + 1);
  const int max_t = min(n - i, (k * m - s - m * (i - 1)) / k);
  for (int t = min_t; t <= max_t; ++t) {
    ans += fact_inv[t] * solve(i + t, k + 1, s + (k - m) * t);
    ans %= M;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> M;
  preprocess();
  long long ans = 0;
  for (m = (n + 2) / 2; m <= n; ++m) {
    memset(dp, -1, sizeof dp);
    const int min_t = max(1, 2 * (n - m));
    const int max_t = min(n - 1, m);
    for (int t = min_t; t <= max_t; ++t) {
      ans += fact_inv[t] * solve(1 + t, m + 1, 0);
      ans %= M;
    }
  }
  cout << (ans * fact[n] + 2) % M;
}
