#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
GLfloat theta[3]={0.0,0.0,0.0};
int axis=2;
GLdouble viw[]={0.0,0.0,5.0};
GLfloat ver[][3]={{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};
GLfloat col[][3]={{1.0,1.0,1.0},{1.0,1.0,0.0},{1.0,0.0,1.0},{1.0,0.0,0.0},{0.0,1.0,1.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.5,0.5,0.5}};

void poly(int a,int b,int c,int d)
{
    glBegin(GL_POLYGON);
    glColor3fv(col[a]);
    glVertex3fv(ver[a]);
    glColor3fv(col[b]);
    glVertex3fv(ver[b]);
    glColor3fv(col[c]);
    glVertex3fv(ver[c]);
    glColor3fv(col[d]);
    glVertex3fv(ver[d]);
    glEnd();
}
void colorcube()
{
    poly(0,3,2,1);
    poly(2,3,7,6);
    poly(0,4,7,3);
    poly(1,2,6,5);
    poly(4,5,6,7);
    poly(0,1,5,4);

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(viw[0],viw[1],viw[2],0.0,0.0,0.0,0.0,1.0,0.0);
    //if(ax==0)
    glRotatef(theta[0],1.0,0.0,0.0);
    //if(ax==1)
    glRotatef(theta[1],0.0,1.0,0.0);
    //if(ax==2)
    glRotatef(theta[2],0.0,0.0,1.0);
    colorcube();
    glFlush();
    glutSwapBuffers();
}

void keys(unsigned char key,int x,int y)
{
    if(key=='x') viw[0]-=1.0;
    if(key=='X') viw[0]+=1.0;
    if(key=='y') viw[1]-=1.0;
    if(key=='Y') viw[1]+=1.0;
    if(key=='z') viw[2]-=1.0;
    if(key=='Z') viw[2]+=1.0;
    display();
}
void mouse(int btn,int state,int x,int y)
{
    if(btn==GLUT_LEFT_BUTTON&& state==GLUT_DOWN) axis=0;
    if(btn==GLUT_MIDDLE_BUTTON&& state==GLUT_DOWN) axis=1;
    if(btn==GLUT_RIGHT_BUTTON&& state==GLUT_DOWN) axis=2;

    theta[axis]+=2.0;
    if(theta[axis]>=360.0)
        theta[axis]-=360.0;
    display();
}
void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glFrustum(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,2.0,20.0);
    else
         glFrustum(-2.0,2.0,-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,2.0,20.0);
    glMatrixMode(GL_MODELVIEW);

}
void main(int argc,char **argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
   // glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Rotate");

    glutMouseFunc(mouse);
    glutKeyboardFunc(keys);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}

