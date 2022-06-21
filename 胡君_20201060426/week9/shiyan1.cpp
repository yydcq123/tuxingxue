#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>


void display()
{

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-1, 0, -10);
    glColor3f(1, 0, 0);
    glutWireCube(1);

    glTranslatef(3, 0, 0);
    glColor3f(0, 1, 0);
    glutWireCube(1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-1, 0, -10);
    glColor3f(1, 0, 0);
    glutWireCube(1);

    glScalef(1.5, 1.5, 1.5);
    glColor3f(0, 1, 0);
    glutWireCube(1);

    //opengl三维旋转(绕平行于坐标轴的轴旋转)
//此例为原点绕经过(0,0,-5)垂直于xz平面的旋转轴进行旋转
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //为了方便查看效果，将整体向z轴负向平移10个单位
    glTranslatef(0, 0, -10);
    for (int i = 0; i < 18; i++)
    {
        //进行逆平移
        glTranslatef(0, 0, -5);
        //进行所需的旋转
        glRotatef(20, 0, 1, 0);
        //将坐标轴平移至与y轴重合
        glTranslatef(0, 0, 5);
        glColor3f(1, 0, 0);
        glutWireCube(1);
    }


    glFlush();
    glutSwapBuffers();
}
void init()
{
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 0, 100);
}
int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(400, 50);
    glutInitWindowSize(600, 600);
    glutCreateWindow("胡君20201060426");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

}
