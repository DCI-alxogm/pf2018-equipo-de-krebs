//
//  proyecto.c
//  
//
//  Created by Saul Sierra Luna on 11/28/18.
//

#include "random.h"
 int main ()
{
    FILE *fp;
    fp=fopen("random.txt","w");
    int x[10],i,y[10],z[10];
   
    for (i=0; i<10; i++)
        
    {
        x[i]=rand()%91+10;
        
        fprintf(fp,"%i\t",x[i]);
        y[i]=rand()%91+10;
        fprintf(fp,"%i\t",y[i]);
        z[i]=rand()%91+10;
        fprintf(fp,"%i\n",z[i]);
    }
    fclose(fp);
   
    
    
    return 0;
}
