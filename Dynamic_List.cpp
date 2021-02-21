#include<stdio.h>
#include<stdlib.h>
#define Initsize 10               //初始的数组长度
typedef struct{                   //定义一个结构体（自己定义一个结构类型）
	int *data;
	int Maxsize;
	int Length;
}List_dynamic;   //结构类型的名字，就像int char string等

void Dynamic_InitList(List_dynamic &List){                 //初始化顺序表
	List.data=(int *)malloc(Initsize*sizeof(int));          //用malloc给顺序表的数组分配Initsize(初始化长度)所需要的内存空间
	List.Maxsize=Initsize;                                  //当前顺性表最大长度即为初始化Initsize的长度    
	List.Length=0;                                          //当前长度为0
}

void IncreaseSize(List_dynamic &List,int len){               //把顺序表最大长度变长
	int *p=List.data;                                        //定义*p指针指向顺序表的数组
	List.data=(int *)malloc((Initsize+len)*sizeof(int));     //重新在内存中开辟一块变长后的顺序表
	for(int i=0;i<List.Length;i++)                           //把之前的顺序表全都复制到刚刚创建好的顺序表在内存中的位置
		List.data[i]=p[i];   
	List.Maxsize=List.Maxsize+len;                          //顺序表的最大长度变长
	free(p);                                                //释放p指针指向的顺序表
}

bool InsertList(List_dynamic &List,int sum_Insert,int sum_position){    //插入顺序表元素的方法，返回布尔类型
	if(sum_position>List.Length+1||sum_position<1)                        //先判断要插入的位置是否有错误，不能大于数组当前长度+1（不排除要在顺序表后加一个元素），也不能小于1
		return false;                             
	if(sum_position>List.Maxsize)                                        //不能大于顺序表的当前储存空间
		return false;                                               
	for(int i=List.Length;i>=sum_position;i--)                          //把插入位置以及之后的元素全部后移以为，把要插入的位置腾出来
		List.data[i+1]=List.data[i];                                    
	List.data[sum_position-1]=sum_Insert;                               //把要插入的元素放在要插入的位置
	List.Length++;                                                      //顺序表长度加1
		return true;
}
bool ListDelete(List_dynamic &List,int sum_position){               //删除顺序表中的元素
	if(sum_position>List.Length+1||sum_position<1)
		return false; 
	for(int i=sum_position;i<=List.Length;i--)  
		List.data[i]=List.data[i+1]; 
	List.Length--;
	return true;
}

int GetElem(List_dynamic List,int getelem){ //以下标的方式查找元素
	return List.data[getelem-1];
}

int GetElemsign(List_dynamic List,int getelem){
	for(int i=0;i<=List.Length;i++){
		if(List.data[i]==getelem)
			return i+1;
	}
	return 0;
}
int main()              //动态主函数
{
	List_dynamic List;
	
	Dynamic_InitList(List);       //初始化顺序表
    int len;                      //要增加的数组长度
	//IncreaseSize(List,len);       //给顺序表增加长度
	int sum_Insert=1,sum_position=1;  //要插入的数和要插入的位置
	InsertList(List,sum_Insert,sum_position);   //给顺序表插入元素
	/*int sum_Delete;                   //要删除的元素位置
	ListDelete(List,sum_Delete);     //删除指定数据元素*/
	int getelem=9;
	//GetElem(List,getelem);          //以下标的方式查找元素
	printf("%d",GetElemsign(List,getelem));  //以元素的方式查找元素，返回下标值
	system("pause");
	return 0;
}
