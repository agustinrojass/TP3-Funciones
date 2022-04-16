#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
//FALTA 7
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();
void ejercicio10();

//Pila cargarPila(Pila pila);                             //(1)
void cargarPilaCR(Pila *pila);                          //(2)
Pila copiarPila(Pila *pila);                            //(3)
Pila copiarPilaIgual(Pila *pila);                       //(4)
int eliminarMenor(Pila *pila);                          //(5)
Pila ordenarPila(Pila *pila);                           //(6)
Pila copiaOrdenada(Pila *pila);                         //(7)
int suma2Elementos(int num1,int num2);                  //(8)
int sumarPila(Pila pila);                               //(9)
int contadorElementos(Pila pila);                       //(10)
float promedioPila(Pila pila);                          //(11)
int numeroPila (Pila pila);                             //(12)

int main()
{
    int ejercicio;
    do
    {
        do
        {
            printf("EJERCICIOS                                                 INGRESAR");
            printf("\nEJERCICIO 1  ...................................................  1");
            printf("\nEJERCICIO 2  ...................................................  2");
            printf("\nEJERCICIO 3  ...................................................  3");
            printf("\nEJERCICIO 4  ...................................................  4");
            printf("\nEJERCICIO 5  ...................................................  5");
            printf("\nEJERCICIO 6  ...................................................  6");
            printf("\nEJERCICIO 7  ...................................................  7");
            printf("\nEJERCICIO 8  ...................................................  8");
            printf("\nEJERCICIO 9  ...................................................  9");
            printf("\nEJERCICIO 10 ................................................... 10\n");
            printf("\nIngrese el ejercicio: ");
            scanf("%i",&ejercicio);
        }
        while(ejercicio!=1 && ejercicio!=2 && ejercicio!=3 && ejercicio!=4 && ejercicio!=5 && ejercicio!=6 && ejercicio!=7 && ejercicio!=8 && ejercicio!=9 && ejercicio!=10 && ejercicio!=0);
        if(ejercicio!=0)
        {
            printf("\nEJERCICIO %i\n\n",ejercicio);
        }
        switch(ejercicio)
        {
            case 1:
            {
                ejercicio1();
            }
            break;
            case 2:
            {
                ejercicio2();
            }
            break;
            case 3:
            {
                ejercicio3();
            }
            break;
            case 4:
            {
                ejercicio4();
            }
            break;
            case 5:
            {
                ejercicio5();
            }
            break;
            case 6:
            {
                ejercicio6();
            }
            break;
            case 7:
            {
                ejercicio7();
            }
            break;
            case 8:
            {
                ejercicio8();
            }
            break;
            case 9:
            {
                ejercicio9();
            }
            break;
            case 10:
            {
                ejercicio10();
            }
            break;
        }
    }
    while(ejercicio!=0);
    printf("\nTP3 TERMINADO\n");
    printf("\nVersion 1.2\n");
    return 0;
}
/*Pila cargarPila(Pila pila)                              //INICIO FUNCION CARGAR ELEMENTOS EN UNA PILA   (1)
{
    char continuar;
    printf("Ingrese los elementos de la pila:\n\n");
    do
    {
        leer(&pila);
        printf("Desea ingresar otro elemento? s/n Respuesta: ");
        fflush(stdin);
        scanf("%c",&continuar);
        printf("\n");
    }
    while(continuar!='n');
    return pila;
}*/                                                       //FIN FUNCION CARGAR ELEMENTOS EN UNA PILA
void cargarPilaCR(Pila *pilaCR)                         //INICIO FUNCION CARGAR ELEMENTOS EN UNA PILA   (2)
{
    char continuar;
    printf("Ingrese los elementos de la pila:\n\n");
    do
    {
        leer(pilaCR);
        printf("Desea ingresar otro elemento? s/n Respuesta: ");
        fflush(stdin);
        scanf("%c",&continuar);
        printf("\n");
    }
    while(continuar!='n');
}                                                       //FIN FUNCION CARGAR ELEMENTOS EN UNA PILA
Pila copiarPila(Pila *pila)                             //INICIO FUNCION COPIAR PILA                    (3)
{
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(pila))
    {
        apilar(&aux,desapilar(pila));
    }
    return aux;
}                                                       //FIN FUNCION COPIAR PILA
Pila copiarPilaIgual(Pila *pila)                        //INICIO FUNCION COPIAR PILA EN EL MISMO ORDEN  (4)
{
    Pila aux,aux2;
    inicpila(&aux);
    inicpila(&aux2);
    while(!pilavacia(pila))
    {
        apilar(&aux,desapilar(pila));
    }
    while(!pilavacia(&aux))
    {
        apilar(&aux2,desapilar(&aux));
    }
    return aux2;
}                                                       //FIN FUNCION COPIAR PILA EN EL MISMO ORDEN
int eliminarMenor(Pila *pila)                           //INICIO FUNCION ELIMINAR EL MENOR DE UNA PILA  (5)
{
    int menor;
    Pila aux,pilaMenor;
    inicpila(&aux);
    inicpila(&pilaMenor);
    apilar(&pilaMenor,desapilar(pila));
    while(!pilavacia(pila))
    {
        if(tope(&pilaMenor)>tope(pila))
        {
            apilar(&aux,desapilar(&pilaMenor));
            apilar(&pilaMenor,desapilar(pila));
        }
        else
        {
            apilar(&aux,desapilar(pila));
        }
    }
    while(!pilavacia(&aux))
    {
        apilar(pila,desapilar(&aux));
    }
    menor=tope(&pilaMenor);
    return menor;
}                                                       //FIN FUNCION ELIMINAR EL MENOR DE UNA PILA
Pila ordenarPila(Pila *pila)                            //INICIO FUNCION ORDENAR PILA                   (6)
{
    int menor;
    Pila ordenada;
    inicpila(&ordenada);
    while(!pilavacia(pila))
    {
        menor=eliminarMenor(pila);                      //FUNCION ELIMINARMENOR
        apilar(&ordenada,menor);
    }
    while(!pilavacia(&ordenada))
    {
        apilar(pila,desapilar(&ordenada));
    }
    //el return lo utilizo solo en algunos ejercicios en los que neceito una copia ordenada y no solo ordenar la pila original
    return *pila;
}                                                       //FIN FUNCION ORDENAR PILA
Pila copiaOrdenada(Pila *pila)                          //INICIO FUNCION COPIAR PILA Y ORDENARLA        (7)
{
    Pila auxX;
    inicpila(&auxX);

    auxX=copiarPila(pila);

    ordenarPila(&auxX);

    return auxX;
}                                                       //INICIO FUNCION COPIAR PILA Y ORDENARLA
int suma2Elementos(int num1,int num2)                   //INICIO FUNCION SUMAR 2 ELEMENTOS              (8)
{
    int suma=0;
    suma=num1+num2;
    return suma;
}                                                       //FIN FUNCION SUMAR 2 ELEMENTOS
int sumarPila(Pila pila)                                //INICIO FUNCIONSUMARPILA                       (9)
{
    int suma=0;
    while(!pilavacia(&pila))
    {
        suma=suma+tope(&pila);
        desapilar(&pila);
    }
    return suma;
}                                                       //FIN FUNCION SUMARPILA
int contadorElementos(Pila pila)                        //INICIO FUNCION CONTAR ELEMENTOS               (10)
{
    int contador=0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&pila))
    {
        apilar(&aux,desapilar(&pila));
        contador++;
    }
    return contador;
}                                                       //FIN FUNCION CONTAR ELEMENTOS
float promedioPila(Pila pila)                           //INICIO FUNCION PROMEDIO DE PILA               (11)
{
    float suma,contador,promedio;
    suma=sumarPila(pila);                               //FUNCION SUMARPILA
    contador=contadorElementos(pila);                   //FUNCION CONTADORPILA
    promedio=suma/contador;
    return promedio;
}                                                       //FIN FUNCION PROMEDIO DE PILA
int numeroPila (Pila pila)                              //INICIO FUNCION PILA A NUMERO DECIMAL          (12)
{
    int contador=0,topeActual,numero=0;
    pila=copiarPila(&pila);
    mostrar(&pila);
    while(!pilavacia(&pila))
    {
        topeActual=desapilar(&pila);
        numero=numero+topeActual*pow(10,contador);
        contador++;
    }
    return numero;
}                                                       //FIN FUNCION PILA A NUMERO DECIMAL

