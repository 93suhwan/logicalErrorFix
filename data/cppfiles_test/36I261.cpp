#include<bits/stdc++.h>
#define MOD (lli)(1e9+7)
#define PR 998244353
#define INF LLONG_MAX
#define newl cout<<'\n'
#define space cout<<' '
#define bar cout<<'-'
#define mt make_tuple 
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define vi vector<lli>
#define pll pair <lli,lli>
#define vpi vector<pll >
#define all(p) p.begin(),p.end()
#define lli long long
#define sz(a) (lli)((a).size())
#define form(i, l, r) for (lli i = l; i > r; --i)
#define forl(i, l, r) for (lli i = l; i < r; ++i)
#define pat(i, l, r, a); for (lli i = l; i < r; ++i){cout<<a[i]<<" ";}cout<<endl;
#define ppt(i, l, r, a); for (lli i = l; i < r; ++i){cout<<a[i].ff<<"-"<<a[i].ss<<" ";}cout<<endl;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
// typedef tree<lli,null_type,less<lli>,rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;
 
// unordered_map<lli, lli, custom_hash> mp;
// gp_hash_table<lli,lli, custom_hash> mp;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
// 10 power 8 operations is the current industry standard (remember !)
//at max arrays of 10e6 can only be declared inside main()  // At global scope the upper bound is 10e7
 
//vector front back push_back pop_back
//dequeue has both push_back and push_front and same for pop functions
//vector init can be done  as vi v{23,34,23,4}or v{arr,arr+n} or v{vec2.begin(),vec2.end()}
//or v(length_to_be_initialized,initialization_value )
 
//set find end insert erase //does not allow duplicates //use multiset for duplicates 
//implemented as red black binary search tree
//unordered_multiset or just multiset both have a function count //syntax set_name.count(element)
 
//prio q top push pop size empty emplace swap erase //allows duplic ates// implemented as max heap-
//use - minus distances for min heap
 
//lb lower_bound gives the position of the first element which is more than  or equal to the input 
//ub or upper_bound gives the postion of the first element which is more than the input.
//syntax for both : lower_bound(v,begin(), v.wnd(),input)
 
//make_tuple for more than a pair of values // get <index> (tuple_name) //indices are 0-indexed
//__builtin_popcount(element) gives no. of set bits in element
//Set operations like union, intersection, complement, difference : a|b,a&b,~(tilde)a, a&-(tilde)b.
 
//common error in code: 
//bitwise operators and referencing should always be used with brackets
//loops or condtional statements should not have the semicolon at the end
//look for equals to or double equals to carefully 
//check the prime number again for prime mod problems
//don't change loop varible or loop limits inside the loop  
//ctrl bv lines (remember the lazy sum jhol) don't cpy bllindly !!
//right shift 1 is division by 2
// const int N=1000; 
// for interactive problems print all queries using a single cout encing with endl

inline lli powmod(lli base,lli exponent,lli mod=MOD)
{ 
	lli ans=1;
	while(exponent)
	{
		if(exponent&1) ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent>>=1;
	}
	return ans;
}

// lli fs[N][N]={{1,1,1},{1,0,0},{0,1,0}};
// lli cs[N][N]={{1,1,1,2,-4},{1,0,0,0,0},{0,1,0,0,0},{0,0,0,1,1},{0,0,0,0,1}};
// // lli f2[N][N]={{1,1},{1,0}};
// //lli ars[N][N]={{1,1},{1,0}};

// lli temp[N][N];
// lli ret[N][N];

// void matmod(lli n,lli exponent,lli arr[N][N])
// {
// 	lli i,j,k,ans,mod=MOD-1;
// 	while(exponent>0)
// 	{
// 		if(exponent&1) 
// 		{
// 			forl(i,0,n)
// 			{
// 				forl(j,0,n)
// 				{
// 					ans=0;
// 					forl(k,0,n)
// 					{
// 						ans+=ret[i][k]*(arr)[k][j];
// 						ans%=mod;
// 					}
// 					temp[i][j]=ans;
// 				}
// 			}
// 			forl(i,0,n)
// 			{
// 				forl(j,0,n) ret[i][j]=temp[i][j];
// 			}
// 		}

