/*	
    THINK DIFFRENT
    IT DOESNT EVEN MATTER TRICK

	-> see score distribution
	
	Building the soltion
    -> 1. DP  2 .Greedy 3.Binary search 4. Bruteforce 5.Math 
    -> think reaverse engirneering
	-> unstand the question
		->Notice every detail
		->see constrains carefully 
	-> do smth instead of nothing and stay organized
	-> write brute force
	-> WRITE STUFF DOWN
	-> DON'T GET STUCK ON ONE APPROACH
	-> Reduce the problem

	
	Wrong ans
	-> unstand the question again

	-> Check Complete Consept again
    -> Implimantation ??
	-> special cases (n=1||n==0||n==-1||empty stings||string with all same)?
	-> int overflow, array bounds
	-> clear the graph
	 
	-> special cases
	-> constrains
	-> use int instade of long long int   (this can do big improvement in time )
	
	Runtime error
	-> see the possible input
	-> int overflow, array bounds
	-> special case n==1, graph is disconnected 
	
	TLE
	-> dont use memset
	-> use less no of % operator and use iterative code
	-> long long int to int
	
*/
#include <bits/stdc++.h>
#define int               long long int
#define ld                long double
#define pb 				  push_back
#define fr                first
#define sc                second
#define INF               1e18    // LLONG_MAX	
#define all(x)            (x).begin(),(x).end()
#define PI                3.14159265358979323846
#define vi                vector<int>
#define pii               pair<int,int> 

#define d1(a)       //cout<<#a<<"="<<a<<"\n";
#define d2(a,b)   	//cout<<#a<<"="<<a<<" | "<<#b<<"="<<b<<"\n";
#define d3(a,b,c) 	//cout<<#a<<"="<<a<<" | "<<#b<<"="<<b<<" | "<<#c<<"="<<c<<"\n";

using namespace std;
const int MOD=1e9+7;
int mod(int a)   // a%b
{	
	
	int ans=a%MOD;
	if(ans<0) ans=ans+MOD;
	return ans;
}
int multi(int a,int b)
{
    return mod(mod(a)*mod(b));
}
int add(int a,int b)
{
    return mod(mod(a)+mod(b));
}
int sub(int a,int b)
{
    return mod((mod(a)-mod(b)));
}
int gcd(int a, int b)
{
    return (b?gcd(b,a%b):a);
}
int lcm(int a,int b)
{
    return (a*b)/(gcd(a,b));
}

 
//_____________________________________________________________________________________________ 

bool isPrime(int n)
{	assert(n>0);
 	if(n==1) return false;
     for(int i=2;i*i<=n;i++)
     {
         if(n%i==0)
         {
             return false;
         }
     }
     return true;
}

//_____________________________________________________________________________________________ 
 int Pow(int B,int power)
 {	
 	
 	int ans=1LL;
     while(power>0LL)
     {
         if(power%2LL==1LL)
         {
             ans=(ans*B);
         }
         B=(B*B);
         power/=2LL;
     }
     assert(ans>=1);
     return ans;
 }
 
 
 
 
 int powermod(int B, int power,int modulo)     //Fast Power
 {
     int ans=1LL;
     while(power>0LL)
     {
         if(power%2LL==1LL)
         {
             ans=(ans*B)%modulo;
         }
         B=(B*B)%modulo;
         power/=2LL;
     }
     return ans;
 }
 
int modInverse(int n, int p){
    return powermod(n,p-2,p);
}
int divide(int x,int y)
{
	return multi(x,modInverse(y,MOD));	
}
//_____________________________________________________________________________________________ 


int fact(int n)  // O(n)
{	
	if(n==0) return 1;
	assert(n>=0);
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=multi(ans,i);
	}
	return ans;
}
 
//_____________________________________________________________________________________________ 
int nCr(int n,int r)
{
	int ans1=fact(n);
	int ans2=multi(fact(n-r),fact(r));
	return multi(ans1,powermod(ans2,MOD-2,MOD));
}
//_____________________________________________________________________________________________
vector<int> primeFactors(int n)
{	//assert(false); 
	// 1 is included
	vector<int> ans;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0) 
			{
				ans.pb(i);
				n=n/i;
			}
		}
		
	}
	if(n>=2) ans.pb(n);
	//ans.pb(1);
	return ans;
}


//____________________________________________________________

const int N=2e5+5;





void solve() {
	
	int n;
	cin>>n;
	vi a(n+2,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	a[0]=-1;
	a[n+1]=-1;
	vi L(n+2,0);
	vi R(n+2,0);
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(L[i]==0)
		{
			int j=i;
			int cnt=1;
			for(;j<=n;j++)
			{	
				if((a[j]<a[j+1]))
				{
						
				}	
				else
				{	
					break;
				}
			}
			for(;j>=i;j--)
			{
				L[j]=cnt;
				cnt++;	
			}	
		}		
	}
	for(int i=n;i>=1;i--)
	{
		if(R[i]==0)
		{
			int j=i;
			int cnt=1;
			for(;j>=1;j--)
			{
				if((a[j-1]>a[j]))
				{
						
				}	
				else
				{	//j++;
					break;
				}
			}
		//	if(j<1) j++;
			for(;j<=i;j++)
			{
				R[j]=cnt;
				cnt++;	
			}	
		}		
	}
	
	for(int i=1;i<=n;i++)
	{
		d3(i,L[i],R[i]);
	}
	
	int i=1;
	int j=n;
	bool isAlice=false;
	bool blocked=false;
	int turn=1;  // alice
	int curr=0;
	while(i<=j)
	{
		if(turn==1) //alice
		{
			if(a[i]>curr&&a[j]>curr)
			{
				if(a[i]>=a[j])
				{
					if((L[i]%2)==1)
					{
						cout<<"Alice\n";
						return;
					}
					else
					{
						j--;
						curr=a[j+1];
						turn=0;
					}
				}
				else
				{
					if((R[j]%2)==1)
					{
						cout<<"Alice\n";
						return;
					}
					else
					{
						i++;
						curr=a[i-1];
						turn=0;
					}
				}
			}
			else  // one side is blocked
			{
				if(a[i]<=curr)
				{
					if((R[j]%2)==1)
					{
						cout<<"Alice\n";
						return;
					}
					else
					{
						cout<<"Bob";
						return;
					}
				}
				else
				{
					if((L[i]%2)==1)
					{
						cout<<"Alice\n";
						return;
					}
					else
					{
						cout<<"Bob";
						return;
					}
				}
			}
		}
		else
		{
			if(a[i]>curr&&a[j]>curr)
			{
				if(a[i]>=a[j])
				{
					if((L[i]%2)==1)
					{
						cout<<"Bob\n";
						return;
					}
					else
					{
						j--;
						curr=a[j+1];
						turn=1;
					}
				}
				else
				{
					if((R[j]%2)==1)
					{
						cout<<"Bob\n";
						return;
					}
					else
					{
						i++;
						curr=a[i-1];
						turn=1;
					}
				}
			}
			else  // one side is blocked
			{	d3(i,i,j);
				if(a[i]<=curr)
				{
					if((R[j]%2)!=1)
					{
						cout<<"Alice\n";
						return;
					}
					else
					{
						cout<<"Bob";
						return;
					}
				}
				else
				{
					if((L[i]%2)!=1)
					{
						cout<<"Alice\n";
						return;
					}
					else
					{
						cout<<"Bob";
						return;
					}
				}
			}
		}
	}
	
}


main()
{
//	cout<<setprecision(15); cout<<fixed;
 	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
    int t=1;
//	cin>>t;
   	for(int i=1;i<=t;i++)
   	{	
   		solve();
	} 
}

