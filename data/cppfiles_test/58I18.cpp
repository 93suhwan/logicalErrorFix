#include <bits/stdc++.h>
using namespace std;
const int n1 = 1e9 + 7;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
struct compare {
  inline bool operator()(const std::string& first,
                         const std::string& second) const {
    return first.size() < second.size();
  }
};
long long fact(long long n) {
  long long ans = 1;
  for (long long i = 1; i < n + 1; i++) {
    ans = ((ans % n1) * (i % n1)) % n1;
  }
  return ans;
}
long long power(long long N, long long M) {
  long long power = N, sum = 1;
  if (M == 0) return 1ll;
  while (M > 0) {
    if ((M & 1ll) == 1ll) {
      sum = ((sum % n1) * (power % n1));
      ;
    }
    power = ((power % n1) * (power % n1)) % n1;
    M = M >> 1;
  }
  return sum;
}
int check_comp(int n) {
  int first = 0;
  for (int i = 2; i < (int)(sqrt(n) + 1); i++) {
    if (n % i == 0) {
      first = 1;
      break;
    }
  }
  return first;
}
int is_hill(int a[], int i, int n) {
  if (a[i] > a[i + 1] && a[i] > a[i - 1] && i > 0 && i < n - 1)
    return 1;
  else
    return 0;
}
int is_valley(int a[], int i, int n) {
  if (a[i] < a[i - 1] && a[i] < a[i + 1] && i > 0 && i < n - 1)
    return 1;
  else
    return 0;
}
int cnt[150002] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str[2];
    for (int i = 0; i < 2; i++) {
      cin >> str[i];
    }
    int f1 = 1;
    for (int i = 0; i < n - 1; i++) {
      if (str[0][i + 1] == '1' && str[1][i] == '1' && str[1][i + 1] == '1') {
        f1 = 0;
        break;
      }
    }
    if (f1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
