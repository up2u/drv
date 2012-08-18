// Deadlock necessary conditions:
// 1: Mutual exclusion 2: hold and wait or resource holding
// 3: No preemption    4: circular wait
// example from :
// www.ibm.com/developerworks/cn/linux/l-cn-deadlock/index.html?ca=drs-

// used tools : pstack + gdb

#include <unistd.h>
#include <pthread.h>
#include <string.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex4 = PTHREAD_MUTEX_INITIALIZER;

static int sequence1 = 0;
static int sequence2 = 0;

int fun1()
{
  pthread_mutex_lock(&mutex1);
  ++sequence1;
  sleep(1);
  pthread_mutex_lock(&mutex2);
  ++sequence2;
  pthread_mutex_unlock(&mutex2);
  pthread_mutex_unlock(&mutex1);

  return sequence1;
}

int fun2()
{
  pthread_mutex_lock(&mutex1);
  ++sequence1;
  sleep(1);
  pthread_mutex_lock(&mutex2);
  ++sequence2;
  pthread_mutex_unlock(&mutex2);
  pthread_mutex_unlock(&mutex1);

  return sequence2;
}

void *thread1(void *arg)
{
  while (1)
  {
    int ret = fun1();

    if (100000 == ret)
    {
      pthread_exit(NULL);
    }
  }
}

void *thread2(void *arg)
{
  while (1)
  {
    int ret = fun2();

    if (100000 == ret)
    {
      pthread_exit(NULL);
    }
  }
}

void *thread3(void *arg)
{
  while (1)
  {
    sleep(1);
    char buf[128];
    memset(buf, 0, sizeof(buf));
    strcpy(buf, "thread3");
  }
}

void *thread4(void *arg)
{
  while (1)
  {
    sleep(1);
    char buf[128];
    memset(buf, 0, sizeof(buf));
    strcpy(buf, "thread3");
  }
}

int main()
{
  pthread_t tid[4];

  if (0 != pthread_create(&tid[0], NULL, &thread1, NULL))
  {
    _exit(1);
  }
  if (0 != pthread_create(&tid[1], NULL, &thread2, NULL))
  {
    _exit(1);
  }
  if (0 != pthread_create(&tid[2], NULL, &thread3, NULL))
  {
    _exit(1);
  }
  if (0 != pthread_create(&tid[3], NULL, &thread4, NULL))
  {
    _exit(1);
  }

  sleep(5);
  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
  pthread_join(tid[2], NULL);
  pthread_join(tid[3], NULL);

  pthread_mutex_destroy(&mutex1);
  pthread_mutex_destroy(&mutex2);
  pthread_mutex_destroy(&mutex3);
  pthread_mutex_destroy(&mutex4);

  return 0;
}
