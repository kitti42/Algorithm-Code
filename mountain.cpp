/*in this question ,we had actully to find the number of distinct sub-arrays in an array
.so we make use of manber-myers suffix sort algorithm */
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#define MAX 100010
#define MOD 1000000009
using namespace std;
int a[100010];                 //input array
int Rank[MAX], suffixArray[MAX];   //output
int cnt[MAX], Next[MAX]; 
bool bh[MAX], b2h[MAX];
int Height[MAX];
int n;
//-----------------------------------------------------------------------------

bool smaller_int(int c, int b)
{
	return a[c] < a[b];     // Compares two sub-arrays according to their first characters
}
//-----------------------------------------------------------------------------

void suffixSort(int n)
{
	for (int i=0; i<n; ++i)
 {
		suffixArray[i] = i;
	}
	sort(suffixArray, suffixArray + n, smaller_int);
	//{suffixArray contains the list of suffixes sorted by their first character}

	for (int i=0; i<n; ++i){
		bh[i] = i == 0 || a[suffixArray[i]] != a[suffixArray[i-1]];
		b2h[i] = false;
		 printf("%d %d\n",i,bh[i]);
	}
printf("\n");
	for (int h = 1; h < n; h <<= 1){
		//{bh[i] == false if the first h characters of suffixArray[i-1] == the first h characters of suffixArray[i]}
		int buckets = 0;
		for (int i=0, j; i < n; i = j){
			j = i + 1;
			while (j < n && !bh[j]) j++;
			Next[i] = j;
			buckets++;
			printf("%d %d\n",i,Next[i]);
		}
		printf("\n");
		if (buckets == n) break; 
		//{suffixes are separted in buckets containing strings starting with the same h characters}

		for (int i = 0; i < n; i = Next[i]){
			cnt[i] = 0;
			for (int j = i; j < Next[i]; ++j){
				Rank[suffixArray[j]] = i;
				printf("%d %d\n",suffixArray[j],i);
			}
		}printf("\n");

		cnt[Rank[n - h]]++;
		b2h[Rank[n - h]] = true;                         //to get the true rank of numbers bases on first h characterz...
		for (int i = 0; i < n; i = Next[i]){
			for (int j = i; j < Next[i]; ++j){
				int s = suffixArray[j] - h;
				if (s >= 0){
					int head = Rank[s];                         //count maintains number of characterz having same h.helps to get rank..
					Rank[s] = head + cnt[head]++;
					b2h[Rank[s]] = true;
					printf("%d %d\n",s,Rank[s]);
				}
			}
			for (int j = i; j < Next[i]; ++j){
				int s = suffixArray[j] - h;                    //in next loop v l want bh for h=2*h..so v maintain b2h
				if (s >= 0 && b2h[Rank[s]]){
					for (int k = Rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
				}
			}
		}printf("\n");
		for (int i=0; i<n; ++i){
			suffixArray[Rank[i]] = i;       //change the suffix array acc t ranks...
			bh[i] |= b2h[i];               
		}
	}
	for (int i=0; i<n; ++i)
	{                                      
		Rank[suffixArray[i]] = i;
	}
}
// End of suffix array algorithm



void getHeight(int n)     /*now as we have correct ranks..we just need t c how many characters of i match j...so that many chracters need 
                           to be substracted from total number of subarrays*/
{
	//for (int i=0; i<n; ++i) Rank[suffixArray[i]] = i;
	Height[0] = 0;
	for (int i=0, h=0; i<n; ++i)
	{
		if (Rank[i] > 0)
		{
			int j = suffixArray[Rank[i]-1];
			while (i + h < n && j + h < n && a[i+h] == a[j+h])
			{
				h++;
			}
			Height[Rank[i]] = h;
			if (h > 0) h--;
		}
	}
}
// End of longest common prefixes algorithm
int main()
{
 int t;
	scanf("%d",&t);
	while(t--)
	{
  scanf("%d",&n);
		int b,c;
		scanf("%d",&b);
  for(int i=0;i<n-1;i++)
  {
   scanf("%d",&c);
   a[i]=b-c;
   b=c;
  }
  int p=--n;             //because our new array has 1 less length..ex.original array 5 4 3 2 1 => new subtracted array 1 1 1 1
		suffixSort(p);
		getHeight(p);

		int diff;
  long long int results=0;
		for(int i=0;i<p;++i)
		{
			diff=(n-suffixArray[i])-Height[i];
			results=results+diff;
			results%=MOD;
		}
		printf("%lld\n",results);

	}
	return 0;
}
