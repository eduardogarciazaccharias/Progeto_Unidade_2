#ifndef ESCULTOR_CLUBE_H_INCLUDED
#define ESCULTOR_CLUBE_H_INCLUDED
#include "voxel_clube.h"
#include<string>

class Sculptor {
protected:
  Voxel ***v;    //matriz para os voxels
  int nx,ny,nz; // Dimensão
  float r,g,b,a; // cores
public:
  Sculptor(int _nx, int _ny, int _nz);   //construtor da classe
  ~Sculptor();   //destrutor
  void alocaRecurso();
  void setColor(float _r, float _g, float _b, float _a);  //define a cor de cada voxel
  void putVoxel(int x, int y, int z);   //ativa o voxel na posição indicada...fazendo isOn = true
  void cutVoxel(int x, int y, int z);    //desativa o voxel da posição...isOn = false
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);  //ativa os voxel no intervalo
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);  //desativa os voxel no intervalo
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);  //ativa os voxels que satisfazem a equação da esfera
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);   //desativa os voxels que satisfazem a equação da esfera
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);   //ativa os voxels que satisfazem a equação da elipse
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);   //desativa os voxels que satisfazem a equação da elipse
  void writeOFF(char filename[]);  //grava a escultura no arquivo OFF
  void putCilindrop(int xcenter, int zcenter, int alt, int radius);//novo metodo, cilindro de area e altura definida pelo programador.
  void putcircunferencia(int xcenter, int ycenter, int zcenter, int radius);
};


#endif // ESCULTOR_CLUBE_H_INCLUDED