// 		exponent>>=1;
// 		forl(i,0,n)
// 		{
// 			forl(j,0,n)
// 			{
// 				ans=0;
// 				forl(k,0,n)
// 				{
// 					ans+=(arr)[i][k]*(arr)[k][j];
// 					ans%=mod;
// 				}
// 				temp[i][j]=ans;
// 			}
// 		}
// 		forl(i,0,n)
// 		{
// 			forl(j,0,n) (arr)[i][j]=temp[i][j];
// 		}
// 	}
// }

// // vi v[N];
// // lli ans[N]={0};
// // lli vis[N]={0};
// // lli mx[N]={0};
// // lli val[N]={0};
// // lli dep=0;

// // void dfs2(lli ch,lli p)
// // {
// // 	vis[ch]=0;
// // 	if(mx[ch]<0) mx[ch]=max((lli)-1,mx[p]-1);
// // 	else 
// // 	{
// // 		mx[ch]=max(mx[ch],mx[p]);
// // 	}
// // 	for(auto x: v[ch])
// // 	{
// // 		if(vis[x])
// // 		{
// // 			dfs2(x,ch);
// // 			// mx[]+=max(dfs(p),0);
// // 		}
// // 	}
// // }
// // // <lli> st[100005];
// vi Pr;
// vector<vector<int>> vst(200009);
// inline void siv(lli n)
// {
// 	lli i,p;
// 	vector <bool> prime(n,1);

// 	for (p=2; p<=n; p++) 
// 	{ 
// 		if (prime[p] == true)
// 		{ 
// 			Pr.push_back(p);
// 			for (i=p; i<=n; i += p)//do i=p*p if you just want to find primes 
// 			{
// 				prime[i] = false;
// 				vst[i].pb(p);
// 			} 
// 		} 
// 	} 
// 	// for (i=p; i<=n; i++)
// 	// {
// 	// 	if (prime[i] == true)
// 	// 	{ 
// 	// 		Pr.push_back(i);
// 	// 		vst[i].pb(i);
// 	// 	}
// 	// }
// }

// // vi v[100005];
// // inline void fac(lli n)
// // {
// // 	lli i,j,k,p;
// // 	forl(i,1,n)
// // 	{
// // 		for(j=i;j<n;j+=i)
// // 		{
// // 			v[j].pb(i);
// // 		}
// // 	}
// // }


// // lli vis[N]={0};
// // lli ar[N];
// // unordered_map<lli,lli> mp;
// // void dfs(lli p,lli ch)
// // {
// // 	vis[p]=1;
// // 	for(auto x: v[p])
// // 	{
// // 		if(!mp[ar[x]])
// // 		{
// // 			continue;
// // 		}
// // 		lli tp=ar[p]-ar[x];
// // 		if(mp[tp])
// // 		{
// // 			mp[tp]--;
// // 		}
// // 		dfs(x,ch); 
// // 	}
// // }

// vpi so;
// int inv(int l,int m,int r)
// {
// 	lli n=r-l,a=l,b=m,c,d;
// 	pll tp[n];
// 	lli ct=0;
// 	forl(i,l,r)
// 	{
// 		// j=i-l;
// 		if(a>=m)
// 		{
// 			c=so[b].ff;
// 			d=so[b].ss;
// 			b++;
// 		}
// 		else if(b>=r)
// 		{
// 			c=so[a].ff;
// 			d=so[a].ss;
// 			a++;
// 		}
// 		else
// 		{
// 			if(so[a].ff<=so[b].ff)
// 			{
// 				c=so[a].ff;
// 				d=so[a].ss;
// 				a++;
// 			}
// 			else 
// 			{
// 				c=so[b].ff;
// 				d=so[b].ss;
// 				b++;
// 				// c=so[b++];
// 				ct+=m-a;
// 			}
// 		}
// 		tp[i-l]={c,d};
// 	}
// 	forl(i,l,r)
// 	{
// 		so[i]=tp[i-l];
// 	}
// 	return ct;
// }

