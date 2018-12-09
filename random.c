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
    int x[100],i,y[10],z[10],m[10],n[10],l[10];
   
    for (i=0; i<10; i++)
        
    {
        x[i]=rand()%91+10;
        
        fprintf(fp,"%i\t",x[i]);
        y[i]=rand()%91+10;
        fprintf(fp,"%i\t",y[i]);
        z[i]=rand()%91+10;
        fprintf(fp,"%i\n",z[i]);
    }
    FILE *fs;
    fs=fopen("random2.txt","w");//imprimir dos archivos con numeros aleatorios
   
    
    for (i=0; i<10; i++)
        
    {
        m[i]=rand()%91+10;
        
        fprintf(fs,"%i\t",m[i]);
        n[i]=rand()%91+10;
        fprintf(fs,"%i\t",n[i]);
        l[i]=rand()%91+10;
        fprintf(fs,"%i\n",l[i]);
    }
    fclose(fp);
    fclose(fs);
   
    
    
    return 0;
}
