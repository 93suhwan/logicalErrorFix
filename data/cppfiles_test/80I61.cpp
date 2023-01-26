#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

// Template {{{
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<typename T>
T maxv(T a) {
  return a;
}
template<typename T, typename ... Args>
T maxv(T a, Args ... args) {
  return std::max(a, maxv(args...));
}

template<typename T>
T minv(T a) {
  return a;
}
template<typename T, typename ... Args>
T minv(T a, Args ... args) {
  return std::min(a, minv(args...));
}

namespace std {
  template<class Fun>
  class y_combinator_result {
    Fun fun_;
  public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
   
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
      return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
  };
   
  template<class Fun>
  decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
  }
} // namespace std

template<typename T>
concept Container = requires(T a)
{
  { a.begin() } -> std::same_as<typename T::iterator>;
  { a.end() } -> std::same_as<typename T::iterator>;
};

#define DEBUG(x) cerr << #x << ": " << x << '\n'
template<class T, template <class> class U>
ostream& operator<<(ostream& o, const U<T>& v) requires Container<U<T>>
{
  o << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    o << *it; if (next(it) != v.end()) o << ", ";
  }
  o << "]";
  return o;
}
// }}}

struct Node {/*{{{*/
	int s, e, m;
	//covers s,e;
	int sum;
  int pfx_sum;
	Node *l, *r;
	
	Node(int a, int b) {
		s = a;
		e = b;
		sum = 0;
		if (s != e) {
			m = (s+e)/2;
			l = new Node(s,m);
			r = new Node(m+1,e);
		}
		else {
			l = nullptr;
			r = nullptr;
		}
	}

	void add(int i, int x) {
		if (s == e) {
			sum = pfx_sum = x;
			return;
		}
		if (i <= m) {
			l->add(i,x);
		}
		else if (i > m) {
			r->add(i,x);
		}
		else assert(false);
		sum = l->sum + r->sum;
    pfx_sum = min(l->pfx_sum, l->sum + r->pfx_sum);
	}

	int getsum(int st, int en) {
		if (st <= s && e <= en) {
			return sum;
		}
		int ret = 0;
		if (st <= m) {
			ret += l->getsum(st,en);
		}
		if (en > m) {
			ret += r->getsum(st,en);
		}
		return ret;
	}

  int minPrefix() const {
    return pfx_sum;
  }
};/*}}}*/

ll countInversions(int n, vector<int> a) {/*{{{*/
  map<int, vector<int>> as;
  for (int i = 1; i <= n; i++) {
    as[a[i]].push_back(i);
  }
  Node seg(1, n+1);
  ll inversions = 0;
  for (auto [ai, v]: as) {
    for (int i: v) {
      inversions += seg.getsum(i, n+1); //???
    }
    for (int i: v) {
      seg.add(i, 1);
    }
  }
  return inversions;
}/*}}}*/

ll countInversionsBrute(int n, vector<int> a) {
  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] > a[j]) cnt++;
    }
  }
  return cnt;
}

struct SegtreeBrute {
  int s, e;
  vector<int> a;
  SegtreeBrute(int _s, int _e) {
    s = _s;
    e = _e;
    a = vector<int>(e+1, 0);
  }
  void add(int i, int x) {
    a[i] = x;
  }
  int minPrefix() {
    int ans = 0;
    int sum = 0;
    for (int i = s; i <= e; i++) {
      sum += a[i];
      ckmin(ans, sum);
    }
    return ans;
  }
};

ll solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n+1), b(m+1);
  deque<pair<int,int>> as;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    as.push_back({a[i], i});
  }
  sort(all(as));

  map<int,int> mpb;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    mpb[b[i]]++;
  }

  if (max(n, m) <= 500) {
    SegtreeBrute pfxSeg(0, n);
    for (int i = 1; i <= n; i++) pfxSeg.add(i, 1);

    ll numInversions = 0;
    int numSmaller = 0;
    for (auto [bi, cnt]: mpb) {
      while (!as.empty() && as.front().first < bi) {
        auto [ai, i] = as.front(); as.pop_front();
        pfxSeg.add(i, -1); 
        numSmaller++;
      }
      vector<int> bs;
      while (!as.empty() && as.front().first == bi) {
        auto [ai, i] = as.front(); as.pop_front();
        pfxSeg.add(i, 0); 
        bs.push_back(i);
      }

      ll add = 1LL * cnt * (numSmaller + pfxSeg.minPrefix());
      numInversions += add;

      for (int i: bs) {
        pfxSeg.add(i, -1);
        numSmaller++;
      }
    }

    numInversions += countInversionsBrute(n, a);
    return numInversions;
  }
  else {
    Node pfxSeg(0, max(n, m) + 5);
    for (int i = 1; i <= n; i++) pfxSeg.add(i, 1);

    ll numInversions = 0;
    int numSmaller = 0;
    for (auto [bi, cnt]: mpb) {
      while (!as.empty() && as.front().first < bi) {
        auto [ai, i] = as.front(); as.pop_front();
        pfxSeg.add(i, -1); 
        numSmaller++;
      }
      vector<int> bs;
      while (!as.empty() && as.front().first == bi) {
        auto [ai, i] = as.front(); as.pop_front();
        pfxSeg.add(i, 0); 
        bs.push_back(i);
      }

      ll add = 1LL * cnt * (numSmaller + pfxSeg.minPrefix());
      numInversions += add;

      for (int i: bs) {
        pfxSeg.add(i, -1);
        numSmaller++;
      }
    }

    numInversions += countInversions(n, a);
    /*
    if (numInversions == 2) {
      cout << n << ' ' << m << endl;
      for (int i = 1; i <= n; i++) {
        cout << a[i] << '\n';
      }
      for (int i = 1; i <= m; i++) {
        cout << b[i] << '\n';
      }
    }
    */
    return numInversions;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int T; cin >> T;
  while (T--) {
    cout << solve() << '\n';
  }
}
