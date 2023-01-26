#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
long long int maxxx(long long int n1, long long int n2, long long int n3) {
  long long int maxim = 0;
  if (n1 >= n2 && n1 >= n3)
    maxim = n1;
  else if (n2 >= n1 && n2 >= n3)
    maxim = n2;
  else if (n3 >= n1 && n3 >= n2)
    maxim = n3;
  return maxim;
}
long long int ceil(long long int a, long long int x) {
  if (a % x == 0)
    return a / x;
  else
    return a / x + 1;
}
int modexpo(int x, int n, int m) {
  if (n == 0) return 1 % m;
  int u = modexpo(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2 == 1) u = (u * x) % m;
  return u;
}
int pow(int a, int b) {
  if (!b) return 1;
  long long temp = pow(a, b / 2);
  temp = (temp * temp);
  if (b % 2) return (a * temp);
  return temp;
}
vector<long long int> CALCfactor(long long int n) {
  vector<long long int> factor;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        factor.push_back(i);
      else
        factor.push_back(i), factor.push_back(n / i);
    }
  }
  return factor;
}
vector<long long int> sieve(long long int n) {
  vector<long long int> seive(n + 1, 1), prime;
  for (int i = 2; i * i <= n; i++) {
    if (seive[i] == 1)
      for (int j = i * i; j <= n; j += i) seive[j] = 0;
  }
  for (long long int i = 2; i <= n; i++) {
    if (seive[i] == 1) prime.push_back(i);
  }
  return prime;
}
vector<long long int> CALCprimeFACTOR(long long int n) {
  vector<long long int> ans;
  while (n % 2 == 0) {
    ans.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      ans.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) ans.push_back(n);
  return ans;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, flag = 0, sum1 = 0, sum2 = 0, t11 = 0, t1q = 0, t21 = 0,
                     t2q = 0, best1 = 0, best2 = 0, worst1 = 0, worst2 = 0,
                     best = 0, worst = 0, c1 = 5, c2 = 5;
    string s;
    cin >> s;
    string s1, s2;
    s1 = s;
    s2 = s;
    vector<char> team1;
    vector<char> team2;
    for (long long int i = 0; i < 10; i++) {
      if (i % 2 == 0) {
        if (s[i] == '?') s1[i] = '1';
      } else {
        if (s[i] == '?') s1[i] = '0';
      }
    }
    for (long long int i = 0; i < 10; i++) {
      if (i % 2 == 0) {
        c1--;
        if (s1[i] == '1') {
          t11++;
        }
        if ((t11 - t21) > c2 || (t21 - t11) > c1) {
          flag = 1;
          sum1 = i + 1;
          break;
        }
      } else {
        c2--;
        if (s1[i] == '1') {
          t21++;
        }
        if (abs((t11 - t21) > c2 || (t21 - t11) > c1)) {
          flag = 1;
          sum1 = i + 1;
          break;
        }
      }
    }
    t11 = 0, t21 = 0, c1 = 5, c2 = 5;
    for (long long int i = 0; i < 10; i++) {
      if (i % 2 != 0) {
        if (s[i] == '?') s2[i] = '1';
      } else {
        if (s[i] == '?') s2[i] = '0';
      }
    }
    for (long long int i = 0; i < 10; i++) {
      if (i % 2 == 0) {
        c1--;
        if (s2[i] == '1') {
          t11++;
        }
        if ((t11 - t21) > c2 || (t21 - t11) > c1) {
          flag = 1;
          sum2 = i + 1;
          break;
        }
      } else {
        c2--;
        if (s2[i] == '1') {
          t21++;
        }
        if ((t11 - t21) > c2 || (t21 - t11) > c1) {
          flag = 1;
          sum2 = i + 1;
          break;
        }
      }
    }
    if (sum1 == 0) sum1 = 10;
    if (sum2 == 0) sum2 = 10;
    cout << min(sum1, sum2) << "\n";
  }
}
