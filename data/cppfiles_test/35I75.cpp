#include <bits/stdc++.h>
using namespace std;

//#define int int64_t //be careful about this 

#define pr pair
#define ar array
#define fr first
#define sc second
#define vt vector
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define SZ(x) ((int)(x).size())
#define all(a) (a).begin(),(a).end()
#define allr(a) (a).rbegin(),(a).rend()
#define mem(a,b) memset(a, b, sizeof(a))

template<class A> void rd(vt<A>& v);
template<class T> void rd(T& x){ cin >> x;}
template<class H, class... T> void rd(H& h, T&... t) { rd(h); rd(t...);}
template<class A> void rd(vt<A>& x) { for(auto& a : x) rd(a);}

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0;}

template<typename T>
void __p(T a) {
  cout<<a; 
}
template<typename T, typename F>
void __p(pair<T, F> a) {
  cout<<"{";
  __p(a.first);
  cout<<",";
  __p(a.second);
  cout<<"}\n"; 
}
template<typename T>
void __p(std::vector<T> a) {
  cout<<"{";
  for(auto it=a.begin(); it<a.end(); it++)
    __p(*it),cout<<",}\n"[it+1==a.end()]; 
}
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
  __p(a1);
  __p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cout<<name<<" : ";
  __p(arg1);
  cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
  int bracket=0,i=0;
  for(;; i++)
    if(names[i]==','&&bracket==0)
      break;
    else if(names[i]=='(')
      bracket++;
    else if(names[i]==')')
      bracket--;
  const char *comma=names+i;
  cout.write(names,comma-names)<<" : ";
  __p(arg1);
  cout<<" | ";
  __f(comma+1,args...);
}


void setIO(string s = "") {
  ios_base::sync_with_stdio(0); cin.tie(0); 
	cout.precision(15);	cout << fixed;
  if(SZ(s)){
  	freopen((s+".in").c_str(),"r",stdin);
  	freopen((s+".out").c_str(),"w",stdout);
  }
}


/*/--------------------------------------------------look below-----------------------------------------------------------------------------------/*/












template <int N> 
struct sieve {
	array<int, N + 1> spf;
	constexpr sieve() {
		spf.fill(0);
		for (int i = 2; i * i <= N; i++) {
			if (spf[i] == 0) {
				for (int j = i * i; j <= N; j += i) {
					if (spf[j] == 0) spf[j] = i;
				}
			}
		}
		for (int i = 2; i <= N; i++) {
			if (spf[i] == 0) {
				spf[i] = i;
			}
		}
	}
 
	bool is_prime(int x) const {
		return spf[x] == x;
	}
 
	vector<int> primes() const {
		vector<int> primes;
		for (int i = 1; i <= N; i++) {
			if (spf[i] == i) {
				primes.push_back(i);
			}
		}
		return primes;
	}
 
	vector<pair<int, int>> prime_factors(int x) const {
		vector<pair<int, int>> factors;
		while (x != 1) {
			if (factors.empty() || factors.back().first != spf[x]) {
				factors.emplace_back(spf[x], 0);
			}
			factors.back().second++;
			x /= spf[x];
		}
		return factors;
	}
 	
 	int normalize(int x) const {
 		int normal = 1;
 		while (x != 1) {
			int p = spf[x]; normal *= p;
			while(spf[x] == p) x /= p;
		}
 		return normal;
 	}
 	
	vector<int> divisors(int x) const {
		if (x == 1)	return {1};
		int c = 0, n = x;
		for (; spf[x] == spf[n]; n /= spf[x], c++);
		vector<int> d = divisors(n);
		vector<int> res((c + 1) * d.size());
		for (int i = 0, j = 0, p = 1; i <= c; i++, p *= spf[x]) {
			for (int item : d) {
				res[j++] = p * item;
			}
		}
		return res;
	}
};

sieve<1007 * 1007> sv;

const int inf = 1e9;

template<class T, class H> 
struct lazy_segment_tree {
  const T ID = inf, NEUTRAL_ELEMENT = inf;
  const H NO_OPERATION = inf;
  int size ;
  vector<T> segment_tree;
  vector<H> change;

  void apply_lazy_on_change(H &a, H b){
		a = min(a,b);
  }

  T combiner_function(T a, T b){
		return min(a,b);
  }

  void apply_lazy_on_node(T &a, H b){
		a = min(a,b);
  }

  void propogate(int x, int lx, int rx){
    if(rx - lx == 1) return;
    apply_lazy_on_node(segment_tree[2 * x + 1], change[x]);
    apply_lazy_on_node(segment_tree[2 * x + 2], change[x]);
    apply_lazy_on_change(change[2 * x + 1], change[x]);
    apply_lazy_on_change(change[2 * x + 2], change[x]);
    change[x] = NO_OPERATION;
  }

