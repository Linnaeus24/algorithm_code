void matrixChain(){
    for(int i=1;i<=n;i++)m[i][i]=0;

    for(int r=2;r<=n;r++)//�Խ���ѭ��
        for(int i=1;i<=n-r+1;i++){//��ѭ��
            int j = r+i-1;//�еĿ���
            //��m[i][j]����Сֵ���ȳ�ʼ��һ�£���k=i
            m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            //k��i+1��j-1ѭ����m[i][j]����Сֵ
            for(int k = i+1;k<j;k++){
                int temp=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(temp<m[i][j]){
                    m[i][j]=temp;
                    //s[][]������¼��������i-j���У���kλ�ô�
                        �Ͽ��ܵõ����Ž�
                    s[i][j]=k;
                }
            }
        }
}