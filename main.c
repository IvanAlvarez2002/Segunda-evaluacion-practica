#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//Inciso a)
	
	printf("-----------------------------------------------\n");
	
	
	
	FILE *tabla=fopen("Tabla.txt","rb");
	
	float precio=0,compra=0;
	char articulo[10],fecha[10];
	char y;
	int i=0,i2=0,nart=75,j=0,id=0,existencias,v=0,n,r;
	float *a;
	int *index;
	
	while(feof(tabla)==0){//while para mostrar y contar elementos del archivo de texto
		fscanf(tabla,"%s%f%f%d",&articulo,&precio,&fecha,&existencias);
		//printf("%s $%.2f %s %d \n",articulo,precio,fecha,existencias);
		i2++;
	}
	rewind(tabla);
	a=(float *) calloc(i2,sizeof(float));
	int *b=(int *) calloc(i2,sizeof(int));
	float *c=(float *) calloc(i2,sizeof(float));
	
	index=(int *) calloc(nart,sizeof(int));
	//system("pause");
	
	while(feof(tabla)==0){//while para guardar los valores del precio en un arreglo
		fscanf(tabla,"%s%f%s%d",&articulo,&precio,&fecha,&existencias);
		i++;
		a[i]=precio;//variable donde se guarda el precio
		b[i]=existencias;
		
	}
	
	
		for(i=0;i<nart;i++){
		j++;
		index[j]=(int)a[i]%nart;
		//printf("el index es: %d \n",index[j]);

		
	}
	
	while(r!=3){
	printf("1.Consultar articulos\n2.Buscar articulo\n3.Salir\n");
	scanf("%d",&r);
	switch(r){
	case 1:
	rewind(tabla);
	while(feof(tabla)==0){//while para mostrar y contar elementos del archivo de texto
	fscanf(tabla,"%s%f%f%d",&articulo,&precio,&fecha,&existencias);
	printf("%s $%.2f %s %d \n",articulo,precio,fecha,existencias);
	i2++;
	}
	break;
	case 2:
	printf("Introduzca el identificador del articulo a comprar\n");
	scanf("%d",&id);
	
	
	
	for(i=0;i<nart;i++){
		j++;
		index[j]=(int)a[i]%nart;
		if(id==index[j]){
		n++;
		a[i]=(a[i]*0.60)+a[i];	
		printf("articulo_%d precio: %.2f existencias: %d\n",i,a[i],b[i]);
		printf("¿Desea comprarlo?\n");
		printf("1.Si\n2.No\n");
		scanf("\n%d",&y);
		if(y==1){
			compra=compra+a[i];
			printf("Compra realizada se cargaron $%f a la cuenta\n",compra);
		}
		}
		if(n>0){
			
			index[j]=((int)a[i]*2)%nart;
			n=0;
			break;
		}
		if(id!=index[j] && id>100){
			printf("No se ha encontrado el articulo\n");
			break;
		}
		
	}
	break;
}
}
	return 0;
}

