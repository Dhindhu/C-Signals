#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

unsigned int time;

void signal_alarm(int signum) {
  time++;
  alarm(1);
}

void signal_int(int signum) {
  printf("\n%d alarm(s) occurred i.e the program ran for approximately %d seconds\n", time, time);
  exit(1);
}

int main() {
  time = 0;
  signal(SIGALRM, signal_alarm);
  signal(SIGINT, signal_int);
  alarm(1);
  while(1);
}