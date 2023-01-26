#include <bits/stdc++.h>
using namespace std;
struct triplet {
  long long x, y, gcd;
};
triplet extendedEuclid(long long a, long long b) {
  if (b == 0) {
    triplet ans;
    ans.x = 1;
    ans.gcd = a;
    ans.y = 0;
    return ans;
  }
  triplet smallAns = extendedEuclid(b, a % b);
  triplet ans;
  ans.x = smallAns.y;
  ans.y = smallAns.x - (a / b) * smallAns.y;
  ans.gcd = smallAns.gcd;
  return ans;
}
long long multiplicativeModuloInverse(long long a, long long m) {
  triplet temp = extendedEuclid(a, m);
  return (temp.x % m + m) % m;
}
long long power(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) {
      ans = (ans * a) % 1000000007;
    }
    a = (a * a) % 1000000007;
    n = n >> 1;
  }
  return ans;
}
const long long N = 5e6 + 1;
vector<bool> isPrime(N, 1);
vector<long long> lp(N, 0), hp(N, 0);
void sieve() {
  isPrime[0] = isPrime[1] = false;
  for (long long i = 2; i < N; i++) {
    if (isPrime[i] == true) {
      lp[i] = hp[i] = i;
      for (long long j = 2 * i; j < N; j += i) {
        isPrime[j] = false;
        hp[j] = i;
        if (lp[j] == 0) {
          lp[j] = i;
        }
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> isCrewmate(n + 1, -1);
    long long prev = -1;
    for (long long i = 1; i <= (n - 2); i++) {
      long long temp;
      cout << "? " << i << ' ' << (i + 1) << ' ' << (i + 2) << endl;
      cin >> temp;
      if (temp == 0 && prev == 1) {
        isCrewmate[i + 2] = 0;
        isCrewmate[i - 1] = 1;
      } else if (temp == 1 && prev == 0) {
        isCrewmate[i + 2] = 1;
        isCrewmate[i - 1] = 0;
      }
      prev = temp;
    }
    long long temp;
    cout << "? " << n - 1 << ' ' << n << ' ' << 1 << endl;
    cin >> temp;
    if (temp == 0 && prev == 1) {
      isCrewmate[1] = 0;
      isCrewmate[n - 2] = 1;
    } else if (temp == 1 && prev == 0) {
      isCrewmate[1] = 1;
      isCrewmate[n - 2] = 0;
    }
    prev = temp;
    cout << "? " << n << ' ' << 1 << ' ' << 2 << endl;
    cin >> temp;
    if (temp == 0 && prev == 1) {
      isCrewmate[2] = 0;
      isCrewmate[n - 1] = 1;
    } else if (temp == 1 && prev == 0) {
      isCrewmate[2] = 1;
      isCrewmate[n - 1] = 0;
    }
    prev = temp;
    long long index_of_crewmate, index_of_imposter;
    for (long long i = 1; i <= n; i++) {
      if (isCrewmate[i] == 1) {
        index_of_crewmate = i;
        break;
      }
    }
    for (long long i = 1; i <= n; i++) {
      if (isCrewmate[i] == 0) {
        index_of_imposter = i;
        break;
      }
    }
    for (long long i = 1; i <= n; i++) {
      if (i != index_of_crewmate && i != index_of_imposter) {
        long long temp;
        cout << "? " << i << ' ' << index_of_crewmate << ' '
             << index_of_imposter << endl;
        cin >> temp;
        if (temp == 1) {
          isCrewmate[i] = 1;
        } else {
          isCrewmate[i] = 0;
        }
      }
    }
    vector<long long> imposters;
    for (long long i = 1; i <= n; i++) {
      if (isCrewmate[i] == 0) {
        imposters.push_back(i);
      }
    }
    cout << "! " << imposters.size() << ' ';
    for (long long i = 0; i < imposters.size(); i++) {
      cout << imposters[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
