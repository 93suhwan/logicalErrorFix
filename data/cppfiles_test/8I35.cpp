#include<bits/stdc++.h>
using namespace std;
template<class T,class S=T>inline bool umin(T&m,const S&x){return x<m?m=x,1:0;}
template<class T,class S=T>inline bool umax(T&m,const S&x){return m<x?m=x,1:0;}
auto operator<<(ostream&o,const auto&v)->enable_if_t<!is_constructible_v<string,decltype(v)>,decltype(o<<*end(v))>{int f=0,u=&o==&cerr&&o<<"[";for(auto&&x:v)(f++?o<<(u?", ":" "):o)<<x;return u?o<<"]":o;}
auto operator<<(ostream&o,const auto&t)->decltype(o<<get<0>(t)){o<<"<";apply([&o](auto&...x){int f=0;(((f++?o<<", ":o)<<x),...);},t);return o<<">";}
#ifdef BIZON
	#define rr(...) [](auto&&...x){ cerr << boolalpha << "\e[1;38;5;68m" << #__VA_ARGS__ << " "; int _=0; ((cerr<<"\e[0;38;5;61m"<<",="[!_++]<<"\e[0m "<<x),...)<<endl; }(__VA_ARGS__);
#else
	#define rr(...) 0;
	#define endl '\n'
#endif
#define ALL(c) begin(c), end(c)
#define fun(T, name, ...) function<T(__VA_ARGS__)> name = [&](__VA_ARGS__)->T
#define II(...) __VA_ARGS__; [](auto&...x){(cin>>...>>x);}(__VA_ARGS__);
#define ii(...) int II(__VA_ARGS__)
using ll = long long;

template<class ...T> struct edge_t : public tuple<size_t,T...> {
	edge_t(auto&&... args): tuple<size_t,T...>(args...) { }
	operator size_t() const { return get<0>(*this); }
};
template<class...T> struct std::tuple_size<edge_t<T...>> : tuple_size<tuple<size_t,T...>> {};
template<size_t I, class...T> struct std::tuple_element<I,edge_t<T...>> : tuple_element<I,tuple<size_t,T...>> {};

template<class ...T> struct graph_t {
	using E = conditional_t<sizeof...(T), edge_t<T...>, size_t>;
	explicit graph_t(size_t n): g(n) {}
	void add_dir_edge(size_t from, size_t to, auto&&... args) {
		assert(from<size() && to<size());
		g[from].emplace_back(to, args...);
	}
	void add_edge(size_t x, size_t y, auto&&... args) {
		add_dir_edge(x, y, args...);
		add_dir_edge(y, x, args...);
	}
	const vector<E>& operator[](size_t i) const { return g[i]; }
	size_t size() const { return g.size(); }
	private: vector<vector<E>> g;
};
using graph = graph_t<>;

template<bool heavy_by_size = true>
struct heavy_light_decomposition {
	heavy_light_decomposition(const auto &g, size_t root = 0):
		par(size(g),-1), header(size(g),-1), tin(size(g)), tn(0)
	{
		calc(g, root);
		build(g, root, root);
		assert(tn == size(g));
	}
	
	size_t index(size_t v) const { return tin[v]; }
	
	size_t query_path(size_t x, size_t y, auto process_range, bool ignore_lca = false) const {
		if(tin[x] > tin[y]) swap(x, y);
		for(size_t v; tin[v=header[y]] > tin[x]; y = par[v]) 
			process_range(tin[v], tin[y]+1);
		for(size_t v; (v=header[x]) != header[y]; x = par[v])
			process_range(tin[v], tin[x]+1);
		if(tin[x] > tin[y]) swap(x, y);
		if(size_t l = tin[x]+ignore_lca, r = tin[y]+1; l<r)
			process_range(l, r);
		return x;
	}
	
	size_t lca(size_t x, size_t y) const { return query_path(x, y, [](...){}); }
	
	private:
	vector<size_t> par, header, tin;
	size_t tn;
	
	size_t calc(const auto &g, size_t v) {
		size_t mx = 0, sz = 1;
		for(size_t i : g[v]) if(i!=par[v]) {
			par[i] = v;
			size_t x = calc(g, i);
			if(x > mx) mx = x, header[v] = i;
			if constexpr (heavy_by_size) sz += x;
		}
		if constexpr (heavy_by_size) return sz;
		else return mx + 1;
	}
	