// lli msort(int l,int r)
// {
// 	if(r-l<=1) return 0;
// 	else 
// 	{
// 		lli mid=(l+r)/2;
// 		lli inv1=msort(l,mid);
// 		lli inv2=msort(mid,r);
// 		lli ct=inv(l,mid,r);
// 		// pat(i,l,r,so);
// 		return inv1+inv2+ct;
// 	}
// }




// lli par[N]={0};
// lli rk[N]={0};
// int find(int a)
// {
// 	if(a==par[a]) return a;
// 	else
// 	{
// 		par[a] = find(par[a]);
// 		return par[a];
// 	}
// }
// int unite(int a,int b)
// {
// 	lli pa=find(a);
// 	lli pb=find(b);
// 	// return 1;
// 	if(pa==pb)
// 	{
// 		return 0;
// 	}
// 	else
// 	{
// 		if(rk[pa]<rk[pb])
// 		{
// 			swap(pa,pb);
// 		}
// 		rk[pa]=max(rk[pa],rk[pb]+1);
// 		par[pb]=pa;
// 		// cout<<pa;
// 		return 1; 
// 	}
// }

// int n;
// const lli M=200005;
// vi g[M], gt[M];
// vector<bool> used;
// vector<int> order, comp;
// vector<bool> assignment;

// void dfs1(int v) {
//     used[v] = true;
//     for (int u : g[v]) {
//         if (!used[u])
//             dfs1(u);
//     }
//     order.push_back(v);
// }

// void dfs2(int v, int cl) {
//     comp[v] = cl;
//     for (int u : gt[v]) {
//         if (comp[u] == -1)
//             dfs2(u, cl);
//     }
// }

// bool solve_2SAT() {
//     used.assign(n, false);
//     for (int i = 0; i < n; ++i) {
//         if (!used[i])
//             dfs1(i);
//     }

//     comp.assign(n, -1);
//     for (int i = 0, j = 0; i < n; ++i) {
//         int v = order[n - i - 1];
//         if (comp[v] == -1)
//             dfs2(v, j++);
//     }

//     assignment.assign(n / 2, false);
//     for (int i = 0; i < n; i += 2) {
//         if (comp[i] == comp[i + 1])
//             return false;
//         assignment[i / 2] = comp[i] > comp[i + 1];
//     }
//     return true;
// }
// lli dp[3][100002];

// lli dp1[20][20];
// lli dp2[20][20];
// lli s[20];
// lli upt(lli num)
// {

// 	lli n=0;
// 	lli d=0;
// 	lli tp=num;
// 	while(num)
// 	{
// 		s[n++]=num%10;
// 		num/=10;
// 	}
// 	memset(dp1,0,sizeof(dp1));
// 	memset(dp2,0,sizeof(dp2));

// 	dp1[0][0]=9;
// 	dp1[0][1]=1;

// 	dp2[0][0]=s[0];
// 	dp2[0][1]=1;
	
// 	forl(i,1,n)
// 	{
// 		forl(j,0,n-3)
// 		{
// 			dp1[i][j]=9*dp1[i-1][j];
// 			if(j) dp1[i][j]+=dp1[i-1][j-1];

// 			lli a=0;
// 			if(d>s[i])
// 			{
// 				a=dp1[i-1][j]*s[i];
// 				a+=dp2[i-1][j];
// 			}
// 			else if(d==s[i])
// 			{
			
// 				a=dp1[i-1][j]*s[i];
// 				if(j) a+=dp2[i-1][j-1];
// 			}
// 			else
// 			{
// 				if(s[i]) a=dp1[i-1][j]*(s[i]-1);
// 				if(j) a+=dp1[i-1][j-1];
// 				a+=dp2[i-1][j];
// 			}
// 			dp2[i][j]=a;
// 		}
// 	}
// 	lli ans=0;
// 	forl(i,0,n-3)
// 	{
// 		ans+=dp2[n-1][i];
// 		// cout<<dp2[n-1][i];space;
// 	}
// 	return (tp-ans);		
// }



