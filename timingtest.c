#include "types.h"
#include "stat.h"
#include "user.h"  
void func() 
{  
   int * a =(int *)malloc(800000*sizeof(int)); 
   for(int i=0;i<200;++i) 
   { 
       for(int j=0;j<200;++j) 
       { 
           for(int k=0;k<20;++k) 
           a[i*j*k] = i*j*k;
       }
   }
}
int main() 
{ int ctime=-1,rtime=-1,retime=-1,stime=-1;
    
    for(int j=0;j<10;++j) 
    {
    int pid = fork(); 
    if(pid==0) 
    { func();  
    
    exit();

    } 
    }  
    
    for(int j=0;j<10;++j) 
    { int temp=0;
    temp = wait2(&ctime,&retime,&rtime,&stime); 
    printf(2,"pid:%d %d %d %d %d\n" ,temp, ctime,retime,rtime,stime); 
    
    } 

    exit();
    
}