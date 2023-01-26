#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
template <typename T>
T Sqr(T x) {
  T n = x * x;
  return n;
}
template <typename T>
T Pow(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * Pow(B, P - 1);
  else
    return Sqr(Pow(B, P / 2));
}
template <typename T>
T Abs(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
T Gcd(T a, T b) {
  if (a < 0) return Gcd(-a, b);
  if (b < 0) return Gcd(a, -b);
  return (b == 0) ? a : Gcd(b, a % b);
}
template <typename T>
T Lcm(T a, T b) {
  if (a < 0) return Lcm(-a, b);
  if (b < 0) return Lcm(a, -b);
  return a * (b / Gcd(a, b));
}
template <typename T>
T Exgcd(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = Exgcd(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = Exgcd(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = Exgcd(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <typename T>
T BigMod(T b, T p, T m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    T s = BigMod(b, p / 2, m);
    return ((s % m) * (s % m)) % m;
  }
  return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;
}
template <typename T>
T ModInvPrime(T b, T m) {
  return BigMod(b, m - 2, m);
}
template <typename T>
T ModInvNotPrime(T a, T m) {
  T x, y;
  Exgcd(a, m, x, y);
  x %= m;
  if (x < 0) x += m;
  return x;
}
template <typename T>
typename std::vector<T>::iterator Insert_sorted(std ::vector<T> &vec,
                                                T const &item) {
  return vec.insert(std::upper_bound(vec.begin(), vec.end(), item), item);
}
template <typename T>
inline string ToBinary(T n) {
  string r;
  while (n != 0) {
    r = (n % 2 == 0 ? "0" : "1") + r;
    n >>= 1;
  }
  return r;
}
long long BinaryToDecimal(string s) {
  int len = s.size();
  long long n = 0, p = 1;
  for (int i = len - 1; i >= 0; i--, p *= 2) n += p * (s[i] - '0');
  return n;
}
char Uplowch(char ch) {
  if (ch >= 'A' && ch <= 'Z') ch += 32;
  return ch;
}
char Lowupch(char ch) {
  if (ch >= 'a' && ch <= 'z') ch -= 32;
  return ch;
}
bool Isalpha(char ch) {
  if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true;
  return false;
}
int Strtoint(string str) {
  stringstream ss(str);
  int x = 0;
  ss >> x;
  return x;
}
string Intostr(int x) {
  stringstream ss;
  ss << x;
  string str = ss.str();
  return str;
}
vector<string> Linetostr(string str) {
  string s;
  vector<string> v;
  istringstream is(str);
  while (is >> s) v.push_back(s);
  return v;
}
template <typename T>
void Print(T ar[], int a, int b) {
  for (int i = a; i + 1 <= b; i++) cout << ar[i] << " ";
  cout << ar[b] << "\n";
}
template <typename T>
void Print(T ar[], int n) {
  for (int i = 0; i + 1 < n; i++) cout << ar[i] << " ";
  cout << ar[n - 1] << "\n";
}
template <typename T>
void Print(const vector<T> &v) {
  for (int i = 0; i + 1 < v.size(); i++) cout << v[i] << " ";
  cout << v.back() << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  for (int tc = 1; tc <= test; tc++) {
    int n, k;
    cin >> n >> k;
    int ar[n + 1];
    for (int i = 0; i < n; i++) cin >> ar[i];
    int mp[n + 2];
    memset(mp, 0, sizeof(mp));
    vector<int> vec[n + 1];
    for (int i = 0; i < n; i++) {
      mp[ar[i]] += 1;
      vec[ar[i]].push_back(i);
    }
    int ans[n + 12];
    memset(ans, 0, sizeof(ans));
    vector<int> dewajabe;
    for (int i = 1; i <= n; i++) {
      if (mp[i] >= k) {
        for (int j = 0; j < k; j++) {
          ans[vec[i][j]] = j + 1;
        }
      } else if (mp[i] != 0) {
        for (int j = 0; j < vec[i].size(); j++) {
          dewajabe.push_back(vec[i][j]);
        }
      }
    }
    int now = dewajabe.size();
    for (int i = 0; i < now && k <= now;) {
      for (int j = 1; j <= k; j++, i++) {
        ans[dewajabe[i]] = j;
      }
      now -= k;
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
