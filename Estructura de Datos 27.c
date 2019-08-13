#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define T 50
struct datos
{
    char nombre[T];
    float sueldo;
    char cat;
};
typedef struct datos sinonimo;
void Abre1(FILE**);
void Carga1(FILE*);
void Lee1(FILE*);
void Baja1(FILE*);

int main()
{
    system("color F0");
    FILE *arch1=NULL;
    Abre1(&arch1);
    Carga1(arch1);
    rewind(arch1);
    Lee1(arch1);
    rewind(arch1);
    Baja1(arch1);
    rewind(arch1);
    Lee1(arch1);
}

void Abre1(FILE ** arch1)
{
    char cad[T];
    printf("\n\t\t\t\tArchivo Binario.\n\n");
    printf("\nIngresa el Nombre del Primer Archivo con la Extencion -.txt-: ");
    gets(cad);
    *arch1=fopen(cad,"a+");
    if(*arch1==NULL)
    {
        printf("\n\nError. No Se Pudo Abrir el Archivo.\n\n");
        getchar();
        exit(1);
    }
}

void Carga1(FILE *arch1)
{
    sinonimo x1;
    char *var=NULL;
    printf("\nIngresa los Elemento al Archivo. Para Terminar de Cargar Ingresa el Nulo.\n");
    printf("\nIngresa el Nombre del Trabajador: ");
    var=gets(x1.nombre);
    if(var!=NULL)
    {
        printf("Ingesa el Sueldo de %s:",x1.nombre);
        scanf("%f",&x1.sueldo);
        x1.cat='A';
    }
    while(var!=NULL)
    {
        fprintf(arch1,"%-10s %-10f %-1c\n",x1.nombre,x1.sueldo,x1.cat);
        fflush(stdin);
        printf("\nIngresa el Nombre del Trabajador: ");
        var=gets(x1.nombre);
        if(var!=NULL)
        {
            printf("Ingesa el Sueldo de %s:",x1.nombre);
            scanf("%f",&x1.sueldo);
            x1.cat='A';
        }
    }
}

void Lee1(FILE *arch1)
{
    sinonimo x1;
    printf("\n\nLa Informacion Ingresada en el Archivo es:\n");
    fscanf(arch1,"%s %f %c",x1.nombre,&x1.sueldo,&x1.cat);
    while(!feof(arch1))
    {
        printf("\nEl Trabajador %-10s tiene un Sueldo de $%-10f. Su estado es: %-1c\n",x1.nombre,x1.sueldo,x1.cat);
        fscanf(arch1,"%s %f %c",x1.nombre,&x1.sueldo,&x1.cat);
    }
}

void Baja1(FILE *arch1)
{
    sinonimo x1;
    char cad[T];
    int comp;
    printf("\n\nIngresa el Nombre del Trabajador para Darlo de Baja: ");
    gets(cad);
    fscanf(arch1,"%s %f %c",x1.nombre,&x1.sueldo,&x1.cat);
    while(!feof(arch1))
    {
        comp=strcmp(cad,x1.nombre);
        if(comp==0)
        {
            x1.cat='*';
            fseek(arch1,-sizeof(x1),SEEK_CUR);
            fprintf(arch1,"%-10s %-10f %-1c\n",x1.nombre,x1.sueldo,x1.cat);
        }
        fscanf(arch1,"%s %f %c",x1.nombre,&x1.sueldo,&x1.cat);
    }
}
