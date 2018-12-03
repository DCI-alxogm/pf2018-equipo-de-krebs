//Esta es la función que lee las coordenadas del archivo de datos
//Creado por Patricia Godinez el 3 de diciembre de 2018
#include<stdio.h>

int main()
{
	FILE *fp;
	float xd[255], yd[255], zd[255];
	int i, con=0;
	fp=fopen("datos.txt","r");
	for(i=0;i<10;i++)
	{
		fscanf(fp,"%f	%f	%f",&xd[i],&yd[i],&zd[i]);
		con++;
		printf("%f\t%f\t%f\n",xd[i],yd[i],zd[i]);
		
	}
	fclose(fp);	
	/*for(i=0;i<10;i++)
	{
		printf("%f\t%f\t%f\n",xd[i],yd[i],zd[i]);
		//printf("%i",con);
	}	*/
}
