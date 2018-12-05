//Esta es la función que lee las coordenadas del archivo de datos
//Creado por Patricia Godinez el 3 de diciembre de 2018
#include<stdio.h>

int main()
{
	FILE *fp;
    FILE *fs;
    
    int nol=0,nw=0,nc=0; //nol es el numero de lineas que tenemos en el archivo 
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
	float xd[255], yd[255], zd[255];
	int i, con=0;
	fp=fopen("datos.txt","r");
	for(i=0;i<nol;i++)
	{
		fscanf(fp,"%f	%f	%f",&xd[i],&yd[i],&zd[i]);
		con++;
		printf("%f\t%f\t%f\n",xd[i],yd[i],zd[i]);
		
	}
	fclose(fp);
    fclose(fs);
    return 0;
}
