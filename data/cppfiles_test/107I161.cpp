#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
bool sorta(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}
bool sortd(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second > b.second);
}
void printarr(long long arr[], long long n) {
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "\n";
}
string decToBinary(int n) {
  string s = "";
  int i = 0;
  while (n > 0) {
    s = to_string(n % 2) + s;
    n = n / 2;
    i++;
  }
  return s;
}
long long binaryToDecimal(string n) {
  string num = n;
  long long dec_value = 0;
  int base = 1;
  int len = num.length();
  for (int i = len - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
bool checksame(int a[], int n) {
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) return false;
  }
  return true;
}
int fact(int n) { return (n == 1 || n == 0) ? 1 : n * fact(n - 1); }
long long mod = 1e9 + 7;
bool cmp(pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; }
vector<pair<int, int>> sort(map<int, int>& M) {
  vector<pair<int, int>> A;
  for (auto& it : M) {
    A.push_back(it);
  }
  sort(A.begin(), A.end(), cmp);
  return A;
}
void BHAI() {
  int n, a, b;
  cin >> n >> a >> b;
  int arr[n];
  for (int i = 0; i < n; i++) arr[i] = i + 1;
  if (n == 2) {
    cout << -1 << endl;
    return;
  }
  int flg = 0;
  do {
    int x = a, y = b;
    for (int i = 1; i < n - 1; i++) {
      if (arr[i] < arr[i - 1] and arr[i] < arr[i + 1])
        x--;
      else if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
        y--;
    }
    if (x == 0 and y == 0) {
      flg = 1;
      break;
    }
  } while (next_permutation(arr, arr + n));
  if (flg) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
  } else
    cout << -1;
  cout << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    BHAI();
  }
  return 0;
}
