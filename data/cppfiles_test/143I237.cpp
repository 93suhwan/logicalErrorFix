// Problem: E. MEX and Increments
// Contest: Codeforces - Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
//#define int long long
#define lld long double
#define fi first
#define se second
#define vi vector<int>
#define vs vector<string>
#define vpii vector<pair<int,int>>
#define mii map<int,int>
#define pii pair<int,int>
#define pq priority_queue
#define loop(n) for(int i=0;i<n;i++)
#define fir(i,s,e) for(int i=s;i<e;i++)
#define intake(a,n) int n; cin>>n; vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];
#define out(a) for(int i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<"\n";
#define test int t; cin>>t; while(t--)
#define en "\n"
#define sortf(a) sort(a.begin(),a.end())
#define sortr(a) sort(a.rbegin(),a.rend())
#define all(a) a.begin(),a.end()
#define get_sum(a) accumulate(a.begin(),a.end(),0LL)
#define get_max(a) *max_element(a.begin(),a.end())
#define get_min(a) *min_element(a.begin(),a.end())
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int mod = 1000000007;
const int dom = 998244353;
const int N = 200001, inf = 2100000000;
const lld eps = 1e-6, pi = 3.1415926535897932;
const long long INF = 4000000000000000000LL;
// ans val flag temp fin fish eye kill stat tic tac time cnt cost

int32_t main()    
{

   
   //code goes here
   test
   {
   		int n;
   		cin>>n;
   		vector<int> a(n);
   		int freq[n+1]={0};
   		vector<int> fr;
   		
   		loop(n)
   		{
   			cin>>a[i];
   			
   			if(a[i]<=n)
   			freq[a[i]]++;
   			
   			
   			
   		}
   		
   		sortf(a);
   		
   		loop(n+1)
   		{
   			fr.pb(freq[i]);
   		}
   		vector<int> last;
   		vector<int> val(n+1,0);
   		
   		int ind=n;
   		
   		for(int i=0;i<=n;i++)
   		{
   			if(fr[i]==0)
   			{
   				if(last.size()==0)
   				{
   					ind = i;
   						break;
   				}
   			
   				
   				fr[i]=1;
   				val[i]=val[i-1]+i-last.back();
   				
   				fr[last.back()]--;
   				
   				if(fr[last.back()]==1)
   				last.pop_back();
   			}
   			else if(fr[i]>1)
   			{
   				if(i>0)
   				val[i]=val[i-1];
   				else
   				val[i]=0;
   				last.pb(i);
   			}
   			else
   			{
   				if(i>0)
   				val[i]=val[i-1];
   				else
   				val[i]=0;
   			}
   			
   		}
   		
   		
   		
   		
   		
   		
   		for(int i=0;i<=ind;i++)
   		{
   			int pos=lower_bound(all(a),i)-a.begin();
   			if(a[pos]!=i)
   			{
   				   if(i>0)
   					cout<<val[i-1]<<" ";
   				else
   				cout<<0<<" ";
   				
   			}
   			else
   			{
   				    if(i>0)
   					cout<<val[i-1]+freq[i]<<" ";
   				else
   				cout<<freq[i]<<" ";
   				
   			}
   			
   			
   			
   		}
   		
   		for(int i=ind+1;i<=n;i++)
   		cout<<-1<<" ";
   		
   		cout<<en;
   }
   

}

/*******************************************************************************









*******************************************************************************/




/*******************************************************************************

   set<int,greater<int>> a;//get highest element at begin
   
   map<int,string,greater<int>> b;//get highest element at begin
   
   priority_queue<int,vector<int>,greater<int>> c;//get lowest element on top
   
   vector<vector<int>> vec( n , vector<int> (m, 0)); //2D vector with known size
   
   vector<vector<int>> vec(siz); //2D vector with known row size
   
   vector<int> vec[siz]; //array of vectors

*******************************************************************************/