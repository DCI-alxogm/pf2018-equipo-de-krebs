//Este codigo lee los archivos random y guarda sus datos en arreglos
//Creado por Patricia Godinez el 5 de diciembre de 2018
#include<stdio.h>

int main()
{
	FILE *fp;
	FILE *fs;
	FILE *fp2;
	FILE *fs2;

	int nol=0,nw=0,nc=0; //nol es el numero de lineas que tenemos en el archivo 
	char ch;
//contador de lineas del archivo para poder leer solo los datos necesarios del archivo
    fs=fopen("random.txt","r");
    while((ch=fgetc(fs))!=EOF)
    {
        if(ch==' ')
            nw++;
        else if(ch=='\n')
            nol++;
        else
            nc++;
        
        
    }
//leyendo el archivo random.txt para guardar las coordenadas en arreglos.
	float xd[255], yd[255], zd[255];
	int i, con=0;
	fp=fopen("random.txt","r");
	for(i=0;i<nol;i++)
	{
		fscanf(fp,"%f	%f	%f",&xd[i],&yd[i],&zd[i]);
		con++;
		printf("%f\t%f\t%f\n",xd[i],yd[i],zd[i]);
		
	}
	fclose(fp);
    fclose(fs);



	printf("//////////////////////\n");//linea de separacion 




	int nol2=0,nw2=0,nc2=0; //nol es el numero de lineas que tenemos en el archivo 
	char ch2;

//contador de lineas del archivo para poder leer solo los datos necesarios del archivo
    fs2=fopen("random2.txt","r"); 
    while((ch2=fgetc(fs2))!=EOF)
    {
        if(ch2==' ')
            nw2++;
        else if(ch2=='\n')
            nol2++;
        else
            nc2++;
        
        
    }
//leyendo el archivo random2.txt para guardar las coordenadas en arreglos.
	float xd2[255], yd2[255], zd2[255];
	int j, con2=0;
	fp2=fopen("random2.txt","r");
	for(j=0;j<nol2;j++)
	{
		fscanf(fp2,"%f	%f	%f",&xd2[i],&yd2[i],&zd2[i]);
		con++;
		printf("%f\t%f\t%f\n",xd2[i],yd2[i],zd2[i]);
		
	}
    double r[nol];
    
    for (i=0; i<nol; i++)
    {
        r[i]=sqrt(pow(xd[i+1]-xd[i],2)+pow(yd[i+1]-yd[i],2)+pow(zd[i+1]-zd[i],2));
        
        printf("r[%d]= %f\n",i,r[i]);
    }
    
    
    double r_2[nol2];
    for (i=0; i<nol2; i++)
    {
        r_2[i]=sqrt(pow(xd2[i+1]-xd2[i],2)+pow(yd2[i+1]-yd2[i],2)+pow(zd2[i+1]-zd2[i],2));
        printf("r_2[%d]= %f\n",i,r_2[i]);
    }
    
	fclose(fp2);
    fclose(fs2);


    return 0;

}
