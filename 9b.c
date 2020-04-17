# include <stdio.h>
# include <pthread.h>
int global[2];

void *mult_thread(void *arg)
{
    int *args_array;
    args_array = arg;

    int n1,n2,mult;
    n1=args_array[0];
    n2=args_array[1];
    mult = n1*n2;

    printf("N1 * N2 = %d\n",mult);

    return NULL;
}

int main() 
{
    printf("First number: ");
    scanf("%d",&global[0]);

    printf("Second number: ");
    scanf("%d",&global[1]);

    pthread_t tid_mult;
pthread_create(&tid_mult,NULL,mult_thread,global);
    pthread_join(tid_mult,NULL);

    return 0;
}
