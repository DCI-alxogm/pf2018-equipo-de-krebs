//Este es el archivo con el codigo del proyecto final.
//Creado por Patricia Godinez y Saul Sierra.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main ()
{
    FILE *fp;
    FILE *fs;
    FILE *fp2;
	FILE *fs2;
	int nol=0,nw=0,nc=0; //nol es el numero de lineas que tenemos en el archivo
    char ch;
    float xd[nol], yd[nol], zd[nol];
	int i, con=0;
	int nol2=0,nw2=0,nc2=0; //nol es el numero de lineas que tenemos en el archivo
    char ch2;
	float xr2[nol2], yr2[nol2], zr2[nol2];
    int j, con2=0;
    int nol_dr=nol + nol2;
    float xdr[nol_dr], ydr[nol_dr], zdr[nol_dr];
    double r[nol];
    float dd=0,rr=0,dr=0;
    double r_2[nol2];
    double r_dr[nol_dr];
    float nd, nr, ndr;
    float sim1,sim2;
    float est,pru1,pru2,pru3;


    int op;
    printf("Elige que tipo de estimador deseas usar:\n1=Estimador simple\n2=Estimador Landy-Szalay\n");
    scanf("%i",&op);

    switch(op)
    {
    case 1:
            //Este es el caso en el que se desea usar el estimador simple.
            //Leyendo las coordenadas desde el archivo de datos

        fs=fopen("test_correlacion_small.dat","r");
        while((ch=fgetc(fs))!=EOF)
        {
            if(ch==' ')
                nw++;
            else if(ch=='\n')
                nol++;
            else
                nc++;
        }

        fp=fopen("test_correlacion_small.dat","r");
        for(i=0;i<nol;i++)
        {
            fscanf(fp,"  %f  %f  %f",&xd[i],&yd[i],&zd[i]);
            con++;
            printf("%f\t%f\t%f\n",xd[i],yd[i],zd[i]);

        }
        fclose(fp);
        fclose(fs);

        printf("//////////////////\n");

            //Leyendo los datos desde archivo random

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

        fp2=fopen("random.txt","r");
        for(j=0;j<nol2;j++)
        {
            fscanf(fp2,"%f	%f	%f",&xr2[j],&yr2[j],&zr2[j]);
            con2++;
            printf("%f\t%f\t%f\n",xr2[j],yr2[j],zr2[j]);
        }

        printf("///////////////\n");

	//Calculando DR utilizando la funcion de memcpy de string.h

        memcpy(xdr,xd,sizeof(float) * nol);
        memcpy(xdr+nol2,xr2,sizeof(float) *nol2);
        memcpy(ydr,yd,sizeof(float) * nol);
        memcpy(ydr+nol2,yr2,sizeof(float) *nol2);
        memcpy(zdr,zd,sizeof(float) * nol);
        memcpy(zdr+nol2,zr2,sizeof(float) *nol2);
        unsigned short it=0;

        for (it=0;it<nol_dr;it++)
        {
            printf("%f\t%f\t%f\n",xdr[it],ydr[it],zdr[it]);
        }

                                                    //Calculando r
        for (i=0; i<nol; i++) //Aplicamos la un ciclo for para obtener r con los diferentes pares de coordenadas
        {
        r[i]=sqrt(pow(xd[i+1]-xd[i],2)+pow(yd[i+1]-yd[i],2)+pow(zd[i+1]-zd[i],2));

        printf("r[%d]= %f\n",i,r[i]);
        if(r[i]<=99)//Esta es la condición para que solo me cuente los datos que estan en el rango que yo puse
        {
            dd++;
        }
        }


        for (i=0; i<nol2; i++)
        {
        r_2[i]=sqrt(pow(xr2[i+1]-xr2[i],2)+pow(yr2[i+1]-yr2[i],2)+pow(zr2[i+1]-zr2[i],2));
        printf("r_2[%d]= %f\n",i,r_2[i]);
        if(r_2[i]<=99)
        {
            rr++;
        }
        }

        for (i=0; i<nol_dr; i++)
        {
        r_dr[i]=sqrt(pow(xdr[i+1]-xdr[i],2)+pow(ydr[i+1]-ydr[i],2)+pow(zdr[i+1]-zdr[i],2));
        printf("r_dr[%d]= %f\n",i,r_dr[i]);
        if(r_2[i]<=99)
        {
            dr++;
        }
        }

        //para tomar nd, nr y ndr

        nd=nol;
        nr=nol2;
        ndr=nol_dr;
        printf("Tus pares en la hoja de datos son=%f\n",dd); //obtenemos DD y RR
        printf("Tus pares en la hoja de random son=%f\n",rr);
        printf("Tus pares en la hoja de datos y random son=%f\n",dr);
        printf("nd=%f\n",nd);
        printf("nr=%f\n",nr);
        printf("ndr=%f\n",ndr);
        fclose(fp2);
        fclose(fs2);

        //Calculando con estimador simple
        sim1=nr/nd;
        sim2=dd/rr;
        est=(sim1*sim2)-1;
        printf("Tu estimador tiene un valor de= %f",est);

        break;

    case 2:
            //Este es el caso en el que se desea usar el estimador de Landy-Szalay
        //Leyendo las coordenadas desde el archivo de datos

        fs=fopen("test_correlacion_small.dat","r");
        while((ch=fgetc(fs))!=EOF)
        {
            if(ch==' ')
                nw++;
            else if(ch=='\n')
                nol++;
            else
                nc++;
        }

        fp=fopen("test_correlacion_small.dat","r");
        for(i=0;i<nol;i++)
        {
            fscanf(fp,"  %f  %f  %f",&xd[i],&yd[i],&zd[i]);
            con++;
            printf("%f\t%f\t%f\n",xd[i],yd[i],zd[i]);

        }
        fclose(fp);
        fclose(fs);

        printf("//////////////////\n");

            //Leyendo los datos desde archivo random

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

        fp2=fopen("random.txt","r");
        for(j=0;j<nol2;j++)
        {
            fscanf(fp2,"%f	%f	%f",&xr2[j],&yr2[j],&zr2[j]);
            con2++;
            printf("%f\t%f\t%f\n",xr2[j],yr2[j],zr2[j]);
        }

        printf("///////////////\n");

	//Calculando DR utilizando la funcion de memcpy de string.h

        memcpy(xdr,xd,sizeof(float) * nol);
        memcpy(xdr+nol2,xr2,sizeof(float) *nol2);
        memcpy(ydr,yd,sizeof(float) * nol);
        memcpy(ydr+nol2,yr2,sizeof(float) *nol2);
        memcpy(zdr,zd,sizeof(float) * nol);
        memcpy(zdr+nol2,zr2,sizeof(float) *nol2);


        for (it=0;it<nol_dr;it++)
        {
            printf("%f\t%f\t%f\n",xdr[it],ydr[it],zdr[it]);
        }

                                                    //Calculando r
        for (i=0; i<nol; i++) //Aplicamos la un ciclo for para obtener r con los diferentes pares de coordenadas
        {
        r[i]=sqrt(pow(xd[i+1]-xd[i],2)+pow(yd[i+1]-yd[i],2)+pow(zd[i+1]-zd[i],2));

        printf("r[%d]= %f\n",i,r[i]);
        if(r[i]<=99)//Esta es la condición para que solo me cuente los datos que estan en el rango que yo puse
        {
            dd++;
        }
        }


        for (i=0; i<nol2; i++)
        {
        r_2[i]=sqrt(pow(xr2[i+1]-xr2[i],2)+pow(yr2[i+1]-yr2[i],2)+pow(zr2[i+1]-zr2[i],2));
        printf("r_2[%d]= %f\n",i,r_2[i]);
        if(r_2[i]<=99)
        {
            rr++;
        }
        }

        for (i=0; i<nol_dr; i++)
        {
        r_dr[i]=sqrt(pow(xdr[i+1]-xdr[i],2)+pow(ydr[i+1]-ydr[i],2)+pow(zdr[i+1]-zdr[i],2));
        printf("r_dr[%d]= %f\n",i,r_dr[i]);
        if(r_2[i]<=99)
        {
            dr++;
        }
        }

        //para tomar nd, nr y ndr

        nd=nol;
        nr=nol2;
        ndr=nol_dr;
        printf("Tus pares en la hoja de datos son=%f\n",dd); //obtenemos DD y RR
        printf("Tus pares en la hoja de random son=%f\n",rr);
        printf("Tus pares en la hoja de datos y random son=%f\n",dr);
        printf("nd=%f\n",nd);
        printf("nr=%f\n",nr);
        printf("ndr=%f\n",ndr);
        fclose(fp2);
        fclose(fs2);

        //Calculando con estimador de Landy-Szalay
    //Dividimos la ecuacion en pequeñas funciones, para facilitar su calculo

        pru1=dd/nd;
        pru2=(2*dr)/ndr;
        pru3=rr/nr;
        printf("%f\t%f\t%f\n",pru1,pru2,pru3);
        est=((pru1)-(pru2)+(pru3))/(pru3);
        printf("Tu estimador tiene un valor de= %f",est);


        break;

    }
    return 0;
}
