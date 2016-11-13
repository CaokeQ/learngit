#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"
/*Begin:project2-006*/
#define MAX_ARGC 10
#define MAX_CMD_LENGTH (1 << 12) /*4k*/
typedef int pid_t;
#define PID_ERROR ((pid_t) -1)
#define BYTES_OF_PUSH 4
/*End:project2-006*/
tid_t process_execute (const char *file_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (void);

#endif /* userprog/process.h */
