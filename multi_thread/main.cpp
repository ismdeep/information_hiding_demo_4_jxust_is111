#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>


int num = 0;

void add ()
{
	for (int i = 0; i < 500; i++)
	{
		num += 1;
		printf ("add + 1, result is : %d\n", num);
	}
}

void sub ()
{
	for (int i = 0; i < 500; i++)
	{
		num -= 1;
		printf ("sub - 1, result is : %d\n", num);
	}
}


int main ()
{
	pthread_t tid1, tid2;
	int err;
	void *tret;
	err = pthread_create (&tid1, NULL, &add, NULL);
	err = pthread_create (&tid2, NULL, &sub, NULL);
	pthread_join (tid1, &tret);
	pthread_join (tid2, &tret);
	return 0;
}



