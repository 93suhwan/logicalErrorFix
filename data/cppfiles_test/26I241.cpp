#include <bits/stdc++.h>
using namespace std;
double pi = 2 * acos(0.0);
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool isPalindrome(string str) {
  int l = 0;
  int h = str.length() - 1;
  while (h > l) {
    if (str[l++] != str[h--]) {
      return false;
    }
  }
  return true;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
int BinToNum(string s) {
  long long int val = 0, len = s.length();
  for (long long int i = len - 1; i >= 0; i--) {
    val += (s[i] - 48) * pow(2, len - i - 1);
  }
  return val;
}
long long int M = 1000000007;
long long int power(long long int b, long long int x) {
  if (x == 0) return 1;
  long long int y = power(b, x / 2) % M;
  long long int z = ((y % M) * (y % M)) % M;
  return (x % 2 == 1) ? b * z : z;
}
bool isSame(long long int arr[10000], long long int x, long long int y,
            long long int a, long long int b) {
  long long int d = b - a + 1;
  while (d--) {
    if (arr[x] != arr[a]) return false;
  }
  return true;
}
string lexiStr(string a, string b) {
  for (long long int i = 0; i < a.length(); i++) {
    if (a[i] < b[i]) return a;
    if (a[i] > b[i]) return b;
  }
  return a;
}
long long int primeFactors(long long int n) {
  long long int mini = INT_MAX;
  long long int c = 0;
  while (n % 2 == 0) {
    c++;
    long long int x = 2;
    mini = min(x, mini);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      c++;
      long long int x = i;
      mini = min(x, mini);
      n = n / i;
    }
  }
  if (n > 2) {
    mini = min(n, mini);
    c++;
  }
  return mini;
}
vector<long long int> factors;
long long int totalFactors(long long int n) {
  long long int c = 0;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i) {
        c++;
        factors.push_back(i);
      } else {
        factors.push_back(i);
        factors.push_back(n / i);
        c++;
        c++;
      }
    }
  }
  return c;
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return (a.first < b.first);
}
int solve() {
  string s;
  cin >> s;
  vector<pair<long long int, long long int>> vect;
  vect.push_back({0, 0});
  long long int ans = 0;
  for (long long int i = 0; i < 10; i++) {
    if (s[i] == '1') {
      for (long long int j = 0; j < vect.size(); j++) {
        if (i % 2 == 0)
          vect[j].first = vect[j].first + 1;
        else
          vect[j].second = vect[j].second + 1;
      }
    }
    if (s[i] == '?') {
      long long int len = vect.size();
      for (long long int j = 0; j < len; j++) {
        if (i % 2 == 0)
          vect.push_back({vect[j].first + 1, vect[j].second});
        else
          vect.push_back({vect[j].first, vect[j].second + 1});
      }
    }
    long long int cr = i + 1;
    for (long long int j = 0; j < vect.size(); j++) {
      long long int e = (10 - cr) / 2;
      if (vect[j].first > vect[j].second) {
        if (i % 2 == 0) e++;
      } else {
        if (i % 2 == 1) e++;
      }
      if (abs(vect[j].first - vect[j].second) > e) {
        cout << cr << endl;
        return 0;
      }
    }
  }
  cout << 10;
  cout << endl;
  return 0;
}
int main() {
  init_code();
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