// lli val[205];
// lli vis[205];
// lli dp[205];
// pll pr[105];
// lli n;
// void find(lli cur,lli pos)
// {
// 	// dp[cur]=val[cur];
// 	lli sc=pr[pos].ss;
// 	lli tp=(cur-n)/sc;
// 	if(tp)
// 	{
// 		vis[cur]=1;
// 		if(!vis[cur-tp*sc]) find(cur-tp*sc,pos+1);
// 		dp[cur]=min(val[cur],dp[cur-tp*sc]+tp*val[sc]);
// 	}
// 	else
// 	{
// 		if(!vis[cur]) find(cur,pos+1);
// 	}
// 	// return dp[cur];
// }




// const lli N=200005;
// vi v[N];
// lli unq[N]={0};
// lli vis1[N]={0};
// lli vis2[N]={0};
// lli depth[N]={0};
// lli dist[N]={0};
// lli fork[N]={0};

// lli dfs1(lli ch,lli d)
// {
// 	vis1[ch]=1;
// 	depth[ch]=d;
// 	d++;
// 	lli mx=-1;
// 	for(auto x: v[ch])
// 	{
// 		if(!vis1[x])
// 		{
// 			lli tp=dfs1(x,d);
// 			mx=max(tp,mx);
// 		}
// 	}
// 	if(unq[ch]) 
// 	{
// 		return ch;
// 	}
// 	else
// 	{
// 		unq[ch]=mx;
// 		return mx;
// 	}
// }

// void dfs2(lli ch,lli p,lli f,lli d)
// {
// 	vis2[ch]=1;
// 	d++;
// 	if(unq[ch]>0)
// 	{
// 		dist[ch]=depth[ch];
// 		fork[ch]=unq[ch];
// 	}
// 	else 
// 	{
// 		dist[ch]=depth[p]-d;
// 		// cout<<ch;bar;cout<<f;bar;cout<<p;bar;cout<<d;space;
// 		fork[ch]=unq[f];
// 	}
// 	for(auto x: v[ch])
// 	{
// 		if(!vis2[x])
// 		{
// 			if(unq[ch]>0)
// 			{
// 				dfs2(x,ch,unq[ch],0);
// 			}
// 			else
// 			{
// 				dfs2(x,p,f,d);
// 			}
// 		}
// 	}
// }

// const lli M=1e5;
// vi v[M+5];
// lli vis[M+5];
// lli lft[M+5];
// lli rit[M+5];
// vi ans;


int main() 
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	lli a,b,c,d,e,q,h,i,j,k,m,n,n1,n2,n3;
	lli t,tt;
	lli mod=MOD, inf=LLONG_MAX;// pr=998244353;

	srand(time(NULL));
	// use rand() for getting random values uptil?
	// time_t begin,end;
	// time(&begin);
	// time(&end);
	// double difference = difftime (end,begin);
	// cout<<difference;

	// memset(vis,0,sizeof(vis));
	// memset(col,0,sizeof(col));

	// const lli M=3e6;
	// memset(vis,0,sizeof(vis));

	// const lli M=1e6;

	// lli fac[M+5];
	// memset(fac,0,sizeof(fac));
	// forl(i,1,M+5)
	// {
	// 	for(lli j=i;j<=M;j+=i)
	// 	{
	// 		fac[j]++;
	// 	}
	// }



	for(cin>>t,tt=1;tt<=t;tt++,newl)
	{
		cin>>n;
		lli k=n/2;
		if(n%2)
		{
			forl(i,0,k)
			{
				cout<<'a';
			}
			cout<<"bc";
			forl(i,0,k-1)
			{
				cout<<'a';
			}
		}
		else
		{
			forl(i,0,k)
			{
				cout<<'a';
			}
			cout<<"b";
			forl(i,0,k-1)
			{
				cout<<'a';
			}
		}

	}	
}
