#include <stdio.h>
#include <stdlib.h>

void menu_profesor(); 
void ingreso_notas();
void menu_estudiante();
void consulta_notas(int); 
void promedio_notas(int);
void mayor_nota(int);

int validate_profe(int id_profe_temp,int passwd_profe_temp);
int validate_est(int id_est_temp,int passwd_est_temp);
int validate_est_profe(int id_est_temp);

int i,x;
int id_profe_temp;
int passwd_profe_temp;
int id_est_temp;
int passwd_est_temp;

struct profesor
{
 int id_profe; 
 char nombre[30];
 int passwd_profe;
};

struct estudiante
{
 int id_est;
 char nombre[30];
 int passwd_est;
 float nota[3];
};

struct profesor p[1] = {100,"Geovanny Poveda",9876};

struct estudiante e[3]={{1,"Daniela Silva",1234,{0.0,0.0,0.0}},
                        {2,"Santiago Ortiz ",5678,{0.0,0.0,0.0}},
                        {3,"Sebastian Amezquita",9123,{0.0,0.0,0.0}}};

int main()
{
    while(1) 
    {
        int choice;
        
        printf("\n---Bienvenido al Sistema Academico---\n");
        printf("Quien eres?\n"
            "1. Profesor\n"
            "2. Estudiante\n"
            "3. Salir\n"
            "Ingresa tu eleccion:\t");
        scanf("%d",&choice); 
       
        switch (choice) 
        {
            case 1:
            {
                menu_profesor();
                break; 
            }
            case 2:
            {
                menu_estudiante();
                break;
            }
            case 3:
            {
                exit(1); 
            }
            default: 
                printf("\nIngresa una opcion valida\n");
        }
    }
    
}

int validate_profe(int id_profe_temp, int passwd_profe_temp)
{
    for(i=0;i<1;i++)
    {
        if(p[i].id_profe==id_profe_temp)
        {
            if(p[i].passwd_profe==passwd_profe_temp)
            {
                return i; 
                break;
            }
            else
            {
                printf("\nClave incorrecta\n");
                return -1;
            }
        }
        if(i==0)
        {
            printf("\nEl id no existe\n");
            return -1;
        }
    }
}

void menu_profesor()
{
    printf("\nIngresa tu id:\t");
    scanf("%d",&id_profe_temp);
    printf("\nIngresa la clave:\t");
    scanf("%d",&passwd_profe_temp);
    
    x = validate_profe(id_profe_temp, passwd_profe_temp);
    
    if(x!= -1)
    {
        while(1)
        {
            int choice;
            printf("\nQue desea hacer?\n"
                   "1. Ingresar notas\n"
                   "2. Salida\t");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                {
                    ingreso_notas(); 
                    break;
                }
                case 2:
                {
                    return; 
                }
                default:
                    printf("\nIngresa una opcion valida\n");
            }
        }
    }
}

void ingreso_notas()
{
    printf("\nIngresa el id del estudiante:\t");
    scanf("%d", &id_est_temp);
    
    x = validate_est_profe(id_est_temp);
    
    if(x!= -1)
    {
        
        for(int j = 0; j < 3; j++)
        {
            printf("Ingresa el valor de la %d nota:\n",j+1);
            scanf( "%f", &e[x].nota[j] );
        }
        
        printf("\nNotas ingresadas satisfactoriamente\n");
    }
}

int validate_est_profe(int id_est_temp)
{
    for(i=0; i<3; i++)
    {
        if(e[i].id_est == id_est_temp)
        {
            return i;
            break;
        }
        
        if(i == 2)
        {
            printf("\nEl id no existe\n");
            return -1;
        }
    }
}

int validate_est(int id_est_temp,int passwd_est_temp)
{
    for(i=0;i<3;i++)
    {
        if(e[i].id_est==id_est_temp)
        {
            if(e[i].passwd_est==passwd_est_temp)
            {
                return i;
                break;
            }
            else
            {
                printf("\nClave incorrecta\n");
                return -1;
            }
        }
        if(i==2)
        {
            printf("\nEl id no existe\n");
            return -1;
        }
    }
}

void menu_estudiante()
{
    printf("\nIngresa tu id:\t");
    scanf("%d",&id_est_temp);
    printf("\nIngresa la clave:\t");
    scanf("%d",&passwd_est_temp);
    
    x = validate_est(id_est_temp,passwd_est_temp);

    if(x!= -1)
    {
        
        while(1)
        {
            int choice;
            printf("\nQue desea hacer?\n"
                   "1. Consultar notas\n"
                   "2. Promedio notas\n"
                   "3. Nota mas alta\n"
                   "4. Salida\t");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                {
                    consulta_notas(x);
                    break; 
                }
                case 2:
                {
                    promedio_notas(x);
                    break;
                }
                case 3:
                {
                    mayor_nota(x);
                    break;
                }
                case 4:
                {
                    return;
                }
                default:
                    printf("\nIngresa una opcion valida\n");
            }
        }
    }
}

void consulta_notas(int _x)
{
    for(i=0;i<3;i++)
    {
        printf("\nEl valor de la %d nota es: %.2f \t",i+1, e[_x].nota[i]);
    }
    putchar('\n');
}

void promedio_notas(int _x)
{
    float sum = 0;
    for (i=0;i<3;i++)
    {
        sum=sum+e[_x].nota[i];
    }
    printf("\nEl promedio de tus notas es: %.2f \n",sum/3); 
}

void mayor_nota(int _x)
{
    float temp = 0;
    for (i=0;i<3;i++)
    {
        if(temp < e[_x].nota[i])
        {
            temp = e[_x].nota[i];
        }
    }
    printf("\nLa nota mas alta es: %.2f \n",temp); 
}