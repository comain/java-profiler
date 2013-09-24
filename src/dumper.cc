#include "globals.h"
#include "profiler.h"
#include "signal.h"
#include <unistd.h>

void _dumper_interface (jvmtiEnv* jvmti_env, JNIEnv* jni_env, void* arg)
{
    Profiler * p = (Profiler*) arg;
    if (p == NULL) {
        return;
    }

    /*disables SIGPROF in current thread*/
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGPROF);
    if (pthread_sigmask(SIG_BLOCK, &set, NULL) !=0) {
        fprintf(stderr, "sigmask_err");
        return;
    } 

    while (1) {
        sleep (kIntervalSeconds);
        p->DumpToFile(Globals::OutFile, jvmti_env);
    }
    return ;
}
