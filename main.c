#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

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

Pila cargarPila(Pila pila);                 //(1)
void cargarPilaCR(Pila *pila);              //(2)
Pila copiarPila(Pila pila);                 //(3)
Pila copiarPilaIgual(Pila pila);            //(4)
void eliminarMenor(Pila *pila);             //(5)
void ordenarPila(Pila *pila);               //(6)
Pila insertarElemento(Pila pila);           //(7)



//Pila ordenarPila(Pila pilaDesordenada);

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
    printf("\nVersion 1.0\n");
    return 0;
}
Pila cargarPila(Pila pila)                              //INICIO FUNCION CARGAR ELEMENTOS EN UNA PILA  (1)
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
}                                                       //FIN FUNCION CARGAR ELEMENTOS EN UNA PILA
void cargarPilaCR(Pila *pilaCR)                         //INICIO FUNCION CARGAR ELEMENTOS EN UNA PILA  (2)
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
Pila copiarPila(Pila pila)                              //INICIO FUNCION COPIAR PILA                   (3)
{
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&pila))
    {
        apilar(&aux,desapilar(&pila));
    }
    return aux;
}                                                       //FIN FUNCION COPIAR PILA
Pila copiarPilaIgual(Pila pila)                         //INICIO FUNCION COPIAR PILA EN EL MISMO ORDEN (4)
{
    return pila;
}                                                       //FIN FUNCION COPIAR PILA EN EL MISMO ORDEN
void eliminarMenor(Pila *pila)                          //INICIO FUNCION MENOR DE UNA PILA             (5)
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
    printf("El menor elemento, el %i, fue eliminado.\n\n",menor);
    //return pila;
}                                                       //FIN FUNCION MENOR DE UNA PILA
void ordenarPila(Pila *pila)                            //INICIO FUNCION ORDENAR UNA PILA
{
    Pila ordenada,aux;
    inicpila(&ordenada);
    inicpila(&aux);
    while(!pilavacia(pila))
    {
        if(tope(pila)<tope(&ordenada))
        {
            apilar(&ordenada,desapilar(pila));
        }
        else
        {
            while(tope(pila)>tope(&ordenada))
            {
                apilar(&aux,desapilar(&ordenada));
            }
            apilar(&ordenada,desapilar(pila));
            while(!pilavacia(&aux))
            {
                apilar(&ordenada,desapilar(&aux));
            }
        }
    }
    while(!pilavacia(&ordenada))
    {
        //apilar(&aux,desapilar(&ordenada));
        apilar(pila,desapilar(&ordenada));
    }
    //while(!pilavacia(&aux))
    //{
    //    apilar(pila,desapilar(&aux));
    //}
}                                                       //FIN FUNCION ORDENAR UNA PILA



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
    cargarPilaCR(&pila);                               //FUNCION CARGARPILACR
    printf("La pila cargada es:");
    mostrar(&pila);
    copia=copiarPila(pila);                           //FUNCION CARGARPILACR
    printf("La copia de la pila cargada es:");
    mostrar(&copia);
}
void ejercicio3()
{
    //Hacer una funcion que pase todos los elementos de una pila a otra, pero conservando el orden.
    Pila pila,copia;
    inicpila(&pila);
    inicpila(&copia);
    cargarPilaCR(&pila);                               //FUNCION CARGARPILACR
    printf("La pila cargada es:");
    mostrar(&pila);
    copia=copiarPilaIgual(pila);                       //FUNCION COPIARPILAIGUAL
    printf("La copia en el mismo orden de la pila cargada es:");
    mostrar(&copia);
}
void ejercicio4()
{
    //Hacer una funcion que encuentre el menor elemento de una pila y lo retorna.
    //La misma debe eliminar ese dato de la pila.
    Pila pila;
    inicpila(&pila);
    cargarPilaCR(&pila);                                //FUNCION CARGARPILA
    printf("La pila inicial es:");
    mostrar(&pila);
    eliminarMenor(&pila);                               //FUNCION ELIMINARMENOR
    printf("La pila final es:");
    mostrar(&pila);
}
void ejercicio5()
{
    //Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.
    //Usar la función del ejercicio 4. (Ordenamiento por seleccion)
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
}
void ejercicio9()
{
    //Hacer una funcion que calcule el promedio de los elementos de una pila, para ello hacer también una funcion que calcule la suma, otra para la cuenta y otra que divida.
    //En total son cuatro funciones, y la funcion que calcula el promedio invoca a las otras 3.
}
void ejercicio10()
{
    //Hacer una funcion que reciba una pila con numeros de un solo dígito (es responsabilidad de quien usa el programa) y que transforme esos digitos en un numero decimal. Por ejemplo, la pila:
    //Base 5 - 7 - 6 - 4 - 1 Tope
    //Debe retornar el número: 14675
}
