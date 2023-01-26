#include <bits/stdc++.h>
using namespace std;
struct compare {
  bool operator()(const pair<long long, long long> &a,
                  const pair<long long, long long> &b) {
    return a.first > b.first;
  }
};
bool comp(const pair<long long, long long> &a,
          const pair<long long, long long> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}
bool compp(const pair<long long, long long> &a,
           const pair<long long, long long> &b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long mod_power(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long temp = mod_power(a, b / 2);
  temp %= 998244353;
  temp *= temp;
  temp %= 998244353;
  if (b % 2 == 1) {
    temp *= a;
    temp %= 998244353;
  }
  return temp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> f(n), c(n);
    long long ef = 0, ec = 0, ac = 0;
    long long totf = 0;
    long long totc = 0;
    for (long long i = 0; i < n; i++) {
      cin >> f[i];
      cin >> c[i];
      totf += f[i];
      totc += c[i];
      if (f[i] >= m) {
        ef += m;
        ac += min(m, c[i]);
      } else {
        ef += f[i];
        ec += m - f[i];
        ac += f[i];
      }
    }
    totf -= ef;
    totc -= ec;
    long long ck = 0;
    if (totf > totc) {
      long long ck = 0;
    } else {
      ck = min((totc - totf) / 2, ac);
    }
    totf += ef;
    totc += ec;
    long long ansss = 0;
    ef = 0;
    ec = 0;
    vector<pair<long long, long long> > answer;
    for (long long i = 0; i < n; i++) {
      ef = min(m, f[i]);
      ec = max(0ll, m - f[i]);
      ac = c[i] - ec;
      if (ck) {
        long long mm = 0;
        mm = min(min(ac, f[i]), min(ck, m));
        ck -= mm;
        ec += mm;
        ef -= mm;
      }
      totf -= ef;
      totc -= ec;
      answer.push_back(make_pair(ef, ec));
    }
    cout << abs(totf - totc) << "\n";
    for (auto itr : answer) {
      cout << itr.first << " " << itr.second << "\n";
    }
  }
  return 0;
}
