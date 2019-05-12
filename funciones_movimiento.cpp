#include <stdio.h>
#include <iostream>
#include <math.h>
#define g 9.8
#define pi 3.141592

using namespace std;

void choque_elastico(int m1, int m2, float vi1, float vi2)
{
    float vf1, vf2=0;

    if(vi2==0 && vi1>0)  //si la masa 2 esta en reposo y la 1 en movimiento
    {
     vf1=(m1-m2)*vi1/(m1+m2);
     vf2=2*m1*vi1/(m1+m2);

    cout<<"la velocidad final de m1 es "<<vf1<<endl;
    cout<<"la velocidad final de m2 es "<<vf2<<endl;
    cout<<endl;
    }
    else if(vi1==0 && vi2<0) //si la masa 1 esta en reposo y la 2 en movimiento
    {
     vf1=2*m2*vi2/(m1+m2);
     vf2=(m2-m1)*vi2/(m1+m2);
    cout<<"la velocidad final de m1 es "<<vf1<<endl;
    cout<<"la velocidad final de m2 es "<<vf2<<endl;
    }

    else//las dos masas en movimiento
    {
     vf1=((m1-m2)*vi1/(m1+m2))+(2*m2*vi2/(m1+m2));
     vf2=(2*m1*vi1/(m1+m2))-((m1-m2)*vi2/(m1+m2));
     cout<<"la velocidad final de m1 es "<<vf1<<endl;
     cout<<"la velocidad final de m2 es "<<vf2<<endl;
    }

}


void rebote(float h, int masa)
{
    float e =0.8;
    int n=0;
    float altura;
    altura=h;

    if(altura<0.1)
    {
        cout<<"la altura ingresda es muy baja, intente de nuevo"<<endl;
    }

    while(altura>0.1)
    {
        ++n;
        altura=pow(e,(2*n))*h;
        cout<<"rebote:"<<n<<" altura "<<altura<<endl;
    }
}

//Movimiento parabolico sin friccion
void movimiento_parabolico(int v0, int pos0, int ang, int t)
{
     double x, y, Vx, Vy;
     int  n=0;
     n=t;

         for(t=0;t<=n;++t)
         {
             x= v0*(cos(ang*pi/180))*t;   //ecuacion para calcular posicion en x
             y= pos0+(v0*(sin(ang*pi/180))*t)- 0.5*g*pow(t,2);//ecuacion para calcular posicion en y
             Vx=v0*cos(ang*pi/180);   //ecuacion para calcular velocidad en x
             Vy=v0*sin(ang*pi/180)-(g*t);  //ecuacion para calcular velocidad en y

             cout<<"En tiempo= "<<t<<endl;
             cout<<"la posicion en x es "<<x<<endl;
             cout<<"la posicion en y es "<<y<<endl;
             cout<<"la velocidad en x es "<<Vx<<endl;
             cout<<"la velocidad en y es "<<Vy<<endl;
             cout<<endl;
         }
}

 //Movimiento parabolico con friccion
 void movi_parabolico_friccion(int v0, int pos0, int ang, int t, int rad,int k,int masa)
 {
    double x, y, Vx, Vy, v, theta, Ax, Ay, Vxa, Vya=0;
    int n=0;
    n=t;

          for(t=0;t<=n;++t)
          {
             Vx=v0*cos(ang*pi/180);  //velocidad en x sin friccion
             Vy=v0*sin(ang*pi/180)-(g*t); //velocidad en y sin friccion
             v=sqrt(pow(Vx,2)+pow(Vy,2));  //magnitud de la velocidad
             theta=atan(Vx/Vy)*180/pi;   //angulo de la velocidad
             Ax= -(((k*pow(v,2)*pow(rad,2))/masa)*cos(theta*pi/180));  //aceleracion en x
             Ay= -(((k*pow(v,2)*pow(rad,2))/masa)*sin(theta*pi/180))-g;  //aceleracion en y

             x= v0*cos(ang*pi/180)*t + 0.5*Ax*pow(t,2);  //posicion en x con aceleracion
             y= pos0+(v0*sin(ang*pi/180)*t)+ 0.5*Ay*pow(t,2); //posicion en y con aceleracion
             Vxa=v0*cos(ang*pi/180)+Ax*t;  //velocidad en x con aceleracion
             Vya=v0*sin(ang*pi/180)+Ay*t;  //velocidad en y con aceleracion

             cout<<"En tiempo= "<<t<<endl;
             cout<<"La magnitud de la velocidad es "<<v<<endl;
             cout<<"El angulo theta es "<<theta<<endl;
             cout<<"La aceleracion en x es "<<Ax<<endl;
             cout<<"La aceleracion en y es "<<Ay<<endl;
             cout<<"la posicion en x es "<<x<<endl;
             cout<<"la posicion en y es "<<y<<endl;
             cout<<"la velocidad en x es "<<Vxa<<endl;
             cout<<"la velocidad en y es "<<Vya<<endl;
             cout<<endl;
         }
}




