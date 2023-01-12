#include <stdio.h>


void hopcounts(int n ,int arr[n][n],int line[n][n])
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                line[i][j]=k;
            }
            for(int j=0;j<n;j++)
            {   
                if(arr[i][j]>arr[i][k]+arr[k][j])
                {
                    arr[i][j]=arr[i][k]+arr[k][j];
                    line[i][j]=k;
                }
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter number of vertices:");
    scanf("%d",&n);
     printf("Enter array elements:\n");
    int arr[n][n];
    int line[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    char label[]={'A','B','C','D','E'};
    hopcounts(n,arr,line);
    for(int i=0;i<n;i++)
    {   printf("From vertex %c\t",label[i]);
        for(int j=0;j<n;j++)
        {
           printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++)
    {   
        // printf("From vertex %c",label[i]);
        for(int j=0;j<n;j++)
        {
           printf("%d\t",line[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

