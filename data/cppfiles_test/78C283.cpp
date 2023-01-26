#include <bits/stdc++.h>
using namespace std;
int minimum(int x, int y) { return (x < y ? x : y); }
template <typename type>
struct even {
  bool operator()(const type &x, const type &y) const { return x % 2 < y % 2; }
};
template <typename type>
struct odd {
  bool operator()(const type &x, const type &y) const { return x % 2 > y % 2; }
};
template <typename type>
struct abslouteValue {
  bool operator()(const type &x, const type &y) const {
    return abs(x) > abs(y);
  }
};
bool flusher() {
  string s;
  fflush(stdout);
  getline(cin, s);
  return s != "";
}
void insertionSortAlgorithm(int arr[], int n) {
  int key, j;
  for (int i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}
template <class T>
T sum(T x) {
  string s = to_string(x);
  T sumOfString = 0;
  int n = s.size();
  for (long long int i = 0; i < n; i++) {
    sumOfString += (T)s[i] - '0';
  }
  return sumOfString;
}
bool compare(const pair<double, double> a, const pair<double, double> b) {
  if (a.first == b.first) {
    return b.second > a.second;
  } else {
    return a.first > b.first;
  }
}
bool abslout(const int &x, const int &y) { return abs(x) > abs(y); }
bool isPrime(long long int x) {
  if (x == 1) return false;
  bool yes = true;
  if (x == 2) {
    return yes;
  } else {
    for (long long int i = 2; i < x; i++) {
      if (x % i == 0) {
        yes = false;
        break;
      }
    }
  }
  return yes;
}
void build(int l, int r, vector<int> const &a, vector<int> &res, int d = 0) {
  if (r < l) {
    return;
  }
  if (l == r) {
    res[l] = d;
    return;
  }
  int temp = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[temp] < a[i]) {
      temp = i;
    }
  }
  res[temp] = d;
  build(l, temp - 1, a, res, d + 1);
  build(temp + 1, r, a, res, d + 1);
}
bool binarySearch(int l, int r, long long int *a, long long int k) {
  while (l <= r) {
    long long int mid = (l + r) / 2;
    if (a[mid] == k) {
      return true;
    } else if (a[mid] > k) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return false;
}
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
vector<long long int> luckyPackage;
void bruteForce(long long int n, long long int four, long long int seven) {
  if (n > 1e10) return;
  if (four == seven) {
    luckyPackage.push_back(n);
  }
  bruteForce(n * 10 + 4, four + 1, seven);
  bruteForce(n * 10 + 7, four, seven + 1);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << b % (max(b / 2 + 1, a)) << endl;
  }
  return 0;
}
