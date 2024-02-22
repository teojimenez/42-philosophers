#include "philo/includes/philo.h"

int cont = 0;
pthread_mutex_t lock;

void  *routine()
{
  int i;

  i = -1;
  while (++i < 1000000)
  {
    pthread_mutex_lock(&lock);
  	  cont++;
    pthread_mutex_unlock(&lock);
  }
  return (NULL);
}

u_int64_t	init_time()
{
	struct timeval	tv;
	if (gettimeofday(&tv, NULL) == -1)
	{
		write(2, "ERROR!", 7);
		return (0);
	}
	// printf("Seconds since epoch: %li\n", tv.tv_sec);
  //   printf("Microseconds: %u\n", tv.tv_usec);
	// printf("%li", (tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int main()
{
  pthread_t tid1, tid2;

  pthread_mutex_init(&lock, NULL);
  pthread_create(&tid1, NULL, &routine, NULL);
  pthread_create(&tid2, NULL, &routine, NULL);

  // pthread_detach(tid1);
  // pthread_detach(tid2);
  printf("BEFORE-> %llu\n", init_time());
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_mutex_destroy(&lock);
  printf("cont: %d\n", cont);
  printf("AFTER->  %llu\n", init_time());
}
