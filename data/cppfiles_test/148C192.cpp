#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
bool sorta(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool sortd(const pair<int, int> &a, const pair<int, int> &b) {
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
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  long long i = 1;
  while (t--) {
    long long w, h;
    cin >> w >> h;
    long long arr1[4];
    for (int i = 0; i < 4; i++) {
      int k;
      cin >> k;
      long long arr[k];
      for (int j = 0; j < k; j++) cin >> arr[j];
      arr1[i] = arr[k - 1] - arr[0];
    }
    arr1[0] *= h, arr1[1] *= h;
    arr1[2] *= w, arr1[3] *= w;
    long long maxan = max({arr1[0], arr1[1], arr1[2], arr1[3]});
    cout << maxan << "\n";
  }
  return 0;
}
