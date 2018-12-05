//
//  proyecto.c
//  
//
//  Created by Saul Sierra Luna on 11/28/18.
//

#include "proyecto.h"
<<<<<<< HEAD
int main ()
{
    FILE *fs;
    FILE *fp;
    
    int nol=0,nw=0,nc=0;
    char ch;
    fs=fopen("datos.txt","r");
    while((ch=fgetc(fs))!=EOF)
    {
        if(ch==' ')
            nw++;
        else if(ch=='\n')
            nol++;
        else
            nc++;
        
        
    }
   
    
    printf("Numero de lineas en el documento=%d \n ",nol);
    fp=fopen("datos.txt","r");
    int xo[nol][3],j;
    printf("%d",xo[nol][3]);
    //for (j=0; j<nol; j++)
    //{
        //(fscanf(fp, "%d", &xo[j][3]);
        //printf("xo[3][%d] %d\n",j,xo[j][3]);
       
    //}
    fclose(fs);
    fclose(fp);
    return 0;
}
=======
#include<stdio.h>
#include<math.h>

>>>>>>> master