	void build(const auto &g, size_t v, size_t f) {
		tin[v] = tn++;
		size_t mx = exchange(header[v], f);
		if(mx == -1) return ;
		build(g, mx, f);
		for(size_t i : g[v]) if(i!=par[v] && i!=mx) build(g, i, i);
	}
};

template<class T, bool well_formed = false>
struct segment_tree {
	segment_tree(size_t n, function<T(size_t)> gen) {
		if constexpr (!well_formed) d = n;
		else for(d=1; d<n; d<<=1);
		t.assign(d*2, {});
		for(size_t i=0;i<n;++i) t[i+d] = gen(i);
		for(size_t i=d;i-->1;) t[i] = T(t[i*2], t[i*2+1]);
	}
	
	void set_value(size_t i, const T &value) {
		for(t[i+=d] = value; i>>=1; ) t[i] = T(t[i*2], t[i*2+1]);
	}
	
	T operator()(size_t l, size_t r) const {
		const static T neutral{};
		T fl = neutral, fr = neutral;
		for(l+=d,r+=d; l<r; l>>=1,r>>=1){
			if(l&1) fl = T(fl, t[l]), ++l;
			if(r&1) --r, fr = T(t[r], fr);
		}
		return T(fl, fr);
	}
	
	decltype(auto) operator()() const {
		if constexpr (well_formed) return t[1];
		else return operator()(0, d);
	}
	
	private:
	vector<T> t;
	size_t d;
};

int main() {
	if(auto f="in.txt"; fopen(f,"r") && freopen(f,"r",stdin));
	cin.tie(0)->sync_with_stdio(0);
	
	ii(n, qn)
	
	vector<int> a(n);
	for(auto &_ : a) cin>>_;
	
	graph g(n);
	for(int k=0;k<n-1;++k) {
		ii(i, j)
		g.add_edge(--i, --j);
	}
	
	heavy_light_decomposition hld(g, 0);
	
	struct node {
		int first, last;
		ll sum;
		bool is_neutral;
		node() {
			is_neutral = true;
		}
		node(int x) {
			first = last = x;
			sum = 0;
			is_neutral = false;
		}
		node(const node &l, const node &r) {
			if(l.is_neutral) *this = r; else
			if(r.is_neutral) *this = l; else {
				first = l.first;
				last = r.last;
				int x = l.last, y = r.first;
				sum = l.sum + r.sum + max(abs(x+y),abs(x-y));
			}
		}
	};
	
	segment_tree<node> t(n, [](int i) { return node(0); });
	for(int i=0;i<n;++i) t.set_value(hld.index(i), node(a[i]));
	
	while(qn--) {
		ii(tp, v, u)
		--v;
		if(tp == 1) {
			t.set_value(hld.index(v), node(u));
			continue ;
		}
		--u;
		
		//copypasted
		auto &h = hld;
		vector<pair<size_t,size_t>> segs;
		h.query_path(v, u, [&](size_t l, size_t r){ segs.emplace_back(l,r); });
		
		bool flip = h.index(v) > h.index(u);
		if(flip) swap(v, u);
		
		sort(ALL(segs), [](const auto&p1, const auto&p2){ return p1.second > p2.second; });
		
		vector<pair<int,pair<int,int>>> q;
		size_t i = h.index(v);
		for(auto [l, r] : segs) if(r-1<=i) q.emplace_back(1, pair(l, r));
		reverse(ALL(segs));
		for(auto [l, r] : segs) if(r-1>i) q.emplace_back(0, pair(l, r));
		
		if(flip) {
			reverse(ALL(q));
			for(auto &[rev, seg] : q) rev^=1;
		}
		
		node res;
		for(auto [rev, seg] : q) {
			auto [l,r] = seg;
			node cur = t(l, r);
			if(rev) {
				swap(cur.first, cur.last);
			}
			res = node(res, cur);
		}
		//copypasted
		
		cout<<res.sum<<endl;
	}
	
	
	
	return 0;
}
