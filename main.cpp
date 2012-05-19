#include <cstdlib>
#include <iostream>
#include <conio2.h>
#include <math.h>
#include <cmath>
#include <GL/glut.h>

#define i 24

using namespace std;

int a, b, c, d;

void Init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,500.0,0.0,500.0);
}

inline GLint round(const GLfloat a) 
{
       return GLint(a+0.5);
}

void setPixel(int x, int y)
{
     glColor3f(0, 0, 0);
     glBegin(GL_POINTS);
     glVertex2f(x,y);
     glEnd(); 
     glFlush();
}

void garisDDA(int x1, int y1, int x2, int y2)
{
     int jml_langkah,k;
     float x_tambah,y_tambah,x=x1,y=y1;
     
     int deltaY = y2 - y1;
     int deltaX = x2 - x1;
        
     if (abs(deltaX) > abs(deltaY))
     {
           jml_langkah = abs(deltaX);
     }
     else
     if (abs(deltaX) < abs(deltaY))
     {
           jml_langkah = abs(deltaY);  
     }
     else
     {
           jml_langkah = 0;
     }
     
     x_tambah = (float) deltaX/ (float) jml_langkah;
     y_tambah = (float) deltaY/ (float) jml_langkah;
     
     setPixel(round(x), round(y));
     for(k=0; k<jml_langkah; k++)
     {
            x+=x_tambah;
            y+=y_tambah;
            setPixel(round(x), round(y));

     }
     glutSwapBuffers();
}

void garisBresenham(int x1, int y1, int x2, int y2)
{
     int jml_langkah,x,y,pk,k;
     
     int deltaX = x2 - x1;
     int deltaY = y2 - y1;
     
     int deltaX2 = deltaX * 2;
     int deltaY2 = deltaY * 2;
     
     int deltaY2MinDeltaX2 = deltaY2 - deltaX2;
     int p0 = deltaY2 - deltaX;
     jml_langkah = deltaX;
     
     if(x1>x2)
     {
          x=x2;
          y=y2;
          x2=x;
     }
     else
     {
         x=x1;
         y=y1;
     }
     setPixel(x, y);
     pk=p0;
     x=x-1;
     y=y-1;
     
     while(x<=x2){
                
     x++;
     
     if(pk<0)
     {
            pk +=deltaY2;
     }
     else
     {
            y++;           
            pk +=deltaY2MinDeltaX2;
     }
     setPixel(x,y);
     }
     glutSwapBuffers();
}  
     
     
     
void Display()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f (1.0, 0.0, 0.0);
     glPointSize(4.0);    
     garisDDA(a,b,c,d); 
     garisBresenham(a,b,c,d);    
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500, 500); 
    textbackground(WHITE);
    system("cls");
    
    int pil;
    
    do
    {
 
        textcolor(BLACK);
        gotoxy(i,7);cout<<" ================================ "<<endl;
        textcolor(RED);
        gotoxy(i,8);cout<<"|            M E N U             |"<<endl;
        textcolor(BLACK);
        gotoxy(i,9);cout<<" ================================ "<<endl;
        textcolor(RED);
        gotoxy(i,10);cout<<"| 1. Algoritma DDA               |"<<endl;
        gotoxy(i,11);cout<<"| 2. Bresenham                   |"<<endl;
        gotoxy(i,12);cout<<"| 3. Nama kelompok               |"<<endl;
        gotoxy(i,13);cout<<"| 4. Keluar                      |"<<endl;
        textcolor(BLACK);
        gotoxy(i,14);cout<<" ================================ "<<endl;
        textcolor(RED);
        gotoxy(i,15);cout<<"| Masukkan pilihan [1..4] :      |"<<endl;
        textcolor(BLACK);
        gotoxy(i,16);cout<<" ================================ "<<endl;
        textcolor(RED);
        gotoxy(52,15);cin>>pil;
        
        textcolor(RED);
        system("cls");
       
        if(pil==1)
        {                 
                  cout<<" Masukkan nilai x1 : ";cin>>a;
                  cout<<" Masukkan nilai y1 : ";cin>>b;
                  cout<<" Masukkan nilai x2 : ";cin>>c;
                  cout<<" Masukkan nilai y2 : ";cin>>d;
                  
                  glutCreateWindow("Algoritma DDA");
                  Init(); 
                  glutDisplayFunc(Display);
                  glutMainLoop();  
        }
        else
        if(pil==2)
        {
                  cout<<" Masukkan nilai x1 : ";cin>>a;
                  cout<<" Masukkan nilai y1 : ";cin>>b;
                  cout<<" Masukkan nilai x2 : ";cin>>c;
                  cout<<" Masukkan nilai y2 : ";cin>>d;
                  
                  glutCreateWindow("Bresenham");
                  Init(); 
                  glutDisplayFunc(Display);
                  glutMainLoop();  
        }
        else
        if(pil==3)
        {
                  textcolor(BLACK);
                  gotoxy(13,7);cout<<" ============================================================ "<<endl;
                  textcolor(RED);
                  gotoxy(13,8);cout<<"|                         NAMA KELOMPOK                      |"<<endl;
                  textcolor(BLACK);
                  gotoxy(13,9);cout<<" ============================================================ "<<endl;
                  textcolor(RED);
                  gotoxy(13,10);cout<<"|          N A M A               |           N I M           |"<<endl;
                  textcolor(BLACK);
                  gotoxy(13,11);cout<<" ============================================================ "<<endl;
                  textcolor(RED);
                  gotoxy(13,12);cout<<"| 1. Yulius Angga Etsa P         |          10108429         |"<<endl;
                  gotoxy(13,13);cout<<"| 2. Imam Ashadi                 |          10108436         |"<<endl;
                  gotoxy(13,14);cout<<"| 3. Ghea Ratimanjari            |          10108449         |"<<endl;
                  gotoxy(13,15);cout<<"| 4. R. Idham Aziz M             |          10108465         |"<<endl;
                  textcolor(BLACK);
                  gotoxy(13,16);cout<<" ============================================================ "<<endl;
                  
                  
                  cout<<endl<<endl<<endl;
        }
        else
        if(pil==4)
        {
                  gotoxy(20,12);cout<<" Terima kasih telah menggunakan program ini. "<<endl<<endl<<endl<<endl;
        }
        else
        {
                  gotoxy(33,12);cout<<" Anda salah pilih! "<<endl<<endl<<endl<<endl;
        }
    system("PAUSE");
    system("cls");
    }while(pil!=4);
     
                  
    
    return EXIT_SUCCESS;
}
