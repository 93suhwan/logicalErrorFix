#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T &vec1, const T &vec2) {
  return vec2 < vec1 ? vec1 = vec2, 1 : 0;
}
template <class T>
bool ckmax(T &vec1, const T &vec2) {
  return vec1 < vec2 ? vec1 = vec2, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int first = 0;
  cerr << '{';
  for (auto &i : x) cerr << (first++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... vec) {
  __print(t);
  if (sizeof...(vec)) cerr << ", ";
  _print(vec...);
}
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
long long decimalToBinary(long long N) {
  long long B_Number = 0;
  int cnt = 0;
  while (N != 0) {
    int temp = N % 2;
    long long c = pow(10, cnt);
    B_Number += temp * c;
    N /= 2;
    cnt++;
  }
  return B_Number;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long powx(long long num1, long long num2) {
  num1 %= MOD;
  long long temp = 1;
  while (num2) {
    if (num2 & 1) {
      temp = (temp * num1) % MOD;
    }
    num1 = (num1 * num1) % MOD;
    num2 /= 2;
  }
  return temp;
}
string removeOccurrences(string second, string part) {
  auto itr = second.find(part);
  if (itr == string::npos) {
    return second;
  } else {
    while (itr != string::npos) {
      second.erase(itr, part.size());
      if (second[itr - 1] != ' ') {
        second.insert(itr, " ");
      }
      itr = second.find(part);
    }
  }
  return second;
}
bool isComp(long long n) {
  for (long long i = 2; i < (pow(n, 2) + 1); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> vec;
    long long xt = 0;
    long long second = 0;
    for (long long i = 0; i < (n); i++) {
      cin >> xt;
      vec.emplace_back(xt);
      second += vec[i];
    }
    if (isComp(second)) {
      cout << n - 1 << nl;
      long long temp = -1;
      for (long long i = 0; i < (n); i++) {
        if (!isComp(second - vec[i])) {
          temp = i;
          break;
        }
      }
      for (long long i = 0; i < (n); i++) {
        if (i != temp) {
          cout << i + 1 << ' ';
        }
      }
    } else {
      cout << n << nl;
      for (long long i = 0; i < (n); i++) {
        cout << i + 1 << ' ';
      }
    }
    cout << nl;
  }
}