void ejercicio1()
{
    //Hacer una funcion que permita ingresar varios elementos a una pila, tanto como quiera el usuario.
    Pila pila;
    inicpila(&pila);
    cargarPilaCR(&pila);                                //FUNCION CARGARPILACR
    printf("La pila cargada es:");
    mostrar(&pila);
}
void ejercicio2()
{
    //Hacer una funcion que pase todos los elementos de una pila a otra.
    Pila pila,copia;
    inicpila(&pila);
    inicpila(&copia);
    cargarPilaCR(&pila);                                //FUNCION CARGARPILACR
    printf("La pila cargada es:");
    mostrar(&pila);
    copia=copiarPila(&pila);                             //FUNCION CARGARPILACR
    printf("La copia de la pila cargada es:");
    mostrar(&copia);
}
void ejercicio3()
{
    //Hacer una funcion que pase todos los elementos de una pila a otra, pero conservando el orden.
    Pila pila,copia;
    inicpila(&pila);
    inicpila(&copia);
    cargarPilaCR(&pila);                                //FUNCION CARGARPILACR
    printf("La pila cargada es:");
    mostrar(&pila);
    copia=copiarPilaIgual(&pila);                        //FUNCION COPIARPILAIGUAL
    printf("La copia en el mismo orden de la pila cargada es:");
    mostrar(&copia);
}
void ejercicio4()
{
    //Hacer una funcion que encuentre el menor elemento de una pila y lo retorna.
    //La misma debe eliminar ese dato de la pila.
    int menor;
    Pila pila;
    inicpila(&pila);
    cargarPilaCR(&pila);                                //FUNCION CARGARPILA
    printf("La pila inicial es:");
    mostrar(&pila);
    menor=eliminarMenor(&pila);                         //FUNCION ELIMINARMENOR
    printf("El menor elemento de la pila es: %i",menor);
    printf("La pila final es:");
    mostrar(&pila);
}
void ejercicio5()
{
    //Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.
    //Usar la función del ejercicio 4. (Ordenamiento por seleccion)
    Pila pila,ordenada;
    inicpila(&pila);
    inicpila(&ordenada);
    cargarPilaCR(&pila);                                //FUNCION CARGARPILA
    printf("La pila inicial es:");
    mostrar(&pila);
    ordenada=copiaOrdenada(&pila);                      //FUNCION COPIAORDENADA
    printf("La pila ordenada es:");
    mostrar(&ordenada);
}
void ejercicio6()
{
    //Hacer una funcion que inserta en una pila ordenada un nuevo elemento, conservando el orden de esta.
    Pila pila;
    inicpila(&pila);
    cargarPilaCR(&pila);                                //FUNCION CARGARPILA
    ordenarPila(&pila);                                 //FUNCION ORDENARPILA
    printf("La pila inicial ordenada es:");
    mostrar(&pila);
    printf("Ingrese el elemento que desea insertar a la pila");
    leer(&pila);
    ordenarPila(&pila);                                 //FUNCION ORDENARPILA
    printf("La pila final ordenada es:");
    mostrar(&pila);
}
void ejercicio7()
{
    //Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.
    //Usar la funcion del ejercicio 6. (Ordenamiento por insercion)
}
void ejercicio8()
{
    //Hacer una funcion que sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar su contenido.
    int tope1,tope2,suma;
    Pila pila,copia;
    inicpila(&pila);
    inicpila(&copia);
    cargarPilaCR(&pila);                                //FUNCION CARGARPILA
    printf("La pila inicial es:");
    mostrar(&pila);
    copia=pila;
    tope1=desapilar(&copia);
    printf("El primer tope es: %i\n",tope1);
    tope2=desapilar(&copia);
    printf("El segundo tope es: %i\n",tope2);
    suma=suma2Elementos(tope1,tope2);                   //FUNCION SUMA2ELEMENTOS
    printf("\nLa suma es: %i\n\n",suma);
}
void ejercicio9()       //USO UNA FUNCION QUE SUMA LOS ELEMENTOS, OTRA QUE LOS CUENTA, Y OTRA QUE USA ESAS 2 FUNCIONES PARA HACER LA DIVISION
{
    //Hacer una funcion que calcule el promedio de los elementos de una pila, para ello hacer tambien una funcion que calcule la suma, otra para la cuenta y otra que divida.
    //En total son cuatro funciones, y la funcion que calcula el promedio invoca a las otras 3.
    float promedio;
    Pila pila;
    inicpila(&pila);
    cargarPilaCR(&pila);                                //FUNCION CARGARPILA
    printf("La pila inicial es:");
    mostrar(&pila);
    promedio=promedioPila(pila);                        //FUNCION PROMEDIOPILA
    printf("El promedio de la pila es: %.2f\n\n",promedio);
}
void ejercicio10()
{
    //Hacer una funcion que reciba una pila con numeros de un solo digito (es responsabilidad de quien usa el programa) y que transforme esos digitos en un numero decimal. Por ejemplo, la pila:
    //Base 5 - 7 - 6 - 4 - 1 Tope
    //Debe retornar el número: 14675
    int  numero;
    Pila pila;
    inicpila(&pila);
    cargarPilaCR(&pila);                            //FUNCION CARGARPILACR
    numero=numeroPila(pila);                        //FUNCION NUMEROPILA
    printf("El numero decimal es: %i\n\n",numero);
}

