#include <bits/stdc++.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


typedef struct student {
    char id[10];    // 学生ID
    char name[20];  // 学生姓名
    char mima[10]; //密码 
    char score[10]; // 学生分数 
    char classes[10];//学生年级 
    struct student *next;
}Student;

Student *head=NULL;// 定义链表头指针


void mathcreat(double c);//生成单个运算 
void opreat(); 
void title(char s1,char s2,int t1,int t2,int t3,int t4);//递归函数
 void titlecreat();//递归生成题目 
void zhuce();//学生注册 
void denglu(char s[]);//学生登录 
void shanchu();//删除学生
void loadStudents();//加载学生信息 
void chaxun(char []);//单人查询 
void xiugaic(char s[],int count);//修改分数
void xiugaix(char s[]);//修改信息 
void liulanp();//浏览学生信息 
void liulana();//按年级查询 
void fengzhuang(char s[]);//封装出题函数 


int M,N;//页数，题目数 
int an;//输入的答案 
int temp=0;
double ct;//年级 
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
	if(str1==id)//学生板块 
	{
    cout<<"有关用户信息输入"<<endl;
	cout<<"登录输入1，注册输入2"<<endl;
	int cho;
	cin>>cho;
	
		if(cho==1)//登录 
		{
		char s[10];
		printf("请输入账号:");
		scanf("%s",s);
		denglu(s);
	    int xz;
	    
		if(temp==1)
		{
			while(1)
	        {
			cout<<"生成题目输入1,查询成绩输入2，修改信息输入3,输入4退出"<<endl;
			cin>>xz;
		        if(xz==1) 
		        {
			        printf("请输入题目页数\n");
	                cin>>M;
	                printf("请输入每页题目数\n");
	                cin>>N;
	                int count=M*N;
	                fengzhuang(s);
                }
            
                else if(xz==2)//查询全班成绩 
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
		else if(cho==2)//注册 
		zhuce();
	}
	
    else if(id==str2)
    {
    	int n;
    	while(1)
    	{
    		printf("录入学生信息输入1\n");
    		printf("删除学生信息输入2\n");
    		printf("浏览学生信息输入3\n");
    		printf("以年级为单位浏览学生信息输入4\n");
    		printf("输入5退出\n");
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
	else cout<<"输入错误，请重启"; 
	return 0;
}
////主函数 





void titlecreat() 
{
	char a;
	int z,t;
	z=1+rand()%3;//决定生成几个括号 
	t=rand()%2;//决定首先是否生成括号 
	if(t==1) title('(',a,z,z,0,0);
	else if(t==0) title(a,a,z,z,1,0);//z是括号个数 
	cout<<'=';
} 


int numcreat()//生成数字
{
    return 1+rand()%100;
}


char pcreat()//生成运算符
{
	int t;
	t=rand()%4;
	if(t==0) return '+';
	if(t==1) return '-';
	if(t==2) return '*';
	if(t==3) return '/';
}


void numscreat()//生成单个运算
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


void title(char s1,char s2,int t1,int t2,int t3,int t4) //t3,t4是现存左右括号 
{
    int m;
    m=0;
	int num;
	char s;
	int ta=rand()%2;//[0,1] 
    int tb=rand()%2;//随机 
    int tc=rand()%2;
    int td=rand()%2;
	char a;
	if(s1=='('&&t1>0)//如果s1==(,输出(,t1--。进入下一个函数 
	{
		p++;
		cout<<'(';
		t1--;
		title(a,a,t1,t2,1,0);
	}
	else if(s1==a)//s1不为(有两种情况. 
	{
		if(t3==1)//t3==1
		{
			numscreat();//生成一对运算 
			if(tb==1&&p>0)//决定 是否生成右括号 
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
		    if(tc==0&&t1>0&&m==0) title('(',a,t1,t2,0,0);//决定是否生成左括号 
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
			if(td==0&&t1>0&&m==0) title('(',a,t1,t2,0,0);//决定是否生成左括号 
		    else title(a,a,t1,t2,1,0);
		}
	}
}


void mathcreat(double c) 
{
	int v=0;
	int t1=rand()%2;//+,-或*,/ 
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
			else num=rand()%num1;//防止减法出现负数 
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
    cout<<"************************************************欢迎使用小学生习题系统************************************************"<<endl; 
	cout<<"学生请输入student"<<endl<<"老师请输入teacher"<<endl; 
}


void denglu(char s[]) {
    char mima[10];
    printf("请输入密码："); 
    scanf("%s",mima);
    Student *p = head;
    int flag = 0;
    while(p!=NULL) {
        if(strcmp(p->id,s) == 0) {
        	flag=1;
        	if(strcmp(p->mima,mima)==0)
        	{
        		temp=1;
            printf("学生账号：%s\n", p->id);
            printf("学生姓名：%s\n", p->name);
            printf("学生分数：%s\n", p->score);
            printf("学生年级: %s\n", p->classes);
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
        printf("未找到该学生信息！\n");
    else if(flag==1)
        printf("密码错误。\n");
}


void zhuce() {
    Student *p = (struct student*)malloc(sizeof(struct student));
    printf("请输入学生账号：");
    scanf("%s", p->id);
    printf("请输入学生姓名：");
    scanf("%s", p->name);
    printf("请输入学生密码：");
    scanf("%s",p->mima);
    printf("请输入学生分数: ");
	scanf("%s",p->score);
	printf("请输入学生年级：");
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
    printf("学生信息注册成功！\n");

    // 将学生信息写入文件
    FILE *fp;
    fp = fopen("students.txt", "a");   // 打开文件（追加模式）
    if(fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    fprintf(fp, "%s %s %s %s %s\n", p->id,p->name, p->mima,p->score,p->classes);    // 写入文件
    fclose(fp); // 关闭文件
}


void shanchu() {
    char id[10];
    printf("请输入学生账号：");
    scanf("%s", id);
    Student *p = head;
    Student *pre = NULL;
    int flag = 0;
    while(p != NULL) {
        if(strcmp(p->id, id) == 0) {
            if(pre == NULL) {   // 要删除的节点为头节点
                head = p->next;
            }
            else {  // 要删除的节点不为头节点
                pre->next = p->next;
            }
            flag = 1;
            printf("已删除该学生信息！\n");
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
        printf("未找到该学生信息！\n");
    }

    // 从文件中删除该学生信息
    FILE *fp1, *fp2; // fp1为原文件指针，fp2为副本文件指针
    fp1 = fopen("students.txt", "r");  // 打开文件（只读模式）
    fp2 = fopen("temp.txt", "w");      // 打开副本文件（写入模式）
    char line[30];
    while(fgets(line, 30, fp1) != NULL) {
        // 每读入一行，查看是否为要删除的学生信息，不是则写入副本文件
        if(strncmp(line, id, strlen(id)) != 0) {
            fputs(line, fp2);
        }
    }
    fclose(fp1);    // 关闭原文件
    fclose(fp2);    // 关闭副本文件
    remove("students.txt"); // 删除原文件
    rename("temp.txt", "students.txt"); // 重命名副本文件，替换原文件
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
    // 修改文件中该学生信息
    FILE *fp1, *fp2; // fp1为原文件指针，fp2为副本文件指针
    fp1 = fopen("students.txt", "r");  // 打开文件（只读模式）
    fp2 = fopen("temp.txt", "w");      // 打开副本文件（写入模式）
    char line[30];
    while(fgets(line, 30, fp1) != NULL) {
        // 每读入一行，查看是否为要修改的学生信息，是则写入副本文件，并替换信息
        if(strncmp(line, s, strlen(s)) == 0) {
            fprintf(fp2, "%s %s %s %s %s\n", p->id, p->name,p->mima,p->score,p->classes);
        }
        else {
            fputs(line, fp2);
        }
    }
    fclose(fp1);    // 关闭原文件
    fclose(fp2);    // 关闭副本文件
    remove("students.txt"); // 删除原文件
    rename("temp.txt", "students.txt"); // 重命名副本文件，替换原文件
}


void loadStudents() {
    FILE *fp;
    fp = fopen("students.txt", "r");
    if(fp == NULL) {
        printf("文件打开失败！\n");
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
    	cout<<"完成答题"<<endl;
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
	        titlecreat();//这里该封装函数了
	        cin>>answer;
	    }
	    cout<<endl;
	}
	cout<<"完成答题"<<endl;
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
    			if(answer==an) cout<<"答案正确" <<endl;
    			else cout<<"答案错误"<<endl;
			}
			cout<<endl;
		}
		cout<<"完成答题"<<endl;
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


// 修改函数
void xiugaix(char s[]) {
    char id[10];
    printf("请输入学生账号：");
    scanf("%s", id);
    Student *p = head;
    int flag = 0;
    while(p != NULL) {
        if(strcmp(p->id, id) == 0) {
            printf("请输入修改后的学生姓名：");
            scanf("%s", p->name);
            printf("请输入修改后的学生密码：");
            scanf("%s", p->mima);
            printf("请输入修改后的学生班级：");
            scanf("%s",p->classes);
            flag = 1;
            printf("修改成功！\n");
            break;
        }
        else {
            p = p->next;
        }
    }
    if(flag == 0) {
        printf("未找到该学生信息！\n");
    }

    // 修改文件中该学生信息
    FILE *fp1, *fp2; // fp1为原文件指针，fp2为副本文件指针
    fp1 = fopen("students.txt", "r");  // 打开文件（只读模式）
    fp2 = fopen("temp.txt", "w");      // 打开副本文件（写入模式）
    char line[30];
    while(fgets(line, 30, fp1) != NULL) {
        // 每读入一行，查看是否为要修改的学生信息，是则写入副本文件，并替换信息
        if(strncmp(line, s, strlen(s)) == 0) {
            fprintf(fp2, "%s %s %s %s %s\n", p->id, p->name,p->mima,p->score,p->classes);
        }
        else {
            fputs(line, fp2);
        }
    }
    fclose(fp1);    // 关闭原文件
    fclose(fp2);    // 关闭副本文件
    remove("students.txt"); // 删除原文件
    rename("temp.txt", "students.txt"); // 重命名副本文件，替换原文件
}


void liulanp() {
	int flag=0;
    char id[10];
    char name[10];
    printf("按账号搜索输入0，按姓名搜索输入1");
	int n; 
    printf("请输入："); 
    scanf("%d",&n);
    if(n==0)
    {
    	printf("输入要查询的账号:");
		scanf("%s",id);
    	Student *p = head;
    while(p!=NULL) {
        if(strcmp(p->id,id) == 0) {
        	flag=1;
            printf("学生账号：%s\n", p->id);
            printf("学生姓名：%s\n", p->name);
            printf("学生分数：%s\n", p->score);
            printf("学生年级: %s\n", p->classes);
            break;
        }
        else {
            p = p->next;
        }
    }
	}
	if(n==1)
	{
		printf("请输入要查询的姓名：");
		scanf("%s",name);
		Student *t=head;
		while(t!=NULL){
			if(strcmp(t->name,name)==0)
			{
			    flag=1;
			    printf("学生账号：%s\n", t->id);
                printf("学生姓名：%s\n", t->name);
                printf("学生分数：%s\n", t->score);
                printf("学生年级: %s\n", t->classes);
                break;
			}
			else{
				t=t->next;
			}
		}
	}
    
    if(flag == 0) 
        printf("未找到该学生信息！\n");
        cout<<endl;
}


void liulana()
{
	double n;
	cout<<"输入你要查看的年级:"<<endl;
	scanf("%lf",&n);
	char str[10];
	sprintf(str,"%.1f",n);
	Student *p=head;
	while(p!=NULL)
	{
		if(strcmp(p->classes,str)==0)
		{
			printf("学生账号:%s\t",p->id);
			printf("学生姓名:%s\t",p->name);
			printf("学生分数:%s\t",p->score);
			cout<<endl;
		}
		p=p->next;
	}
	cout<<endl;
}



