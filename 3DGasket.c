#include <GL/glut.h>
#include<stdio.h>
GLfloat v[4][3]={{0.0,0.0,1.0},{0.0,0.94,-0.3333},{-0.816,-0.47,-0.33},{0.816,-0.47,-0.333}};
int n;

void triangle(GLfloat*a,GLfloat*b,GLfloat*c)
{
 glBegin(GL_POLYGON);
 glVertex3fv(a);
 glVertex3fv(b);
 glVertex3fv(c);
 glEnd();
 }
 void divide_triangle(GLfloat*a,GLfloat*b,GLfloat*c,int n)
 {
  GLfloat v1[3],v2[3],v3[3];
  int j;
  if(n>0)
  {
   for(j=0;j<3;j++) v1[j]=(a[j]+b[j])/2;
   for(j=0;j<3;j++) v2[j]=(a[j]+c[j])/2;
   for(j=0;j<3;j++) v3[j]=(b[j]+c[j])/2;
   divide_triangle(a,v1,v2,n-1);
   divide_triangle(c,v2,v3,n-1);
   divide_triangle(b,v3,v1,n-1);
  }
  else(triangle(a,b,c));
}
void tetrahedron(int n)
{
 glColor3f(1.0,0.0,0.0);
 divide_triangle(v[0],v[1],v[2],n);
 glColor3f(0.0,1.0,0.0);
 divide_triangle(v[3],v[2],v[1],n);
 glColor3f(0.0,0.0,1.0);
 divide_triangle(v[0],v[3],v[1],n);
 glColor3f(0.0,0.0,0.0);
 divide_triangle(v[0],v[2],v[3],n);

}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 tetrahedron(n);
 glFlush();
}
void myinit()
{
 glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0);
 glClearColor(1.0,1.0,1.0,1.0);
}
int main(int argc,char **argv)
{
 printf("No of divisions");
 scanf("%d",&n);
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
 glutInitWindowSize(500,500);
 glutCreateWindow("3D Gasket");
 glutDisplayFunc(display);
 myinit();
 glEnable(GL_DEPTH_TEST);
 glutMainLoop();
 }
