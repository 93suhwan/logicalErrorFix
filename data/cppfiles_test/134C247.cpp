#include <bits/stdc++.h>
using namespace std;
vector<string> vec_splitter(string s) {
  for (char& c : s) c = c == ',' ? ' ' : c;
  stringstream ss;
  ss << s;
  vector<string> res;
  for (string z; ss >> z; res.push_back(z))
    ;
  return res;
}
void debug_out(vector<string> args, int idx) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, Head H, Tail... T) {
  if (idx > 0) cerr << ", ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, T...);
}
void localTest() {}
long long gcd(long long a, long long b) {
  if (a < b) {
    swap(a, b);
  }
  if (!b) {
    return a;
  }
  return gcd(b, a % b);
}
bool checkDivisibility(vector<long long>& A, long long d) {
  for (auto a : A) {
    if (a % d == 0) {
      return true;
    }
  }
  return false;
}
void solver() {
  long long n;
  cin >> n;
  vector<long long> odd, even;
  long long eGcd = 0, oGcd = 0;
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    if (i & 1) {
      odd.push_back(x);
      oGcd = gcd(oGcd, x);
    } else {
      even.push_back(x);
      eGcd = gcd(eGcd, x);
    }
  }
  if (!checkDivisibility(even, oGcd)) {
    cout << oGcd << "\n";
  } else if (!checkDivisibility(odd, eGcd)) {
    cout << eGcd << "\n";
  } else {
    cout << "0\n";
  }
  return;
}
int main() {
  localTest();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solver();
  }
  return 0;
}
