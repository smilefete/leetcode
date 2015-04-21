#include <stdio.h>
#include <stdlib.h>

int arr[]= {3,6,9,1};
typedef struct _bucket
{
    int max;
    int min;
} bucket;
int maximumGap(int num[], int n)
{
    if(n<2) return 0;
    int max,min,i;
    for(i=1,max=min=num[0]; i<n; i++)
    {
        if(num[i]>max)
        {
            max=num[i];
        }
        else if(num[i]<min)
        {
            min=num[i];
        }
    }
    int len=(max-min+1)/n;//Í°³¤¶È
    if((max-min+1)%n) len++;
    int size=(max-min+1)/len+1;
    bucket *buck=(bucket *)malloc(sizeof(bucket)*size);
    for(i=0; i<size; i++)
    {
        buck[i].max=buck[i].min=-1;
    }
    int value;
    for(i=0; i<n; i++)
    {
        value=(num[i]-min)/len;
        if(-1==buck[value].min)
        {
            buck[value].min=buck[value].max=num[i];
        }
        else if(num[i]>buck[value].max)
        {
            buck[value].max=num[i];
        }
        else if(num[i]<buck[value].min)
        {
            buck[value].min=num[i];
        }
    }
    int maxgap=len;
    int j=0;
    i=0;
    while(i<size)
    {
        if(buck[i].min!=-1) break;
        i++;
    }
    j=i;
    while(i<size)
    {
        if(buck[i].min!=-1)
        {
            if(buck[i].min-buck[j].max>maxgap)
            {
                maxgap=buck[i].min-buck[j].max;
            }
            j=i;
        }
        i++;
    }
    free(buck);
    return maxgap;
}
int main()
{
    printf("%d\n",maximumGap(arr,sizeof(arr)/sizeof(int)));
    return 0;
}






