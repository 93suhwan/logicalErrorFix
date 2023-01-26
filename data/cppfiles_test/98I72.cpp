#include <stdio.h> // header file for Standard Input Output
#include <stdlib.h> // header file for Standard Library
#include <string.h>
int main() {

	int n;
	char alphabets[26]; 
	scanf("%d",&n);
	while(n>0){
		scanf("%s",alphabets);
		int cost=0;
		char str[100];
		scanf("%s",&str);

		int index(char a)
		{
			for(int i=0;i<25;i++)
			{
				if(a == alphabets[i]){
					return i+1;
				}
			}
		}

		if(strlen(str)<=1){
			cost = 0;
		}

		else{
			for(int i=0;i<strlen(str)-1;i++)
			{
				int idx1 = index(str[i]);
				int idx2 = index(str[i+1]);

				int dist = idx1- idx2;
				if(dist<0){
					dist = dist * -1;
				}
				cost =cost + dist;
			}
		}
		
		printf("%d\n",cost);
		n--;
	}
}