//Este es el archivo con el codigo del proyecto final.
//Creado por Patricia Godinez y Saul Sierra.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
float *funcion_datos();
int funcion_random();


int main ()
{
    int op;
    printf("Elige que tipo de estimador deseas usar:\n1=Estimador simple\n2=Estimador Landy-Szalay\n");
    scanf("%i",&op);

    switch(op)
    {
    case 1:
            //Este es el caso en el que se desea usar el estimador simple.

            *funcion_datos();
            printf("/////////\n");
            funcion_random();
            printf("/////////\n");

        break;

    case 2:
            //Este es el caso en el que se desea usar el estimador de Landy-Szalay

        break;
    }
}
float *funcion_datos()
{
//Leyendo las coordenadas desde el archivo de datos
    FILE *fp;
    FILE *fs;

    int nol=0,nw=0,nc=0; //nol es el numero de lineas que tenemos en el archivo
    char ch;
    fs=fopen("test_correlacion_med.dat","r");
    while((ch=fgetc(fs))!=EOF)
    {
        if(ch==' ')
            nw++;
        else if(ch=='\n')
            nol++;
        else
            nc++;


    }
	float xd[nol], yd[nol], zd[nol];
	int i, con=0;
	fp=fopen("test_correlacion_med.dat","r");
	for(i=0;i<nol;i++)
	{
		fscanf(fp,"  %f  %f  %f",&xd[i],&yd[i],&zd[i]);
		con++;
		printf("%f\t%f\t%f\n",xd[i],yd[i],zd[i]);

	}
	fclose(fp);
    fclose(fs);
    return (float *) xd, (float *) yd, (float *) zd, (int *) nol;
}
int funcion_random()
{
//Leyendo los datos desde archivo random
    FILE *fp2;
	FILE *fs2;
    int nol2=0,nw2=0,nc2=0; //nol es el numero de lineas que tenemos en el archivo
	char ch2;

//contador de lineas del archivo para poder leer solo los datos necesarios del archivo
    fs2=fopen("random.txt","r");
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
	float xr2[nol2], yr2[nol2], zr2[nol2];
	int j, con2=0;
	fp2=fopen("random.txt","r");
	for(j=0;j<nol2;j++)
	{
		fscanf(fp2,"%f	%f	%f",&xr2[j],&yr2[j],&zr2[j]);
		con2++;
		printf("%f\t%f\t%f\n",xr2[j],yr2[j],zr2[j]);

	}
	return xr2;
	return yr2;
	return zr2;
	return nol2;
}
