#include <bits/stdc++.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


typedef struct student {
    char id[10];    // ѧ��ID
    char name[20];  // ѧ������
    char mima[10]; //���� 
    char score[10]; // ѧ������ 
    char classes[10];//ѧ���꼶 
    struct student *next;
}Student;

Student *head=NULL;// ��������ͷָ��


void mathcreat(double c);//���ɵ������� 
void opreat(); 
void title(char s1,char s2,int t1,int t2,int t3,int t4);//�ݹ麯��
 void titlecreat();//�ݹ�������Ŀ 
void zhuce();//ѧ��ע�� 
void denglu(char s[]);//ѧ����¼ 
void shanchu();//ɾ��ѧ��
void loadStudents();//����ѧ����Ϣ 
void chaxun(char []);//���˲�ѯ 
void xiugaic(char s[],int count);//�޸ķ���
void xiugaix(char s[]);//�޸���Ϣ 
void liulanp();//���ѧ����Ϣ 
void liulana();//���꼶��ѯ 
void fengzhuang(char s[]);//��װ���⺯�� 


int M,N;//ҳ������Ŀ�� 
int an;//����Ĵ� 
int temp=0;
double ct;//�꼶 
int key=0;
int p=0;
int cid;




int main()
{
	string str1="student";
	string str2="teacher";
	string id;
	loadStudents();
	opreat();
	cin>>id;
	if(str1==id)//ѧ����� 
	{
    cout<<"�й��û���Ϣ����"<<endl;
	cout<<"��¼����1��ע������2"<<endl;
	int cho;
	cin>>cho;
	
		if(cho==1)//��¼ 
		{
		char s[10];
		printf("�������˺�:");
		scanf("%s",s);
		denglu(s);
	    int xz;
	    
		if(temp==1)
		{
			while(1)
	        {
			cout<<"������Ŀ����1,��ѯ�ɼ�����2���޸���Ϣ����3,����4�˳�"<<endl;
			cin>>xz;
		        if(xz==1) 
		        {
			        printf("��������Ŀҳ��\n");
	                cin>>M;
	                printf("������ÿҳ��Ŀ��\n");
	                cin>>N;
	                int count=M*N;
	                fengzhuang(s);
                }
            
                else if(xz==2)//��ѯȫ��ɼ� 
		        {
		            chaxun(s);
	            }
	    
	            else if(xz==3)
	            {
	    	        xiugaix(s);
		        }
		
	            else if(xz==4)
	            {
	    	        exit(0);
		        }
	        }
		}
		
	    }
		else if(cho==2)//ע�� 
		zhuce();
	}
	
    else if(id==str2)
    {
    	int n;
    	while(1)
    	{
    		printf("¼��ѧ����Ϣ����1\n");
    		printf("ɾ��ѧ����Ϣ����2\n");
    		printf("���ѧ����Ϣ����3\n");
    		printf("���꼶Ϊ��λ���ѧ����Ϣ����4\n");
    		printf("����5�˳�\n");
    		scanf("%d",&n);
    		switch(n)
    		{
    			case 1:
    				zhuce();
    				break;
    			case 2:
    				shanchu();
    				break;
    			case 3:
    				liulanp();
    				break; 
    			case 4:
    				liulana();
    				break;
    			case 5:
				    exit(0); 
			}
		}
	}
	else cout<<"�������������"; 
	return 0;
}
////������ 





void titlecreat() 
{
	char a;
	int z,t;
	z=1+rand()%3;//�������ɼ������� 
	t=rand()%2;//���������Ƿ��������� 
	if(t==1) title('(',a,z,z,0,0);
	else if(t==0) title(a,a,z,z,1,0);//z�����Ÿ��� 
	cout<<'=';
} 


int numcreat()//��������
{
    return 1+rand()%100;
}


char pcreat()//���������
{
	int t;
	t=rand()%4;
	if(t==0) return '+';
	if(t==1) return '-';
	if(t==2) return '*';
	if(t==3) return '/';
}


void numscreat()//���ɵ�������
{
	int num;
	char s;
	num=numcreat();
	cout<<num;
	s=pcreat();
	cout<<s;
	num=numcreat();
	cout<<num;
}


