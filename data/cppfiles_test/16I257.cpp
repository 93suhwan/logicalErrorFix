#include <bits/stdc++.h>
using namespace std;
void input(vector<long long>& vec, long long n) {
  long long temp, i;
  for (i = 0; i < n; i++) {
    cin >> temp;
    vec.push_back(temp);
  }
}
long long fact(long long n) {
  long long ans = 1;
  while (n--) {
    ans *= (n + 1);
    ans %= 998244353;
  }
  return ans;
}
bool isprime(long long n) {
  long long i;
  if (n <= 1) return false;
  if (n == 2) return true;
  if (!(n & 1)) return false;
  for (i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}
bool cmp(long long u, long long v) { return u >= v; }
long long decimal(string s) {
  reverse(s.begin(), s.end());
  long long ans = 0, i = 1, j = 0;
  while (j < s.size()) {
    if (s[j] == '1') {
      ans += i;
    }
    i *= 2;
    j++;
  }
  return ans;
}
string binary(long long n) {
  string temp;
  if (n == 0) return "0";
  while (n) {
    temp += to_string(n % 2);
    n /= 2;
  }
  return temp;
}
long long countdigits(long long n) {
  long long i, ans = 0;
  i = n;
  while (i) {
    ans++;
    i /= 10;
  }
  return ans;
}
long long power(long long n, long long k) {
  long long i, ans = 1;
  for (i = 0; i < k; i++) {
    ans *= n;
    ans = ans % 1000000007;
  }
  return ans;
}
struct DblEndedPQ {
  set<pair<long long, long long> > s;
  long long size() { return s.size(); }
  bool isEmpty() { return (s.size() == 0); }
  void insert(pair<long long, long long> x) { s.insert(x); }
  pair<long long, long long> getMin() { return *(s.begin()); }
  pair<long long, long long> getMax() { return *(s.rbegin()); }
  void deleteMin() {
    if (s.size() == 0) return;
    s.erase(s.begin());
  }
  void deleteMax() {
    if (s.size() == 0) return;
    auto it = s.end();
    it--;
    s.erase(it);
  }
};
string logical_function() {
  long long n, i, j, k, l, m;
  cin >> n;
  vector<pair<long long, long long> > vec;
  for (i = 0; i < n; i++) {
    cin >> l;
    if (l != 0) vec.push_back({l, i});
  }
  DblEndedPQ p;
  for (i = 0; i < vec.size(); i++) {
    p.insert(vec[i]);
  }
  l = 0;
  if (n == 1) return to_string(0);
  vector<pair<pair<long long, long long>, pair<long long, long long> > > o;
  string ans, s;
  while (p.size() > 1) {
    pair<long long, long long> temp = p.getMax();
    p.deleteMax();
    pair<long long, long long> temp1 = p.getMin();
    p.deleteMin();
    l += temp1.first;
    long long kl = temp1.first;
    while (kl--) {
      s +=
          to_string(temp.second + 1) + " " + to_string(temp1.second + 1) + "\n";
    }
    p.insert({temp.first - temp1.first, temp.second});
  }
  return to_string(l) + "\n" + s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1, i = 1;
  cin >> t;
  while (t--) {
    cout << logical_function();
    cout << "\n";
  }
}
