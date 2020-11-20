#include "voxel_clube.h"
#include "escultor_clube.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>


using namespace std;
Voxel ***v;
int nx, ny, nz;
float r, g, b, a;


Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;
   // r = g = b = a = 1;
    alocaRecurso();
}
Sculptor::~Sculptor()
{
    for(int i =0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            delete[] v[i][j];
        }
    }
    delete [] v;
}
void Sculptor::alocaRecurso()
{
    v= new Voxel**[nx];
    for(int i =0; i < nx; i++){
        v[i] = new Voxel*[ny];
    }
    for(int i =0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                v[i][j][k].isOn = false;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
            }
        }
    }
}
void Sculptor::setColor(float _r, float _g, float _b, float _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}
void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}
void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = false;
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    if(x0 > x1){
        int tmp = x0;
        x1 = x0;         // implementar uma função troca;
        x0 = tmp;
    }
    if(y0 > y1){
        int tmp = y0;
        y1 = y0;         // implementar uma função troca;
        y0 = tmp;
    }
    if(z0 > z1){
        int tmp = z0;
        z1 = z0;         // implementar uma função troca;
        z0 = tmp;
    }
    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k < z1; k++){
                v[i][j][k].isOn = true;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    if(x0 > x1){
        int tmp = x0;
        x1 = x0;         // implementar uma função troca;
        x0 = tmp;
    }
    if(y0 > y1){
        int tmp = y0;
        y1 = y0;         // implementar uma função troca;
        y0 = tmp;
    }
    if(z0 > z1){
        int tmp = z0;
        z1 = z0;         // implementar uma função troca;
        z0 = tmp;
    }
    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k < z1; k++){
                v[i][j][k].isOn = false;
            }
        }
    }
}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                float d = sqrt(pow(xcenter - i,2) + pow(ycenter - j,2) + pow(zcenter - k,2));
                if(xcenter < 0 || xcenter > nx || ycenter < 0 || ycenter > ny || zcenter < 0 || zcenter > nz)
                {

                }else if(d <= radius)
                {
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;

                }
            }
        }
    }
}
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                float d = sqrt(pow(xcenter - i,2) + pow(ycenter - j,2) + pow(zcenter - k,2));
                if(xcenter < 0 || xcenter > nx || ycenter < 0 || ycenter > ny || zcenter < 0 || zcenter > nz)
                {

                }else if(d <= radius)
                {
                    v[i][j][k].isOn = false;

                }
            }
        }
    }
}
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(xcenter < 0 || xcenter > nx || ycenter < 0 || ycenter > ny || zcenter < 0 || zcenter > nz)
                {

                }else if((pow(i - xcenter,2)/pow(rx,2) + pow(j - ycenter,2)/pow(ry,2) + pow(k - zcenter,2)/pow(rz,2))<= 1)
                {
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;

                }
            }
        }
    }
}
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(xcenter < 0 || xcenter > nx || ycenter < 0 || ycenter > ny || zcenter < 0 || zcenter > nz)
                {

                }else if((pow(i - xcenter,2)/pow(rx,2) + pow(j - ycenter,2)/pow(ry,2) + pow(k - zcenter,2)/pow(rz,2))<= 1)
                {
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void Sculptor::writeOFF(char filename[] )
{
   // int tam=strlen(filename);
   // char format[]={'.', 'O', 'F', 'F', '\0'};
    ofstream saida;
   // for(int i=0; i<=strlen(format); i++){
     //   filename[tam+i]=format[i];
   // }
    saida.open(filename);
  //  if(!saida.is_open())
    //    return;
    saida << "OFF" << endl;
    int cont = 0;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn == true){
                    cont++;
                }
            }
        }
    }
    saida << 8*cont << " " << 6*cont << " 0\n";
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn == true){
                    saida << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << " " <<endl;
                    saida << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << " " <<endl;
                    saida << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << " " <<endl;
                    saida << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << " " <<endl;
                    saida << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << " " <<endl;
                    saida << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << " " <<endl;
                    saida << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << " " <<endl;
                    saida << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << " " <<endl;

                }
            }
        }
    }
    int aux = 0;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn == true){
                    saida << fixed;
                    saida << 4 << " " << 0+aux << " " << 3+aux << " " << 2+aux << " " << 1+aux << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a <<endl;
                    saida << 4 << " " << 4+aux << " " << 5+aux << " " << 6+aux << " " << 7+aux << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a <<endl;;
                    saida << 4 << " " << 0+aux << " " << 1+aux << " " << 5+aux << " " << 4+aux << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a <<endl;;
                    saida << 4 << " " << 0+aux << " " << 4+aux << " " << 7+aux << " " << 3+aux << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a <<endl;;
                    saida << 4 << " " << 3+aux << " " << 7+aux << " " << 6+aux << " " << 2+aux << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a <<endl;;
                    saida << 4 << " " << 1+aux << " " << 2+aux << " " << 6+aux << " " << 5+aux << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a <<endl;;
                    aux = aux+8;
                }
            }
        }
    }
    saida.close();
}

void Sculptor::putCilindrop(int xcenter, int zcenter, int alt, int radius)
{
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < alt; j++){
            for(int k = 0; k < nz; k++){
                float d = sqrt(pow(xcenter - i,2) + pow(zcenter - k,2));
                if(xcenter < 0 || xcenter > nx || zcenter < 0 || zcenter > nz)
                {

                }else if(d <= radius)
                {
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;

                }
            }
        }
    }
}
void Sculptor::putcircunferencia(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = 0; i < nx; i++){
        for(int j = ycenter; j < ycenter+1; j++){
            for(int k = 0; k < nz; k++){
                float d = sqrt(pow(xcenter - i,2) + pow(zcenter - k,2));
                if(xcenter < 0 || xcenter > nx || zcenter < 0 || zcenter > nz)
                {

                }else if(d <= radius)
                {
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;

                }
            }
        }
    }
}
