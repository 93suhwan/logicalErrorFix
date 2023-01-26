#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
bool is_prime(long long n) {
  if (n == 1 || n == 0) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 1; (6 * i + 1) <= n; i++) {
    if (6 * i + 1 == n) return true;
    if (6 * i - 1 == n) return true;
  }
  return false;
}
unordered_set<long long> prime_till_n(long long n) {
  vector<long long> arr(n + 1);
  arr[0] = 0;
  arr[1] = 0;
  for (long long i = 2; i <= n; i++) arr[i] = (long long)1;
  for (long long i = 2; i <= (n - 1) / 2; i++) {
    if (arr[i] == 1) {
      long long j = i;
      while (i + j <= n) {
        if (arr[i + j] == 1) {
          arr[i + j] = 0;
        }
        j += i;
      }
    }
  }
  unordered_set<long long> ans;
  for (long long i = 0; i <= n; i++) {
    if (arr[i] == 1) ans.insert(i);
  }
  return ans;
}
bool is_palindrome(string s) {
  string r = s;
  reverse(r.begin(), r.end());
  if (s.compare(r) == 0) return true;
  return false;
}
bool issubstr(string s1, string s2) {
  int M = s1.length();
  int N = s2.length();
  for (int i = 0; i <= N - M; i++) {
    int j;
    for (j = 0; j < M; j++)
      if (s2[i + j] != s1[j]) break;
    if (j == M) return true;
  }
  return false;
}
long long xortilln(long long n) {
  if (n % 4 == 0ll) return n;
  if (n % 4 == 1ll) return 1ll;
  if (n % 4 == 2ll) return n + 1ll;
  return 0ll;
}
void solve() {
  string s;
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  cin >> s;
  vector<long long> up, down;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1')
      up.push_back(v[i]);
    else
      down.push_back(v[i]);
  }
  sort(up.begin(), up.end());
  sort(down.begin(), down.end());
  unordered_map<long long, long long> up2, down2;
  for (int i = 0; i < down.size(); i++) down2[down[i]] = i + 1;
  for (int i = 0; i < up.size(); i++) up2[up[i]] = down.size() + i + 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      cout << up2[v[i]] << " ";
    else
      cout << down2[v[i]] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long i = 1, t = 1;
  cin >> t;
  while (t--) {
    solve();
    i++;
  }
}
