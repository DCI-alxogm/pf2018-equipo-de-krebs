//
//  proyecto.c
//  
//
//  Created by Saul Sierra Luna on 11/28/18.
//

#include "random.h"
#define RAND_MAX        0x7fffffff
 int main ()
{
    FILE *fp;
    fp=fopen("random.txt","w");
    int x;
    float fr,ar,tr;
    
    srand((unsigned)time(NULL));
    for(x=0;x<100;x++)
    {
        fr = (float)rand()/RAND_MAX;
        ar=(float)rand()/RAND_MAX;
        tr=(float)rand()/RAND_MAX;
        fr*=100;
        ar*=100;
        tr*=100;
        fprintf(fp,"%f\t",fr);
        fprintf(fp,"%f\t",ar);
        fprintf(fp,"%f\n",tr);
    }
    
    fclose(fp);
    
   
    
    
    return 0;
}
