#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<GL/glut.h>

GLfloat tr[3][3] = {{100.0,150.0,200.0},{100.0,150.0,100.0},{1.0,1.0,1.0}};
GLfloat rot_mat[3][3] = {{0},{0},{0}};
GLfloat res[3][3] = {{0},{0},{0}};
GLfloat h,k,theta,rad;
int ch;

void multiply()
{
    int i,j,l;
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    {
        res[i][j] = 0;
        for(l=0;l<3;l++)
        res[i][j] = res[i][j]+rot_mat[i][l]*tr[l][j];
    }
}


void rotate()
{
    GLfloat m,n;
    m = -h*(cos(theta)-1) + k*(sin(theta));
    n = -k*(cos(theta)-1) - h*(sin(theta));
    rot_mat[0][0] = cos(theta);
    rot_mat[0][1] = -sin(theta);
    rot_mat[0][2] = m;
    rot_mat[1][0] = sin(theta);
    rot_mat[1][1] = cos(theta);
    rot_mat[1][2] = n;
    rot_mat[2][0] = 0;
    rot_mat[2][1] = 0;
    rot_mat[2][2] = 1;
    multiply();
}


void draw(GLfloat mat[3][3])
{
    glBegin(GL_TRIANGLES);
    glVertex2f(mat[0][0],mat[1][0]);
    glVertex2f(mat[0][1],mat[1][1]);
    glVertex2f(mat[0][2],mat[1][2]);
    glEnd();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    theta = rad;
    glColor3f(1.0,1.0,0.0);
    draw(tr);
    if(ch==1)
    {
        h=100;
        k=100;
        rotate();
        glColor3f(1.0,0.0,0.0);
    }

    if(ch==2)
    {
        h=k=0;
        rotate();
        glColor3f(1.0,0.0,1.0);
    }
    draw(res);
    glFlush();
}

void myinit()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(1,1,1);
    gluOrtho2D(-500.0,500.0,-500.0,500.0);
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    printf("enter choice: ---------1. for about pivot point\t 2.about origin\n");
    scanf("%d",&ch);
    printf("enter value of theta:\n");
    scanf("%f",&theta);
    rad = (3.14*theta)/180;
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1024,1024);
    glutCreateWindow("rotation of triangle");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}


