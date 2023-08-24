#include<stdio.h>
#define size 23
typedef struct bigint_type
{
    int arr[size];
    int length;
}bigint;

bigint input()
{
    char temp[size];
    int length_t=0;
    char t;
    int i=0;
    scanf("%c", &t);
    while(t!='\n')
    {
       temp[i]=t;
       length_t++;
       i++;
       scanf("%c", &t);
    }
    int itr=length_t-1;
    i=0;
    bigint b;
    b.length=0;
    while(itr>=0)
    {
       b.arr[i]=temp[itr]-'0';
       b.length++;
       itr--;
       i++;
    }
    return b;
    
}

void output(bigint b)
{
    b.length-=1;
    while(b.length>=0)
    {
      printf("%d", b.arr[b.length]);
      b.length-=1;
    }
    printf("\n");
}

bigint addition(bigint b1, bigint b2)
{
    int f=0,s=0, carry=0, add=0;
    bigint ans;
    ans.length=0;
    while(f<b1.length && s<b2.length)
    {
        add=b1.arr[f]+b2.arr[s]+carry;
        ans.arr[ans.length]=add%10;
        ans.length++;
        f++;
        s++;
        carry=add/10;
    }
    while(f<b1.length)
    {
        add=b1.arr[f]+carry;
        ans.arr[ans.length]=add%10;
        ans.length++;
        f++;
        carry=add/10;

    }

    while(s<b2.length)
    {
        add=b2.arr[s]+carry;
        ans.arr[ans.length]=add%10;
        ans.length++;
        s++;
        carry=add/10;

    }
    if(carry!=0)
    {
        ans.arr[ans.length]=carry;
        ans.length++;
    }
    return ans;
    
}

bigint subtraction(bigint b1, bigint b2)
{
    int underflow=0;
    int f=0, s=0, carry=0;
    bigint ans;
    ans.length=0;
    while(f<b1.length && s<b2.length)
    {
        if(b1.arr[f]>=(b2.arr[s]+carry))
        {
           ans.arr[ans.length]=b1.arr[f]-(b2.arr[s]+carry);
           carry=0;
        }
        else
        {
            ans.arr[ans.length]=(b1.arr[f]+10)-(b2.arr[s]+carry);
            carry=1;
        }
        f++;
        s++;
        ans.length++;
    }
    while(f<b1.length)
    {

        if(b1.arr[f]>=(carry))
        {
           ans.arr[ans.length]=b1.arr[f]-(carry);
           carry=0;
        }
        else
        {
            ans.arr[ans.length]=(b1.arr[f]+10)-(carry);
            carry=1;
        }
        f++;
        ans.length++;
        
    }
    if(s<b2.length)
    {
        underflow=1;
    }
    if(carry!=0)
    {
        underflow=1;
    }
    if(underflow==1)
    {
        ans.arr[0]=-1;
        
    }
    return ans;
}

bigint Multiply(bigint b1, bigint b2)
{
    int l1=b1.length;
    int l2=b2.length;
    bigint ans;
    ans.length=0;
    int  itr2=0;
    while(itr2<l2)
    {
        bigint temp;
        temp.length=0;
        for(int i=0;i<itr2;i++)
        {
            temp.arr[temp.length]=0;
            temp.length++;
        }
        int carry=0;
        for(int i=0;i<l1;i++)
        {
            int prod=(b2.arr[itr2]*b1.arr[i])+carry;
            carry=prod/10;
            temp.arr[temp.length]=prod%10;
            temp.length++;
        }
        if(carry!=0)
        {
            temp.arr[temp.length]=carry;
            temp.length++;
        }
        
        ans=addition(ans,temp);
        itr2++;
        

    }

    return ans;
}

int main()
{
    //1.input
    bigint b1, b2;
    printf("Enter two numbers : \n");
    b1=input();
    b2=input();

    int opt;
    printf("Enter the 1, 2, 3 for additon, subtraction and multiplication and other number to exit\n");
    scanf("%d", &opt);
    
    
    switch(opt)
    {
        case 1:
            bigint ans=addition(b1, b2);
            output(ans);
            break;
        
        case 2:
            bigint sub=subtraction(b1, b2);
            if(sub.arr[0]!=-1)
            {
                output(sub);
            }
            else
            {
                printf("There is a undeflow\n");
            }
            break;
        
        case 3:
            bigint mul=Multiply(b1, b2);
            output(mul);
            break;

            
    }
    
    


   
   
   





    

}