void title(char s1,char s2,int t1,int t2,int t3,int t4) //t3,t4���ִ��������� 
{
    int m;
    m=0;
	int num;
	char s;
	int ta=rand()%2;//[0,1] 
    int tb=rand()%2;//��� 
    int tc=rand()%2;
    int td=rand()%2;
	char a;
	if(s1=='('&&t1>0)//���s1==(,���(,t1--��������һ������ 
	{
		p++;
		cout<<'(';
		t1--;
		title(a,a,t1,t2,1,0);
	}
	else if(s1==a)//s1��Ϊ(���������. 
	{
		if(t3==1)//t3==1
		{
			numscreat();//����һ������ 
			if(tb==1&&p>0)//���� �Ƿ����������� 
			{
		    p--;
			title(a,')',t1,t2,0,0);
		    }
			else title(a,a,t1,t2,0,1);
		}
		else if(t4==1)//t4==1
		{
		    s=pcreat();
		    cout<<s;
		    if(s=='/') m=1;
		    if(tc==0&&t1>0&&m==0) title('(',a,t1,t2,0,0);//�����Ƿ����������� 
		    else title(a,a,t1,t2,1,0);
		}
	}
	if(s2==')')
	{
		t2--;
		cout<<')';
		if(t2==0)
		{
			s=pcreat();
			cout<<s;
    	    num=numcreat();
    	    cout<<num;
    	    return;
		}
		else
		{
			s=pcreat();
			cout<<s;
			if(s=='/') m=1;
			if(td==0&&t1>0&&m==0) title('(',a,t1,t2,0,0);//�����Ƿ����������� 
		    else title(a,a,t1,t2,1,0);
		}
	}
}


void mathcreat(double c) 
{
	int v=0;
	int t1=rand()%2;//+,-��*,/ 
	int t2=rand()%4;//+,-,*,/
	
	int num;
	int num1=rand()%6;//[0,5]
	int num2=rand()%11;//[0,10]
	int num3=rand()%21;//[0,20]
	int num4=rand()%100;//[0,99]
	int num5=rand()%101;//[0,100]
	int num6=rand()%10;//[0,9]
	int num7=1+rand()%9;
	int num8=10+rand()%90;
	int num9=rand()%300;
	if(c==1)
	{
		switch(t1)
		{
			case 0:num=rand()%6;
			printf("%d+%d=",num1,num);
			an=num1+num;
			break;
			case 1:if(num1==0) num=0;
			else num=rand()%num1;//��ֹ�������ָ��� 
			printf("%d-%d=",num1,num);
			an=num1-num;
			break;
		}
	}
	else if(c==1.5)
	{
		switch(t1)
		{
			case 0:num=rand()%11;
			printf("%d+%d=",num2,num);break;
			case 1:if(num2==0) num=0;
			else num=rand()%num2;
			printf("%d-%d=",num2,num);break;
		}
	}
	else if(c==2)
	{
		switch(t1)
		{
			case 0:num=rand()%21;
			printf("%d+%d=",num3,num);break;
			case 1:if(num3==0) num=0;
			else num=rand()%num3;
			printf("%d-%d=",num3,num);break;
		}
	}
	else if(c==2.5)
	{
		switch(t1)
		{
			case 0:num=rand()%101;
			printf("%d+%d=",num5,num);break;
			case 1:if(num5==0) num=0;
			else num=rand()%num5;
			printf("%d-%d=",num5,num);break;
		}
	}
	else if(c==3)
	{
			num=1+rand()%9;
			printf("%d*%d=",num7,num);
	}
	else if(c==3.5)
	{
	        int t;
		    num=1+rand()%9;
		    t=1+rand()%9;
		    printf("%d/%d=",num*t,num);
	}
	else if(c==4)
	{
		printf("%d*%d=",num6,num8);
	}
	else if(c==4.5)
	{
		int answer;
		int t;
		while(1)
		{
		num7=1+rand()%9;
		num=1+rand()%9;
		t=num*num7;
		if(t>=10&&v!=M*N)
		{
			v++;
			printf("%d/%d=",t,num);
			cin>>answer;
			if(v%M==0) cout<<endl;
		}
		if(v==M*N) break;
	    }
	}
	else if(c==5)
	{
		switch(t1)
		{
			case 0:num=rand()%500;
			printf("%d+%d=",num9,num);break;
			case 1:if(num9==0) num=0;
			else num=rand()%num9;
			printf("%d-%d=",num9,num);break;
		}
	}
	else if(c==5.5)
	{
		numscreat();
		cout<<'=';
	}
}


