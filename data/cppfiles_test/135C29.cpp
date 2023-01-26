#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MOD = 1e9 + 7;
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << "\n";
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
void run() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long gcd(long long n1, long long n2) {
  if (n2 != 0)
    return gcd(n2, n1 % n2);
  else
    return n1;
}
bool checkPalindrome(string s) {
  int n = s.size();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) return false;
  }
  return true;
}
long long digSum(long long n) {
  long long sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first == a.second)
    return true;
  else if (b.first == b.second)
    return false;
  else {
    int adiff = a.second - a.first;
    int bdiff = b.second - b.first;
    if (adiff > bdiff)
      return false;
    else
      return true;
  }
}
int main() {
  run();
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    int ind = n - 2 * k;
    int half = ind + k;
    for (int i = 1; i <= ind; i++) {
      ans += v[i];
    }
    for (int i = ind + 1; i <= half; i++) {
      ans = ans + (v[i] / v[i + k]);
    }
    cout << ans << "\n";
  }
  return 0;
}
