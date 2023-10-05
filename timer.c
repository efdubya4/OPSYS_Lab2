#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int handler_called = 0; // Global variable to track whether the handler was called
int alarm_count = 0; // Global variable to count alarms
time_t start_time; // Global variable to store start time

void handler(int signum)
{
  printf("Hello World!\n");
  handler_called = 1; // Set the flag to indicate handler was called
  alarm_count++;
  alarm(1); // Schedule the next alarm
}

void int_handler(int signum)
{
  time_t end_time;
  double execution_time;

  end_time = time(NULL);
  execution_time = difftime(end_time, start_time);

  printf("Total alarms received: %d\n", alarm_count);
  printf("Total execution time: %.2lf seconds\n", execution_time);
  exit(0);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM, handler);
  signal(SIGINT, int_handler); // Register the handler for SIGINT

  alarm(1);
  start_time = time(NULL);

  while (1) {
    while (!handler_called) {
      // Wait for the handler to be called
    }
    handler_called = 0; // Reset the flag
  }

  return 0;
}
