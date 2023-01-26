#include <bits/stdc++.h>
using namespace std;
vector<long long> divisors(long long n) {
  vector<long long> ans;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      ans.push_back(i);
      if (n / i != i) ans.push_back(n / i);
    }
  }
  ans.push_back(1);
  return ans;
}
void precision_print(long double n, long long p) {
  cout << fixed << setprecision(p) << n << '\n';
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    string temp = to_string(x1);
    long long a = ((long long)(temp).size());
    temp = to_string(x2);
    long long b = ((long long)(temp).size());
    if (a + p1 > b + p2) {
      cout << '>' << '\n';
      continue;
    }
    if (a + p1 < b + p2) {
      cout << '<' << '\n';
      continue;
    }
    if (p1 < p2)
      x2 *= pow(10, p2 - p1);
    else
      x1 *= pow(10, p1 - p2);
    if (x1 > x2)
      cout << ">\n";
    else if (x1 == x2)
      cout << "=\n";
    else
      cout << "<\n";
  }
  return 0;
}
