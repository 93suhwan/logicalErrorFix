#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
void prl(int x) { cout << x << "\n"; }
const int N = (int)(1 * 1e6 + 10);
using namespace std;
bool check_prime[100];
bool flag;
void sieve() {
  memset(check_prime, true, 100);
  int n = 99;
  for (int p = 2; p * p <= n; p++) {
    if (check_prime[p] == true) {
      for (int i = p * p; i <= n; i += p) check_prime[i] = false;
    }
  }
}
void check_subsequence(string s, string output) {
  int n = s.size();
  if (output.size() == 2 && flag == false) {
    int number = stoi(output);
    if (check_prime[number] == false) {
      cout << number << "\n";
      flag = true;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    char ch = s[i];
    string left = s.substr(0, i);
    string right = s.substr(i + 1);
    check_subsequence(left + right, output + s[i]);
    check_subsequence(left + right, output);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    string s;
    cin >> s;
    long long n = s.size();
    sieve();
    flag = false;
    ;
    bool is_prime[10] = {true, false, true, true, false,
                         true, false, true, true, false};
    vector<int> cnt(10, 0);
    for (int i = 0; i < n; i++) {
      int ss = s[i] - '0';
      if (is_prime[ss] == false) {
        cout << 1 << "\n";
        cout << ss << "\n";
        flag = true;
        break;
      }
      cnt[ss]++;
    }
    if (!flag) {
      if (n == 2) {
        cout << 2 << "\n";
        cout << s << "\n";
      } else {
        cout << 2 << "\n";
        check_subsequence(s, "");
      }
    }
  }
}
