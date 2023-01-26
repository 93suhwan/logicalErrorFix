#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <typename T>
T get(T& a) {
  read(a);
  return a;
}
class Converter {
 public:
  template <typename T>
  T toNum(string s, T& n) {
    stringstream ss;
    ss << s;
    ss >> n;
    return n;
  }
  template <typename T>
  string toString(T& n) {
    stringstream ss;
    ss << n;
    string s;
    ss >> s;
    return s;
  }
} convert;
class Prime {
 public:
  bool isPrime[10000007] = {0};
  std::vector<int> primeContain;
  void sieve(int n) {
    memset(isPrime, true, sizeof(isPrime));
    for (int p = 2; p * p <= n; p++) {
      if (isPrime[p] == true) {
        for (int i = p * p; i <= n; i += p) isPrime[i] = false;
      }
    }
    isPrime[0] = 0, isPrime[1] = 0;
    for (int i = 2; 1 > 0 ? i < n + 7 : i >= n + 7; i += 1)
      if (isPrime[i]) primeContain.push_back(i);
  }
  bool primeDigit(int n) {
    while (n) {
      int t = n % 10;
      if (t != 2 && t != 3 && t != 5 && t != 7) return false;
      n /= 10;
    }
    return true;
  }
} prime;
class Algo {
 public:
  int josephusDP[100005];
  int josephus(int n, int k) {
    if (josephusDP[n] != -1) return josephusDP[n];
    if (n == 1) return 1;
    return josephusDP[n] = (josephus(n - 1, k) + k - 1) % n + 1;
  }
  template <typename T>
  T kadane(T arr[], int arr_len) {
    T total_max, current_max;
    total_max = current_max = INT_MIN;
    for (int i = 0; i < arr_len; i++) {
      current_max = max(current_max, 0) + arr[i];
      total_max = max(total_max, current_max);
    }
    return total_max;
  }
  template <typename T>
  pair<int, pair<int, int> > kadane_indx(T arr[], int arr_len) {
    int indx_begin = 0, indx_end = 0, indx_temp = 0;
    T total_max = 0, current_max = 0;
    for (int i = 0; i < arr_len; i++) {
      current_max += arr[i];
      if (current_max < 0) {
        current_max = 0;
        indx_temp = i + 1;
      } else if (total_max < current_max) {
        total_max = current_max;
        indx_begin = indx_temp;
        indx_end = i;
      }
    }
    return pair<int, pair<int, int> >(total_max,
                                      pair<int, int>(indx_begin, indx_end));
  }
} algo;
void cppCheck() {
  if (__cplusplus == 201103L)
    std::cout << "C++11\n";
  else if (__cplusplus == 199711L)
    std::cout << "C++98\n";
  else
    std::cout << "pre-standard C++\n";
}
int val[105], wet[105];
int mem[105][200007];
int knapsack(int n, int w) {
  if (n == 0 || w == 0) return 0;
  int& ret = mem[n][w];
  if (ret != -1) return ret;
  if (wet[n] <= w)
    return ret = max(val[n] + knapsack(n - 1, w - wet[n]), knapsack(n - 1, w));
  else
    return ret = knapsack(n - 1, w);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, m;
    long long pairr = 0;
    cin >> a >> b >> c >> m;
    int arr[5];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    sort(arr, arr + 3);
    pairr = arr[2] - (arr[0] + arr[1] + m);
    long long p = (a - 1) + (b - 1) + (c - 1);
    if (pairr < 2 && p >= m)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