void opreat()
{
    cout<<"************************************************��ӭʹ��Сѧ��ϰ��ϵͳ************************************************"<<endl; 
	cout<<"ѧ��������student"<<endl<<"��ʦ������teacher"<<endl; 
}


void denglu(char s[]) {
    char mima[10];
    printf("���������룺"); 
    scanf("%s",mima);
    Student *p = head;
    int flag = 0;
    while(p!=NULL) {
        if(strcmp(p->id,s) == 0) {
        	flag=1;
        	if(strcmp(p->mima,mima)==0)
        	{
        		temp=1;
            printf("ѧ���˺ţ�%s\n", p->id);
            printf("ѧ��������%s\n", p->name);
            printf("ѧ��������%s\n", p->score);
            printf("ѧ���꼶: %s\n", p->classes);
            flag = 2;
            break;
            }
            break;
        }
        else {
            p = p->next;
        }
    }
    if(flag == 0) 
        printf("δ�ҵ���ѧ����Ϣ��\n");
    else if(flag==1)
        printf("�������\n");
}


void zhuce() {
    Student *p = (struct student*)malloc(sizeof(struct student));
    printf("������ѧ���˺ţ�");
    scanf("%s", p->id);
    printf("������ѧ��������");
    scanf("%s", p->name);
    printf("������ѧ�����룺");
    scanf("%s",p->mima);
    printf("������ѧ������: ");
	scanf("%s",p->score);
	printf("������ѧ���꼶��");
	scanf("%s",p->classes);
    p->next = NULL;
    if(head == NULL) {
        head = p;
    }
    else {
        Student *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
    printf("ѧ����Ϣע��ɹ���\n");

    // ��ѧ����Ϣд���ļ�
    FILE *fp;
    fp = fopen("students.txt", "a");   // ���ļ���׷��ģʽ��
    if(fp == NULL) {
        printf("�ļ���ʧ�ܣ�\n");
        return;
    }
    fprintf(fp, "%s %s %s %s %s\n", p->id,p->name, p->mima,p->score,p->classes);    // д���ļ�
    fclose(fp); // �ر��ļ�
}


void shanchu() {
    char id[10];
    printf("������ѧ���˺ţ�");
    scanf("%s", id);
    Student *p = head;
    Student *pre = NULL;
    int flag = 0;
    while(p != NULL) {
        if(strcmp(p->id, id) == 0) {
            if(pre == NULL) {   // Ҫɾ���Ľڵ�Ϊͷ�ڵ�
                head = p->next;
            }
            else {  // Ҫɾ���Ľڵ㲻Ϊͷ�ڵ�
                pre->next = p->next;
            }
            flag = 1;
            printf("��ɾ����ѧ����Ϣ��\n");
            cout<<endl; 
            free(p);
            break;
        }
        else {
            pre = p;
            p = p->next;
        }
    }
    if(flag == 0) {
        printf("δ�ҵ���ѧ����Ϣ��\n");
    }

    // ���ļ���ɾ����ѧ����Ϣ
    FILE *fp1, *fp2; // fp1Ϊԭ�ļ�ָ�룬fp2Ϊ�����ļ�ָ��
    fp1 = fopen("students.txt", "r");  // ���ļ���ֻ��ģʽ��
    fp2 = fopen("temp.txt", "w");      // �򿪸����ļ���д��ģʽ��
    char line[30];
    while(fgets(line, 30, fp1) != NULL) {
        // ÿ����һ�У��鿴�Ƿ�ΪҪɾ����ѧ����Ϣ��������д�븱���ļ�
        if(strncmp(line, id, strlen(id)) != 0) {
            fputs(line, fp2);
        }
    }
    fclose(fp1);    // �ر�ԭ�ļ�
    fclose(fp2);    // �رո����ļ�
    remove("students.txt"); // ɾ��ԭ�ļ�
    rename("temp.txt", "students.txt"); // �����������ļ����滻ԭ�ļ�
}


void xiugaic(char s[],int count) {
    Student *p = head;
    char str[10];
    int flag = 0;
    while(p != NULL) {
        if(strcmp(p->id, s) == 0) {
            int n=atoi(p->score)+count;
            sprintf(str,"%d",n);
            strcpy(p->score,str);
            break;
        }
        else
        p = p->next;
    }
    // �޸��ļ��и�ѧ����Ϣ
    FILE *fp1, *fp2; // fp1Ϊԭ�ļ�ָ�룬fp2Ϊ�����ļ�ָ��
    fp1 = fopen("students.txt", "r");  // ���ļ���ֻ��ģʽ��
    fp2 = fopen("temp.txt", "w");      // �򿪸����ļ���д��ģʽ��
    char line[30];
    while(fgets(line, 30, fp1) != NULL) {
        // ÿ����һ�У��鿴�Ƿ�ΪҪ�޸ĵ�ѧ����Ϣ������д�븱���ļ������滻��Ϣ
        if(strncmp(line, s, strlen(s)) == 0) {
            fprintf(fp2, "%s %s %s %s %s\n", p->id, p->name,p->mima,p->score,p->classes);
        }
        else {
            fputs(line, fp2);
        }
    }
    fclose(fp1);    // �ر�ԭ�ļ�
    fclose(fp2);    // �رո����ļ�
    remove("students.txt"); // ɾ��ԭ�ļ�
    rename("temp.txt", "students.txt"); // �����������ļ����滻ԭ�ļ�
}


void loadStudents() {
    FILE *fp;
    fp = fopen("students.txt", "r");
    if(fp == NULL) {
        printf("�ļ���ʧ�ܣ�\n");
        return;
    }
    char id[10];
    char name[20];
    char mima[20];
    char score[10];
    char classes[10];
    while(fscanf(fp, "%s %s %s %s %s", id, name,mima,score,classes) != EOF) {
        Student *p = (struct student*)malloc(sizeof(struct student));
        strcpy(p->id, id);
        strcpy(p->name, name);
        strcpy(p->mima,mima);
        strcpy(p->score,score);
        strcpy(p->classes,classes);
        p->next = NULL;
        if(head == NULL) {
            head = p;
        }
        else {
            Student *temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = p;
        }
    }
    fclose(fp);
}


void fengzhuang(char s[])
{
	Student *p=head;
	while(p!=NULL)
	{
		if(strcmp(p->id,s)==0)
		{
			ct=atof(p->classes);
			break;
		}
		p=p->next;
	}
	srand(time(0));
	int answer;
	int count=M*N;
	
    if(ct==4.5)
    {
    	mathcreat(ct);
    	cout<<"��ɴ���"<<endl;
    	cout<<endl;
    	xiugaic(s,count);
	}
	else if(ct==6)
	{
		cout<<0<<endl;
		for(int i=1;i<=M;i++)
	{
	    for(int j=1;j<=N;j++)
	    {
	    	int answer;
	        titlecreat();//����÷�װ������
	        cin>>answer;
	    }
	    cout<<endl;
	}
	cout<<"��ɴ���"<<endl;
	cout<<endl;
	xiugaic(s,count);
	}
    else
    {
    	for(int i=1;i<=M;i++)
    	{
    		for(int j=1;j<=N;j++)
    		{
    			mathcreat(ct);
    			cin>>answer;
    			if(answer==an) cout<<"����ȷ" <<endl;
    			else cout<<"�𰸴���"<<endl;
			}
			cout<<endl;
		}
		cout<<"��ɴ���"<<endl;
		cout<<endl;
		xiugaic(s,count);
	}
}


void chaxun(char s[]) 
{
	Student *p=head;
	char str[10];
	while(p!=NULL)
	{
		if(strcmp(p->id,s)==0)
		{
		strcpy(str,p->classes);
		break; 
	    }
	    p=p->next;
	}
	Student *t=head;
	while(t!=NULL)
	{
		if(strcmp(t->classes,str)==0)
		{
		printf("%s\t",t->name);
		printf("%s\t",t->score);
		cout<<endl;
	    }
	    t=t->next;
   }
}


// �޸ĺ���
void xiugaix(char s[]) {
    char id[10];
    printf("������ѧ���˺ţ�");
    scanf("%s", id);
    Student *p = head;
    int flag = 0;
    while(p != NULL) {
        if(strcmp(p->id, id) == 0) {
            printf("�������޸ĺ��ѧ��������");
            scanf("%s", p->name);
            printf("�������޸ĺ��ѧ�����룺");
            scanf("%s", p->mima);
            printf("�������޸ĺ��ѧ���༶��");
            scanf("%s",p->classes);
            flag = 1;
            printf("�޸ĳɹ���\n");
            break;
        }
        else {
            p = p->next;
        }
    }
    if(flag == 0) {
        printf("δ�ҵ���ѧ����Ϣ��\n");
    }

    // �޸��ļ��и�ѧ����Ϣ
    FILE *fp1, *fp2; // fp1Ϊԭ�ļ�ָ�룬fp2Ϊ�����ļ�ָ��
    fp1 = fopen("students.txt", "r");  // ���ļ���ֻ��ģʽ��
    fp2 = fopen("temp.txt", "w");      // �򿪸����ļ���д��ģʽ��
    char line[30];
    while(fgets(line, 30, fp1) != NULL) {
        // ÿ����һ�У��鿴�Ƿ�ΪҪ�޸ĵ�ѧ����Ϣ������д�븱���ļ������滻��Ϣ
        if(strncmp(line, s, strlen(s)) == 0) {
            fprintf(fp2, "%s %s %s %s %s\n", p->id, p->name,p->mima,p->score,p->classes);
        }
        else {
            fputs(line, fp2);
        }
    }
    fclose(fp1);    // �ر�ԭ�ļ�
    fclose(fp2);    // �رո����ļ�
    remove("students.txt"); // ɾ��ԭ�ļ�
    rename("temp.txt", "students.txt"); // �����������ļ����滻ԭ�ļ�
}


void liulanp() {
	int flag=0;
    char id[10];
    char name[10];
    printf("���˺���������0����������������1");
	int n; 
    printf("�����룺"); 
    scanf("%d",&n);
    if(n==0)
    {
    	printf("����Ҫ��ѯ���˺�:");
		scanf("%s",id);
    	Student *p = head;
    while(p!=NULL) {
        if(strcmp(p->id,id) == 0) {
        	flag=1;
            printf("ѧ���˺ţ�%s\n", p->id);
            printf("ѧ��������%s\n", p->name);
            printf("ѧ��������%s\n", p->score);
            printf("ѧ���꼶: %s\n", p->classes);
            break;
        }
        else {
            p = p->next;
        }
    }
	}
	if(n==1)
	{
		printf("������Ҫ��ѯ��������");
		scanf("%s",name);
		Student *t=head;
		while(t!=NULL){
			if(strcmp(t->name,name)==0)
			{
			    flag=1;
			    printf("ѧ���˺ţ�%s\n", t->id);
                printf("ѧ��������%s\n", t->name);
                printf("ѧ��������%s\n", t->score);
                printf("ѧ���꼶: %s\n", t->classes);
                break;
			}
			else{
				t=t->next;
			}
		}
	}
    
    if(flag == 0) 
        printf("δ�ҵ���ѧ����Ϣ��\n");
        cout<<endl;
}


void liulana()
{
	double n;
	cout<<"������Ҫ�鿴���꼶:"<<endl;
	scanf("%lf",&n);
	char str[10];
	sprintf(str,"%.1f",n);
	Student *p=head;
	while(p!=NULL)
	{
		if(strcmp(p->classes,str)==0)
		{
			printf("ѧ���˺�:%s\t",p->id);
			printf("ѧ������:%s\t",p->name);
			printf("ѧ������:%s\t",p->score);
			cout<<endl;
		}
		p=p->next;
	}
	cout<<endl;
}



