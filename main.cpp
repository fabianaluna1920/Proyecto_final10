
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "header_final.h"


using namespace std;

int main()
{
    int opcion;
    float vi1,vi2=0,masa1, masa2, altura, masa=0,v0,pos0, angulo,t=0,k,rad;

    cout<<"Ingrese la opcion para el calculo que desea realizar:"<<endl;
    cout<<"1  si desea colision elastica"<<endl;
    cout<<"2  si desea rebotes"<<endl;
    cout<<"3  si desea movimiento parabolico sin friccion"<<endl;
    cout<<"4  si desea movimiento parabolico con friccion"<<endl;

    cin>>opcion;

    cout<<"Ha seleccionado la Opcion: "<<opcion<<endl;
    cout<<endl;


    //Menu para las Diferentes Opciones de Movimientos
    switch(opcion)
    {
    //Choque elastico
    case 1:
       cout<<"Ingrese el valor para la masa en la particula 1"<<endl;
       cin>>masa1;
       cout<<"Ingrese el valor para la  masa en la particula 2"<<endl;
       cin>>masa2;
       cout<<"Ingrese la velocidad inicial en la particula 1"<<endl;
       cin>>vi1;
       cout<<"Ingrese la velocidad inicial en la particula 2"<<endl;
       cin>>vi2;
       cout<<endl;

       choque_elastico(masa1, masa2, vi1, vi2);
       break;

    //Rebote
    case 2:
       cout<<"Digite la altura deseada"<<endl;
       cin>>altura;
       cout<<"Digite el valor para la masa de la particula"<<endl;
       cin>>masa;

       rebote(altura, masa);
       break;

    //Movimiento parabolico sin friccion
    case 3:
       cout<<"Ingrese la posicion inicial"<<endl;
       cin>>pos0;
       cout<<"Ingrese la velocidad inicial"<<endl;
       cin>>v0;
       cout<<"Ingrese angulo de lanzamiento"<<endl;
       cin>>angulo;
       cout<<"Ingrese el tiempo"<<endl;
       cin>>t;

       movimiento_parabolico(v0, pos0, angulo, t);
       break;

    // Movimiento parabolico con friccion
    case 4:
       cout<<"Ingrese la posicion inicial"<<endl;
       cin>>pos0;
       cout<<"Ingrese la velocidad inicial"<<endl;
       cin>>v0;
       cout<<"Ingrese angulo de lanzamiento"<<endl;
       cin>>angulo;
       cout<<"Ingrese el tiempo"<<endl;
       cin>>t;
       cout<<"Digite el valor de la constante de friccion"<<endl;
       cin>>k;
       cout<<"Digite el radio de la particula"<<endl;
       cin>>rad;
       cout<<"Digite el valor de la masa de la particula"<<endl;
       cin>>masa;

       movi_parabolico_friccion( v0, pos0, angulo,  t,  rad, k,masa);
       break;

    default:
       cout<<"Opcion Incorrecta Intente de Nuevo"<<endl;
       break;
   }
        return 0;
}
