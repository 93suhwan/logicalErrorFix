#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 1e6 + 10;
const int MOD = 1e9 + 7;
long long int mod(long long int a) {
  a %= MOD;
  if (a < 0) a += MOD;
  return a;
}
const double PI = 2 * acos(0.0);
long long int digit(long long int x) { return floor(log10(x)) + 1; }
long long int digit_sum(long long int x) {
  long long int sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}
bool cmp_double(double a, double b) {
  if (abs(a - b) < 1e-10)
    return true;
  else
    return false;
}
int reverse_num(int n) {
  int tmp = n, ans = 0, r;
  while (tmp > 0) {
    r = tmp % 10;
    ans = ans * 10 + r;
    tmp /= 10;
  }
  return ans;
}
long long int factorial(long long int n) {
  long long int i, ans = 1;
  for (i = n; i > 1; i--) {
    ans *= i;
  }
  return ans;
}
bool vowel(char ch) {
  ch = tolower(ch);
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return true;
  return false;
}
bool isLeapYear(long long int y) {
  return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}
long long int power(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
bool isprime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if ((n % 2 == 0) || (n % 3 == 0)) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
string Summation(string n, string s) {
  if (n.size() > s.size()) swap(n, s);
  string str;
  int l_n = n.size();
  int l_s = s.size();
  reverse(n.begin(), n.end());
  reverse(s.begin(), s.end());
  int carry = 0;
  for (int i = 0; i < l_n; i++) {
    int sum = ((n[i] - '0') + (s[i] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  for (int i = l_n; i < l_s; i++) {
    int sum = ((s[i] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  if (carry) str.push_back(carry + '0');
  reverse(str.begin(), str.end());
  return str;
}
string multiplication(string n, string s) {
  int l_n = n.size();
  int l_s = s.size();
  if (l_n == 0 || l_s == 0) return "0";
  vector<int> result(l_n + l_s);
  int i_n = 0;
  int i_s = 0;
  for (int i = l_n - 1; i >= 0; i--) {
    int carry = 0;
    int n_1 = n[i] - '0';
    i_s = 0;
    for (int j = l_s - 1; j >= 0; j--) {
      int s_2 = s[j] - '0';
      int sum = n_1 * s_2 + result[i_n + i_s] + carry;
      carry = sum / 10;
      result[i_n + i_s] = sum % 10;
      i_s++;
    }
    if (carry > 0) result[i_n + i_s] += carry;
    i_n++;
  }
  int i = result.size() - 1;
  while (i >= 0 && result[i] == 0) i--;
  if (i == -1) return "0";
  string pro;
  while (i >= 0) pro += to_string(result[i--]);
  return pro;
}
int i, j;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tc = 1;
  cin >> tc;
  while (tc--) {
    string n;
    cin >> n;
    long long int f = 1;
    if (n.length() % 2 != 0)
      cout << "No" << endl;
    else {
      long long int ok = n.length() / 2;
      string a = "YES";
      for (i = 0; i < ok; i++) {
        if (n[i] != n[ok + i]) {
          a = "No";
          f = 0;
          break;
        }
      }
      cout << a << endl;
    }
  }
  return 0;
}
