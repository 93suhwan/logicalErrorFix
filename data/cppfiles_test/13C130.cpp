#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long mod1 = 1e12 + 7;
const int small_mod = 1e6 + 3;
template <typename KeyType, typename ValueType>
std::pair<KeyType, ValueType> get_max(const std::map<KeyType, ValueType> &x) {
  using pairtype = std::pair<KeyType, ValueType>;
  return *std::max_element(x.begin(), x.end(),
                           [](const pairtype &p1, const pairtype &p2) {
                             return p1.second < p2.second;
                           });
}
vector<long long> inp_ll(int n) {
  vector<long long> v(n);
  for (long long &x : v) {
    cin >> x;
  }
  return v;
}
long long binpow(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long res = binpow(a, b / 2) % mod;
  if (b % 2) {
    return (res * res * a) % mod;
  } else {
    return (res * res) % mod;
  }
}
vector<int> inp_int(int n) {
  vector<int> v(n);
  for (int &x : v) {
    cin >> x;
  }
  return v;
}
void display_ll(vector<long long> v) {
  for (auto x : v) {
    cout << x << " ";
  }
}
void display_int(vector<int> v) {
  for (auto x : v) {
    cout << x << " ";
  }
}
long long sum_ll(vector<long long> v) {
  return accumulate((v).begin(), (v).end(), 0ll);
}
int sum_int(vector<int> v) { return accumulate((v).begin(), (v).end(), 0); }
long long SOD(long long x) {
  if (x < 0) {
    return -1;
  }
  long long s = 0;
  while (x > 0) {
    s += (x % 10);
    x /= 10;
  }
  return s;
}
bool sortbyfirst(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first > b.first;
}
bool sorting(const pair<int, string> &a, const pair<int, string> &b) {
  return (a.first == b.first ? a.second < b.second : a.first > b.first);
}
void prime1(long long n1) {
  bool prime[n1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n1; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n1; i += p) prime[i] = false;
    }
  }
}
void solve() {
  string s;
  cin >> s;
  vector<int> temp(3);
  bool ok = 1;
  for (char c : s) {
    temp[int(c) - 65]++;
  }
  if (temp[1] == 0) {
    cout << "NO";
    return;
  }
  temp[1] -= min(temp[0], temp[1]);
  if (temp[1] <= 0 && temp[2] > 0) {
    cout << "NO";
    return;
  }
  if (temp[1] != temp[2]) {
    cout << "NO";
    return;
  }
  cout << "YES";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
