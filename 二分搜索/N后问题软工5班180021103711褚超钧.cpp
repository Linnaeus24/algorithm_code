#include<stdio.h>
#include<math.h>
int x[9]={0};
bool PLACE(int k)//����k���ʺ��ܷ�Ž�����
{
    int i=1;
    while(i<k)
    {
        if(x[i]==x[k]||fabs(x[i]-x[k])==fabs(i-k))
            return false;
        i++;
    }
    return true;
}
void NQUEENS(int n)
{
    int i,k=1; //kΪ��ǰ�к�
    x[1]=0;//x[k]Ϊ��k�лʺ����ŵ��к�
    while(k>0)
    {
        x[k]++;
        while(x[k]<=n&&!PLACE(k))//���в����ϣ��������һ��
          x[k]++;
        if(x[k]<=n)
        {
            if(k==n)//���x[]
            {
                for(i=1;i<=n;i++)
                    printf("x[%d]:%d  ",i,x[i]);
                printf("\n");
            }

            else//�ж���һ��
            {
                k++; x[k]=0;
            }
        }
        else k--;//û�ҵ��������
    }
    return ;
}
int main()
{
    NQUEENS(8);
    return 0;
}
