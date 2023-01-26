#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << "[ " << *it << " = " << a << " ] ";
  err(++it, args...);
}
template <typename Tk, typename Tv>
ostream& operator<<(ostream& os, const pair<Tk, Tv>& p) {
  os << "{" << p.first << ',' << p.second << "}";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (T x : p) os << x << " ";
  os << "]" << '\n';
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "{ ";
  for (T x : p) os << x << " ";
  os << "}" << '\n';
  return os;
}
template <typename Tk, typename Tv>
ostream& operator<<(ostream& os, const map<Tk, Tv>& p) {
  os << "{ ";
  for (pair<Tk, Tv> x : p) os << x << " ";
  os << "}" << '\n';
  return os;
}
const long long int N = 1e5;
bool prime[N + 1];
void sieve() {
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= N; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= N; i += p) prime[i] = false;
    }
  }
}
string do_recur(string s) {
  if (!prime[stoi(s)]) {
    return s;
  }
  if ((long long int)s.size() > 1) {
    for (char c : s) {
      string tmp = s;
      tmp.erase(remove((tmp).begin(), (tmp).end(), c), tmp.end());
      string chk = do_recur(tmp);
      if (chk != "-1") {
        return tmp;
      }
    }
  }
  return "-1";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  sieve();
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    bool findev = false;
    vector<long long int> freq(10);
    for (char ch : s) {
      freq[ch - '0']++;
      if ((ch - '0') % 2 == 0 || ch == '1') {
        findev = true;
        cout << "1\n" << ch << '\n';
        break;
      }
    }
    if (!findev) {
      bool finddu = false;
      for (long long int i = 0; i < 10; i++) {
        if (freq[i] > 1) {
          finddu = true;
          string gg;
          gg += i + '0';
          gg += i + '0';
          cout << "2\n" << gg << '\n';
          break;
        }
      }
      if (!finddu) {
        if ((long long int)s.length() == 2) {
          cout << "2\n" << s << '\n';
        } else {
          string fin = do_recur(s);
          cout << (long long int)fin.size() << '\n' << fin << '\n';
        }
      }
    }
  }
  return 0;
}
