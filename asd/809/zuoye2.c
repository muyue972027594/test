/************************************************
文件名：zuoye2.c
功  能：创建队列  并实现  多个“生产”一个“消费”
版本号：0.0.1
*************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

typedef struct data
{
	int num;
	struct data *next;
} DATA;


int i = 0;

sem_t sem_wr,sem_rd,sem_lock;


int mypush(DATA *head,int num)
{
	DATA *p1,*p2;

	p1 = p2 = head;

	p2 = (DATA *)malloc(sizeof(DATA));
	p2->num = num;
	p2->next = NULL;

	while(p1->next != NULL)
	{
		p1 = p1->next;
	} 

	p1->next = p2;
}


int mypop(DATA *head)
{
	DATA *p1;

	p1 = head->next;

	if(p1 != NULL)	
	{
		head->next = p1->next;
		return p1->num;
		free(p1);
	}
}


int isfull(DATA *head)
{
	int count = 0;
	DATA *p1;
	
	p1 = head->next;
	while(p1 != NULL)
	{
		count++;
		p1 = p1->next;
	}

	if(count >= 5)
		return 1;
	else 
		return 0;
}


int isempty(DATA *head)
{
	DATA *p1;

	p1 = head->next;
	if(p1 != NULL)
		return 0;
	else
		return 1;
}


void *myread(void *arg)
{

    while(1)
    {
        sem_wait(&sem_rd);

//		sem_wait(&sem_lock);
        printf("输出 %d\n",mypop((DATA *)arg));
//		sem_post(&sem_lock);

        sem_post(&sem_wr);
	
		if(i >= 50 && isempty((DATA *)arg)) break;
    }

    pthread_exit(NULL);

}


void *mywrite(void *arg)
{
    while(i < 50)
    {
        sem_wait(&sem_wr);

//		sem_wait(&sem_lock);
		i++;
		mypush((DATA *)arg,i);
//		sem_post(&sem_lock);
        
        sem_post(&sem_rd);
    }

    pthread_exit(NULL);
}


int main()
{
    pthread_t thread[2] = {0};
	DATA * myhead = NULL;
    int ret = 0;
	myhead = (DATA *)malloc(sizeof(DATA));
	myhead->next = NULL;

    sem_init(&sem_rd,0,0);
    sem_init(&sem_wr,0,5);
	sem_init(&sem_lock,0,1);

    ret = pthread_create(&thread[0],NULL,myread,myhead);
    if(ret != 0)
    {
        printf("create myread error!\n");
        exit(-1);
    }


    ret = pthread_create(&thread[1],NULL,mywrite,myhead);
    if(ret != 0)
    {
        printf("create myread error!\n");
        exit(-1);
    }


    pthread_join(thread[0],NULL);
    pthread_join(thread[1],NULL);

	free(myhead);

    return 0;
}





