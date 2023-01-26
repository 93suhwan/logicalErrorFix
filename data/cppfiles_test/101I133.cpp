#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265359;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long randint(long long a, long long b) {
  return uniform_int_distribution<long long>(a, b)(rng);
}
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}
void print(vector<long long>& v) {
  cout << "[";
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i + 1 != v.size()) cout << ", ";
  }
  cout << "]" << endl;
}
void print(pair<long long, long long>& p) {
  cout << "{" << p.first << ", " << p.second << "}" << endl;
}
const long long maxn = 1e6 + 10;
bitset<maxn> tanacoluna(0);
bitset<maxn> tanalinha(0);
vector<long long> gambx(maxn, 0);
vector<long long> gamby(maxn, 0);
signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, qp;
    cin >> n >> m >> qp;
    long long resp = (qp * (qp - 1)) / 2;
    vector<long long> x(n);
    vector<long long> y(m);
    vector<pair<long long, long long> > p(qp);
    for (long long i = 0; i < n; i++) cin >> x[i];
    for (auto k : x) tanacoluna[k] = 1;
    for (long long i = 0; i < m; i++) cin >> y[i];
    for (auto k : y) tanalinha[k] = 1;
    for (long long i = 0; i < qp; i++) cin >> p[i].first >> p[i].second;
    sort(y.begin(), y.end());
    sort(x.begin(), x.end());
    long long pp = qp - 1;
    long long tot = 0;
    vector<long long> carasx;
    vector<long long> carasy;
    vector<pair<long long, long long> > pqpxxx;
    vector<pair<long long, long long> > pqpyyy;
    for (long long i = 0; i < qp; i++) {
      if (tanacoluna[p[i].first] && tanalinha[p[i].second]) {
        tot += pp;
        pp--;
      } else if (tanacoluna[p[i].first]) {
        carasx.push_back(p[i].second);
        pqpxxx.push_back({p[i].second, i});
        tot += (gambx[p[i].first]++);
      } else {
        carasy.push_back(p[i].first);
        pqpyyy.push_back({p[i].first, i});
        tot += (gamby[p[i].second]++);
      }
    }
    long long primeiralinha = 0;
    long long primeiracoluna = 0;
    sort(carasx.begin(), carasx.end());
    sort(carasy.begin(), carasy.end());
    sort(pqpxxx.begin(), pqpxxx.end());
    sort(pqpyyy.begin(), pqpyyy.end());
    deque<pair<long long, long long> > pqpx;
    deque<pair<long long, long long> > pqpy;
    for (auto k : pqpxxx) {
      pqpx.push_back(p[k.second]);
    }
    for (auto k : pqpyyy) {
      pqpy.push_back(p[k.second]);
    }
    long long cx = 0;
    long long cy = 0;
    for (auto k : x) {
      tanacoluna[k] = 0;
      gambx[k] = 0;
    }
    for (auto k : y) {
      tanalinha[k] = 0;
      gamby[k] = 0;
    }
    for (long long i = 0; i < carasx.size(); i++) {
      while ((primeiralinha + 1 < y.size()) &&
             (y[primeiralinha + 1] < carasx[i]))
        primeiralinha++;
      while (!pqpx.empty() && pqpx.front().second <= y[primeiralinha]) {
        gambx[pqpx.front().first]++;
        pqpx.pop_front();
      }
      long long rsp =
          (lower_bound(carasx.begin(), carasx.end(), y[primeiralinha]) -
           carasx.begin());
      tot += rsp;
      tot -= gambx[p[pqpxxx[i].second].first];
    }
    for (long long i = 0; i < carasy.size(); i++) {
      while ((primeiracoluna + 1 < y.size()) &&
             (x[primeiracoluna + 1] < carasy[i]))
        primeiracoluna++;
      while (!pqpy.empty() && pqpy.front().first <= x[primeiracoluna]) {
        gamby[pqpy.front().second]++;
        pqpy.pop_front();
      }
      long long rsp =
          lower_bound(carasy.begin(), carasy.end(), x[primeiracoluna]) -
          carasy.begin();
      tot += rsp;
      tot -= gamby[p[pqpyyy[i].second].second];
    }
    tot += ((long long)carasy.size() * (long long)carasx.size());
    cout << resp - tot << endl;
    for (auto k : x) {
      tanacoluna[k] = 0;
      gambx[k] = 0;
    }
    for (auto k : y) {
      tanalinha[k] = 0;
      gamby[k] = 0;
    }
  }
}
