#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0; i<n; i++)
#define sz(v) (int)(v.size())
#define prin(a) cout << #a << " = " << a << endl
#define prinv(v) cout << #v << " = "; for(auto it : v) cout << it << ", "; cout << endl
#define all(v) (v).begin(),(v).end()

typedef long long ll;

#define rmin(a,b) a = min<ll>(a,b)
#define rmax(a,b) a = max<ll>(a,b)

#define fi first
#define se second

template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }

vector<int> v;
vector<int> ans;

void oper(int i){
	assert(i>=0 and i+2<sz(v));
	int x = v[i]^v[i+1]^v[i+2];
	v[i] = x;
	v[i+1] = x;
	v[i+2] = x;
	ans.push_back(i);
}

void no(){
	cout << "NO\n";
}

void yes(){
	cout << "YES\n";
}

#define assert my_assert
void assert(int ok){
	if(!ok){
		prin(ok);
		freopen("input_errado","a", stdout);
		cout << "Erro - checar input_aux.txt" << endl;
		exit(0);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	fr(tt,t){
		int n; cin >> n;
		v.resize(n);
		fr(i,n) cin >> v[i];
		int p1 = -1, u1 = -1;
		int n1 = 0;
		fr(i,n){
			if(v[i]){
				if(p1==-1) p1 = i;
				u1 = i;
				n1++;
			}
		}
		if(n1%2 or n1==n){
			no();
			continue;	
		}
		if(n1==0){
			yes();
			cout << 0 << "\n";
			continue;
		}
		ans.clear();
		/*
		prin(n1);
		prin(p1);
		prin(u1);
		prinv(v);
		*/
		for(int i = p1; i+2<n and i+2<=u1; i++){
			if(v[i] and v[i+1]==0 and v[i+2]==0) oper(i);
		} 
		//prinv(v);
		
		int p0 = 0;
		while(p0<n and v[p0]) p0++;
		if(p0==n){
			no();
			continue;
		}
		int n1a = p0;
		if(p1){
			p0 = p1-1;
			n1a = 0;
		}
		/*
		prin(p0);
		prin(n1a);
		*/
		
		int p0b = p0-2, p0f = p0;
		if(n1a%2) oper(p0-1), p0b = p0-3, p0f = p0+1;
		while(p0b>=0){
			while(p0b+2>=n) p0b--;
			//prin(p0b);
			int q0 = 0;
			fr(di,3) q0+=v[p0b+di];
			if(q0==0) break;
			assert(q0<3);
			if(q0==1){
				p0b--;
			} else{
				oper(p0b);
				p0b-=2;
			}
			//prinv(v);
			//prin(p0b);
		}	
		//cout << endl;
		
		while(p0f+2<n){
			int q0 = 0;
			fr(di,3) q0+=v[p0f+di];
			if(q0==0) break;
			assert(q0<3);
			if(q0==1){
				p0f++;
			} else{
				oper(p0f);
				p0f+=2;
			}
		}
		
		fr(i,n) assert(v[i]==0);
		
		yes();
		cout << sz(ans) << "\n";
		assert(sz(ans)<=n);
		fr(i,sz(ans)){
			if(i) cout << " ";
			cout << ans[i]+1;
		}	
		cout << "\n";
		//cout << endl;
	}	
}