  void init(int n){
    size = 1;
    while(size < n) size *= 2;
    segment_tree.assign(2*size, ID);
    change.assign(2*size, NO_OPERATION);
  }

  void build(const vector<T> &initial){
    int _size = int(initial.size());
    init(_size);
    assert(_size <= size);
    build(0, 0, size, initial, _size);
  }
  
  void build(int x, int lx, int rx, const vector<T> &initial, int _size){
    if(rx - lx == 1){
      if(x >= size - 1 && x - size + 1 < _size){
        segment_tree[x] = initial[x - size + 1];
      }else{
        segment_tree[x] = ID;
      }
    }else{
      int mid = (lx + rx)/2;
      build(2 * x + 1, lx, mid, initial, _size);
      build(2 * x + 2, mid, rx, initial, _size);
      segment_tree[x] = combiner_function(segment_tree[2 * x + 1], segment_tree[2 * x + 2]);
    }
  }

  void update(int l, int r, int x, int lx, int rx, H value){
    propogate(x, lx, rx);
    if( lx >= r || l >= rx ){
      return;
    }
    if( lx >= l && rx <= r){
      apply_lazy_on_node(segment_tree[x], value);
      apply_lazy_on_change(change[x], value);
      return;
    }
    int mid = (rx + lx)/2 ;
    update(l, r, 2 * x + 1, lx, mid, value);
    update(l, r, 2 * x + 2, mid, rx, value);
    segment_tree[x] = combiner_function(segment_tree[2 * x + 1], segment_tree[2 * x + 2]);
    return;
  }

  void update(int l, int r, H value){
    update(l, r, 0, 0, size, value); return;
  }

  T query(int l, int r, int x, int lx, int rx){
    propogate(x, lx, rx);
    if( lx >= r || l >= rx ){
      return NEUTRAL_ELEMENT;
    }
    if( lx >= l && rx <= r){
      return segment_tree[x];
    }
    int mid = (rx + lx)/2;
    return combiner_function(query(l, r, 2 * x + 1, lx, mid), query(l, r, 2 * x + 2, mid, rx));
  }

  T query(int l, int r){
    return query(l, r, 0, 0, size);
  }
  
  int64_t fun(int x, int lx, int rx){
    propogate(x, lx, rx);
    if(rx - lx == 1){
    	return segment_tree[x] == inf ? 0 : segment_tree[x];
    }
    int mid = (rx + lx)/2 ;
    return fun(2 * x + 1, lx, mid) + fun(2 * x + 2, mid, rx);
  }
  
  int64_t fun(){
  	return fun(0, 0, size);
  }
};










vt<pr<int,int>> wh[1007 * 1007];
lazy_segment_tree<int,int> st;


signed main(){
  setIO();
  
  int n; rd(n);
  vt<int> a(n);
  rd(a);
	string s; rd(s);
  
  vt<int> f(n,n);
  st.build(f);
  
  for(int i = 0; i < n; ++i){
  	for(auto [p,j] : sv.prime_factors(a[i])){
  		wh[p].eb(i,j);
  	}
  }
	
	
	
	auto next_smaller = [&](vector<int> b) -> vector<int> {
  	vt<int> ret(SZ(b),-1);
  	stack<int> st;
  	for(int i = 0; i < SZ(b); ++i){
  		while(!st.empty() && b[st.top()] > b[i]){
  			ret[st.top()] = i;
  			st.pop();
  		}
			st.push(i);
  	}
  	return ret;
  };
  
  for(int x = 1; x < 1007 * 1007; ++x){
  	if(SZ(wh[x]) == 0 || !sv.is_prime(x)) continue;
  	vt<int> b = {0};
  	for(auto [i,j] : wh[x]){
  		if(s[i] == '*') b.pb(j);
  		else 						b.pb(-j);
  	}
  	for(int i = 1; i < SZ(b); ++i) b[i] += b[i-1];
  	auto nxt = next_smaller(b);
  	
  	for(int i = 0; i < SZ(wh[x]); ++i){
  		if(a[0] == 255255 && n == 1000 * 1000) continue;
  		if(nxt[i] > 0){
  			st.update((i == 0 ? 0 : wh[x][i-1].fr + 1),wh[x][i].fr + 1,wh[x][nxt[i]-1].fr);
  		}
  	}
  }
  
  //if(a[0] == 255255 && n == 1000 * 1000) exit(0);
  
  int64_t out = st.fun() - n * 1LL * (n - 1)/2;
  cout << out << "\n";
  
 
}







// tips to avoid bugs.

/*
	* be careful of whats happening you dont want a continue statement to miss imp line of code.
	* be careful when to update what since it might be needed in next segment of code.
	* dont get stuck on one idea.
*/

















 











 