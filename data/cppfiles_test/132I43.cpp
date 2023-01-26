#include <bits/stdc++.h>
using namespace std;
vector<long long> primeFactors(long long n) {
  vector<long long> ret;
  while (n % 2 == 0) {
    ret.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      ret.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) ret.push_back(n);
  return ret;
}
long long findArraySum(vector<long long> v) {
  long long sum = 0, n = v.size();
  for (long long i = 0; i < n; i++) {
    sum += v[i];
  }
  return sum;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int countIncreasing(vector<int> arr) {
  int cnt = 0;
  int len = 1;
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i + 1] > arr[i])
      len++;
    else {
      cnt += (((len - 1) * len) / 2);
      len = 1;
    }
  }
  if (len > 1) cnt += (((len - 1) * len) / 2);
  return cnt;
}
int countDivisors(int n) {
  int cnt = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
  return cnt;
}
bool isSorted(vector<int> v) {
  vector<int> temp = v;
  sort(temp.begin(), temp.end());
  if (temp == v)
    return true;
  else
    return false;
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int maxThree(int a, int b, int c) {
  int temp = max(a, b);
  return max(temp, c);
}
int firstPosIndex(vector<int> v) {
  int n = v.size();
  for (long long i = 0; i < n; i++) {
    if (v[i] > 0) return i;
  }
  return -1;
}
long long firstNonDiv(vector<long long> v, long long x) {
  long long n = v.size();
  for (long long i = 0; i < n; i++) {
    if (v[i] % x != 0) {
      return i;
    }
  }
  return -1;
}
double log_a_to_base_b(long long a, long long b) { return log(a) / log(b); }
bool checkIfPalindrome(string s) {
  string temp = s;
  reverse((temp).begin(), (temp).end());
  if (temp == s) return true;
  return false;
}
bool checkIfOneChar(string s) {
  size_t a = count((s).begin(), (s).end(), s[0]);
  if (a == s.length()) {
    return true;
  }
  return false;
}
int findGCD(vector<int> v) {
  int n = v.size();
  int result = v[0];
  for (int i = 1; i < n; i++) {
    result = gcd(v[i], result);
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
int findMinElementOfSubset(vector<int> v, int start, int end) {
  int mini = INT_MAX;
  for (int i = start; i <= end; i++) {
    if (v.at(i) <= mini) mini = v.at(i);
  }
  int index = find(v.begin() + start, v.end(), mini) - v.begin();
  return index;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int countDigit(long long n) {
  int count = 0;
  while (n != 0) {
    n = n / 10;
    ++count;
  }
  return count;
}
bool isFirstDigitEven(int a) {
  int count = countDigit(a);
  int power = pow(10, count - 1);
  if ((a / power) % 2 == 0) return true;
  return false;
}
bool isAllDigitsOdd(int a) {
  int count = countDigit(a);
  for (int i = 0; i < count; i++) {
    int k = a % 10;
    if (k % 2 == 0) {
      return false;
    }
    a /= 10;
  }
  return true;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int LCSubStr(string X, string Y, int m, int n) {
  int LCSuff[m + 1][n + 1];
  int result = 0;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCSuff[i][j] = 0;
      else if (X[i - 1] == Y[j - 1]) {
        LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
        result = max(result, LCSuff[i][j]);
      } else
        LCSuff[i][j] = 0;
    }
  }
  return result;
}
vector<int> convertIntIntoVector(long long n) {
  vector<int> ret;
  long long countDig = countDigit(n);
  for (int i = 0; i < countDig; i++) {
    ret.push_back(n % 10);
    n /= 10;
  }
  reverse((ret).begin(), (ret).end());
  return ret;
}
vector<long long> primeInRange(long long L, long long R) {
  int flag;
  vector<long long> ret;
  if (L == 1) ret.push_back(1);
  for (long long i = L; i <= R; i++) {
    if (i == 1 || i == 0) continue;
    flag = 1;
    for (long long j = 2; j <= i / 2; ++j) {
      if (i % j == 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) ret.push_back(i);
  }
  return ret;
}
vector<long long> notPrimeInRange(long long L, long long R) {
  int flag;
  vector<long long> ret;
  if (L == 1) L = 2;
  for (long long i = L; i <= R; i++) {
    if (i == 1 || i == 0) continue;
    flag = 1;
    for (long long j = 2; j <= i / 2; ++j) {
      if (i % j == 0) {
        flag = 0;
        break;
      }
    }
    if (flag != 1) ret.push_back(i);
  }
  return ret;
}
void solve() {
  vector<long long> v(7, 0);
  for (long long i = 0; i < 7; i++) cin >> v[i];
  cout << v[6] - v[5] << " " << v[6] - v[4] << " " << v[6] - v[3] << endl;
}
int main() {
  int t;
  cin >> t;
  for (long long i = 0; i < t; i++) solve();
  return 0;
}
