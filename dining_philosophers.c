/*
 * dining_philosophers.c
 * 간단한 "식사하는 철학자" 문제 구현 (pthread 사용)
 * 해결 전략: 짝수 철학자는 왼쪽 포크 먼저, 홀수 철학자는 오른쪽 포크 먼저 집어 교착 상태(deadlock)를 방지
 * 각 철학자는 MAX_MEALS 만큼 먹고 종료
 * 컴파일: gcc -pthread -o dining_philosophers dining_philosophers.c
 * 실행: ./dining_philosophers
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <pthread.h>
 #include <unistd.h>
 #include <time.h>
 #include <stdarg.h>
 
 #define N_PHIL 5
 #define MAX_MEALS 3
 
 pthread_mutex_t forks[N_PHIL];
 pthread_mutex_t print_lock;
 
 void ms_sleep(int ms) {
     usleep(ms * 1000);
 }
 
 void safe_printf(const char *fmt, ...) {
     va_list ap;
     va_start(ap, fmt);
     pthread_mutex_lock(&print_lock);
     vprintf(fmt, ap);
     fflush(stdout);
     pthread_mutex_unlock(&print_lock);
     va_end(ap);
 }
 
 void *philosopher(void *arg) {
     int id = *((int*)arg);
     int left = id;                
     int right = (id + 1) % N_PHIL; 
     int meals = 0;
     unsigned int seed = time(NULL) ^ (id * 0x9e3779b9);
 
     while (meals < MAX_MEALS) {
         safe_printf("철학자 %d: (생각 중...)\n", id);
         ms_sleep(100 + (rand_r(&seed) % 400));
 
         safe_printf("철학자 %d: 포크를 집으려고 함 (왼=%d, 우=%d)\n", id, left, right);
         if (id % 2 == 0) {
             pthread_mutex_lock(&forks[left]);
             safe_printf("철학자 %d: 왼쪽 포크(%d) 획득\n", id, left);
             pthread_mutex_lock(&forks[right]);
             safe_printf("철학자 %d: 오른쪽 포크(%d) 획득\n", id, right);
         } else {
             pthread_mutex_lock(&forks[right]);
             safe_printf("철학자 %d: 오른쪽 포크(%d) 획득\n", id, right);
             pthread_mutex_lock(&forks[left]);
             safe_printf("철학자 %d: 왼쪽 포크(%d) 획득\n", id, left);
         }
         safe_printf("철학자 %d: (식사 시작) #%d\n", id, meals + 1);
         ms_sleep(100 + (rand_r(&seed) % 300));
         meals++;
         safe_printf("철학자 %d: (식사 끝) 지금까지 먹은 횟수=%d\n", id, meals);
         pthread_mutex_unlock(&forks[left]);
         pthread_mutex_unlock(&forks[right]);
         safe_printf("철학자 %d: 포크(%d, %d) 반납\n", id, left, right);
         ms_sleep(50 + (rand_r(&seed) % 150));
     }
 
     safe_printf("철학자 %d: 배부르다... 이제 그만\n", id);
     free(arg);
     return NULL;
 }
 
 int main(void) {
     pthread_t threads[N_PHIL];
     pthread_mutex_init(&print_lock, NULL);
     for (int i = 0; i < N_PHIL; ++i) pthread_mutex_init(&forks[i], NULL);
     for (int i = 0; i < N_PHIL; ++i) {
         int *id = malloc(sizeof(int));
         if (!id) {
             perror("malloc");
             exit(EXIT_FAILURE);
         }
         *id = i;
         if (pthread_create(&threads[i], NULL, philosopher, id) != 0) {
             perror("pthread_create");
             exit(EXIT_FAILURE);
         }
     }
     for (int i = 0; i < N_PHIL; ++i) pthread_join(threads[i], NULL);
     for (int i = 0; i < N_PHIL; ++i) pthread_mutex_destroy(&forks[i]);
     pthread_mutex_destroy(&print_lock);
 
     printf("모두 식사 완료. 프로그램 종료.\n");
     return 0;
 }
 