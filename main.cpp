#include <iostream>
#include "voxel_clube.h"
#include "escultor_clube.h"

using namespace std;

int main()
{
   Sculptor clube(200, 200, 200);  //definição da matriz 3D
   clube.setColor(0.7, 0.5, 0, 0); //definindo a cor do muro e dos pilares da entrada
   clube.putCilindrop(70, 185, 40, 5); //pilares
   clube.putCilindrop(130, 185, 40, 5);//pilares
   clube.putBox(55, 145, 40, 45, 173, 197); // teto da entrada
   clube.putBox(0, 200, 0, 30, 0, 178); //muro em volta
   clube.cutBox(3, 197, 0, 30, 3, 178);  //muro em volta
   clube.putBox(3,71, 0, 30, 184, 186);//muro frente
   clube.putBox(130,197, 0, 30, 184, 186); //muro frente
   clube.putBox(197, 200, 0, 30, 178, 186);//muro frente
   clube.putBox(0, 3, 0, 30, 178, 186);//muro frente
   clube.putBox(0, 200, 0, 1, 0, 200); //box inferior
   clube.setColor(0.1, 0.4, 0.1, 0); //cor verde da grama
   clube.putBox(3, 197, 10, 11, 3, 184); //grama
   clube.setColor(1, 0.8, 0, 0);  //cor da esfera
   clube.putSphere(70, 50, 185, 5);  //esfera entrada
   clube.putSphere(130, 50, 185, 5);   //esfera entrada

   //piscina
   clube.setColor(0.8, 0.8, 0.8, 0);
   clube.putEllipsoid(50, 10, 60, 25, 10, 30);
   clube.cutBox(3, 100, 11, 30, 3, 180);
   clube.setColor(0, 0.8, 1, 0);
   clube.putEllipsoid(50, 10, 60, 22, 9, 20);
   clube.cutBox(3, 100, 11, 30, 3, 178);

   //campo
   clube.setColor(1, 1, 1, 0);
   clube.putBox(100, 180, 10, 11, 20, 21);
   clube.putBox(100, 180, 10, 11, 140, 141);
   clube.putBox(100, 101, 10, 11, 20, 140);
   clube.putBox(179, 180, 10, 11, 20, 140);
   clube.putBox(100, 180, 10, 11, 79, 81);
   clube.putBox(125, 155, 10, 11, 20, 40);
   clube.putBox(125, 155, 10, 11, 120, 140);
   //trave
   clube.putBox(130, 150, 20, 21, 20, 21);
   clube.putBox(130, 131, 11, 21, 20, 21);
   clube.putBox(150, 151, 11, 21, 20, 21);
   clube.putBox(130, 150, 20, 21, 140, 141);
   clube.putBox(130, 131, 11, 21, 140, 141);
   clube.putBox(150, 151, 11, 21, 140, 141);

   //circulo central
   clube.putcircunferencia(140, 10, 80, 10);

    //escada
    clube.setColor(0.9, 0.8, 0.5, 0);
    clube.putBox(75, 126, 1, 11, 184, 185);
    clube.putBox(76, 125, 1, 11, 185, 186);
    clube.putBox(75, 126, 1, 9, 186, 188);
    clube.putBox(75, 126, 1, 7, 188, 189);
    clube.putBox(74, 127, 1, 7, 189, 190);
    clube.putBox(71, 130, 1, 5, 190, 191);
    clube.putBox(70, 131, 1, 5, 191, 193);
    clube.putBox(68,133,1,3,193,195);
    clube.putBox(68, 70, 1, 3, 190,193);
    clube.putBox(131,133,1,3,190,193);


   clube.writeOFF("clube.off");
   clube.~Sculptor();
}

