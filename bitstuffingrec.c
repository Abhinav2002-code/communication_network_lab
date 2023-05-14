#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

int i,j;
int sender(int arr[10],int n)
{
    int checksum,sum=0,i;
    printf("\n****SENDER SIDE****\n");
    for(i=0;i<n;i++)
        sum+=arr[i];
    printf("SUM IS: %d",sum);
    checksum=~sum;    //1's complement of sum
    printf("\nCHECKSUM IS:%d",checksum);
    return checksum;
}

void receiver(int arr[10],int n,int sch)
{
    int checksum,sum=0,i;
    printf("\n****RECEIVER****\n");
    for(i=0; i<n; i++)
        sum+=arr[i];
    printf("SUM IS:%d",sum);
    sum=sum+sch;
    checksum=~sum;    //1's complement of sum
    printf("\nRECEIVER's CHECKSUM IS:%d",checksum);
}

// Function for bit de-stuffing
void bitDestuffing(int N, char arr[])
{
    char brr[30];
    int i, j, k;
    i = 0;
    j = 0;
    int count = 1;
    while (i < N)
    {
        if (arr[i] == 1)
        {
            brr[j] = arr[i];
            for (k = i + 1; arr[k] == 1 && k < N && count < 5; k++)
            {
                j++;
                brr[j] = arr[k];
                count++;
                if (count == 5)
                {
                    k++;
                }
                i = k;
            }
        }

        else
        {
            brr[j] = arr[i];
        }
        i++;
        j++;
    }
    brr[j]='\0';
    printf("\nResult after Bit De-stuffing ");
    printf("%s", brr);
}

void characterCount_rec(int N, char arr[])
{
    char temp[30];
    int i=0;
    for(i=0; i<N; i++)
        temp[i] = arr[i];
    printf("\nAt receiver's side: ");
    printf("\nOutput: %s", temp);
}

int main()
{
    char str[100], bstr[100];
    int a[100],m,scheck,sch;
    char choice;
    printf("\n.....YOUR OPTIONS....\n");
    printf("\n a. Checksum\n b. Bit stuffing\n c. Character count\n");
    printf("\nEnter your choice:");
    scanf("%c",&choice);
    switch(choice)
    {
//Checksum Calculation
    case 'a':
    {
        printf("\nENTER SIZE OF THE STRING:");
        scanf("%d",&m);
        printf("\nENTER THE ELEMENTS OF THE ARRAY:");
        for(i=0; i<m; i++)
            scanf("%d",&a[i]);
        sch=sender(a,m);
        receiver(a,m,sch);
    }
    break;
//Bit stuffing
    case 'b':
    {
        int count=0;
        printf("Enter the bit string: ");
        scanf("%s",str);
        int N = strlen(str);
        for(i=j=0; str[i]; i++)
        {
            if(str[i]=='1') count++;
            else count=0;
            bstr[i+j]=str[i];
            if(count==5)
            {
                j++;
                bstr[i+j]='0';
                count=0;
            }
        }
        bstr[i+j]='\0';
        printf("\nAfter Bit stuffing : %s\n", bstr);
        printf("\nAt the Receiver's side: ");
        bitDestuffing(N, str);
    }
    break;
//Inserting character count code
    case 'c':
    {
        char arr[100];
        int x,y;
        printf("\nENTER THE ELEMENTS OF THE ARRAY:");
        scanf("%s",arr);
        printf("\nResultant Frame using character count = %d%s\n",strlen(arr)+1,arr);
        characterCount_rec(strlen(arr)+1, arr);
    }
    break;
    default:
        printf("\nYou entered an invalid choice run program again");
    }
    getch();
}