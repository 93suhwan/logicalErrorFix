#include <bits/stdc++.h>
const long long nint = 1e9 + 7;
const long long i1 = 1e6 + 5;
const long long num = 1e5 + 5;
using namespace std;
bool itsrt(string s, long long n) {
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] > s[i + 1]) {
      return false;
    }
  }
  return true;
}
void kkkuuu() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long maxi = *max_element(arr, arr + n);
  vector<long long> vec;
  for (long long i = 0; i < n; i++) {
    if (arr[i] == maxi) {
      vec.push_back(i);
    }
  }
  vector<long long> miniind;
  for (long long i = 0; i < vec.size(); i++) {
    long long a, b;
    if (vec[i] == 0) {
      a = arr[vec[i] + 1];
      miniind.push_back(a);
    } else if (vec[i] == n - 1) {
      a = arr[vec[i] - 1];
      miniind.push_back(a);
    } else {
      a = arr[vec[i] - 1];
      b = arr[vec[i] + 1];
      miniind.push_back(a);
      miniind.push_back(b);
    }
  }
  long long mini = *max_element(miniind.begin(), miniind.end());
  cout << maxi * mini << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tct = 1;
  cin >> tct;
  while (tct--) {
    kkkuuu();
  }
}
