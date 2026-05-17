#ifndef UCLITE_PROCESS_H
#define UCLITE_PROCESS_H

int fork(void);
int execve(const char *pathname, char *const argv[], char *const envp[]);
int waitpid(int pid, int *wstatus, int options);

#endif
