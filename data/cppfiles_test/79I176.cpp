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
void sieve() {
  memset(check_prime, true, 100);
  int n = 99;
  for (int p = 2; p * p <= n; p++) {
    if (check_prime[p] == true) {
      for (int i = p * p; i <= n; i += p) check_prime[i] = false;
    }
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
    bool flag = false;
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
      int cnt2 = cnt[2];
      int cnt3 = cnt[3];
      int cnt5 = cnt[5];
      int cnt7 = cnt[7];
      int cnt0 = cnt[0];
      if (n == 2) {
        cout << 2 << "\n";
        cout << s << "\n";
      } else if (n > 2) {
        for (int i = 0; i < n - 1; i++) {
          string temp = "";
          temp.push_back(s[i]);
          temp.push_back(s[i + 1]);
          long long number = stoi(temp);
          if (check_prime[number] == false) {
            cout << 2 << "\n";
            cout << number << "\n";
            flag = true;
            break;
          }
          if (flag) break;
        }
        if (!flag) {
          for (int i = 1; i < n - 1; i++) {
            string temp = "";
            temp.push_back(s[i - 1]);
            temp.push_back(s[i + 1]);
            long long number = stoi(temp);
            if (check_prime[number] == false) {
              cout << 2 << "\n";
              cout << number << "\n";
              flag = true;
              break;
            }
            if (flag) break;
          }
        }
      }
    }
  }
}
