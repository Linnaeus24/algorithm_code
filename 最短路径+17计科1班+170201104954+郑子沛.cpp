#include <stdio.h> 

#define none 1000000          //  ���޴�Ϊ��ͨ 
#define NUM 4      //d����Ϊ4 
int a[NUM][NUM]={
        1,none,6,4,
        2,3,3,1,
        2,4,none,1,
        5,3,2,3
    };
#define OK 1
#define ERROR 0                 
typedef int status;

bool finish(bool *S,int n)          //�Ƿ���� ��Ѱ 
{
    for(int i=0;i<n;i++)
    {
        if(!S[i])
        return false;
    }
    return true; 
}

status djs(int n,int t)//a Ϊ���� n Ϊ��ĸ�����vΪ��ʼ�� 
{
    //��ʼ������v
    int D[n];
    for(int i=0;i<n;i++)
    D[i]=a[t][i];
    D[t]=0;
    //��ʼ���ѷ�������S;
    bool S[n];

    for(int i=0;i<n;i++)
    S[i]=false;

    S[t]=true;

    int j=0;
        int min=none;

    while (!finish(S,n))
    {   j=0;
        min=none;

        for(int i=0;i<n;i++)        //�ҵ��۲��������·����v,j�� 
        {
            if(S[i]) continue;

            if(min>D[i]) 
            {min=D[i];j=i;}     
        }   

        S[j]=true;      //��j����㼯S�� 

        for(int i=0;i<n;i++)        //���¹۲��� 
        {
            if(S[i]) continue;
            if(D[i]>D[j]+a[j][i])
            D[i]=D[j]+a[j][i];      
        }


    }

    for(int i=0;i<n;i++)                //��� 
    {
        printf("���·���ǣ�v,%d��������%d\n",i,D[i]);
    }
    return OK; 
}
int main()
{

    djs(NUM,1);
    return 0;

} 

