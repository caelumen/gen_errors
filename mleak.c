#include <stdio.h>
#include <memory.h>
#include <time.h>


#define MAX_LOOP 10000
#define MSIZE 1024

void main(int argc, char* argv[])
{
    int i=0;
    int n=MAX_LOOP;
    int nSize = MSIZE;
    char* s=NULL;
    int iLeak=0;
    //printf("argc : %d, argv[1]:%s, 2:%s 3:%s ", argc, argv[1], argv[2], argv[3]);
    if(argc>1) {
        n=(int)atoi(argv[1]);
        if(argc>2) nSize = (int)atoi(argv[2]);
        if(argc>3) { iLeak=(int)atoi(argv[3]);}
    }
    printf("=>> Start with n:%d, M:%d, leak:%d <<=\n", n, nSize, iLeak);

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char str_logfile[1024] = {0,};
    sprintf(str_logfile,"memory_leak_%d-%d-%d.log", tm->tm_mday, tm->tm_hour, tm->tm_min);
    printf("==>file:%s\n",str_logfile);
    FILE* fp= fopen(str_logfile,"w");
    for(i=0;i<n; i++){
        int mBlock = 10;
        s = (char*) malloc(sizeof(char) * nSize* mBlock);  // basic unit : KB
        memset(s,1, nSize * mBlock);
        // memset(s,0, 1024);
        sprintf(s,"%06d: TEST String...\n",i);
        fputs(s,fp);
        if(iLeak==0) free(s);  // memory leak. 
        fputs("Memory free!\n",fp);
    }
    fclose(fp);

}
