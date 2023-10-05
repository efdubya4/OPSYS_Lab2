#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int handler_called = 0; // Global variable to track whether the handler was called

void handler(int signum)
{
  printf("Hello World!\n");
  handler_called = 1; // Set the flag to indicate handler was called
  alarm(1); // Schedule the next alarm
}

int main(int argc, char * argv[])
{
  signal(SIGALRM, handler);
  alarm(1);

  while (1) {
    while (!handler_called) {
      // Wait for the handler to be called
    }
    printf("Turing was right!\n");
    handler_called = 0; // Reset the flag
  }

  return 0;
}
