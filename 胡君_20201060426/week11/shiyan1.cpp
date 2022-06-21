#include <stdlib.h>  
#include <GL/glut.h>  
#include<iostream>
#pragma comment(lib, "glut32.lib")  
using namespace std;
GLfloat roate = 0.0;// set rote of roate ying yu bu hao  bu zhuang le 设置旋转速率
GLfloat rote = 0.0;//shezhi旋转角度
GLfloat anglex = 0.0;//X 轴旋转
GLfloat angley = 0.0;//Y 轴旋转
GLfloat anglez = 0.0;//Z 轴旋转
GLint WinW = 200;
GLint WinH = 200;
GLfloat oldx;//当左键按下时记录鼠标坐标  
GLfloat oldy;
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0); //背景黑色  
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0); //画笔红色
	glLoadIdentity();  //加载单位矩阵  
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(rote, 0.0f, 1.0f, 0.0f);
	glRotatef(anglex, 1.0, 0.0, 0.0);
	glRotatef(angley, 0.0, 1.0, 0.0);
	glRotatef(anglez, 0.0, 0.0, 1.0);
	glutWireTeapot(2);
	rote += roate;
	//glRotatef(angle, 0.0, 1.0, 0.0);
	//angle += 1.0f;
	glutSwapBuffers();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			roate = 0;
			rote = 0;
			oldx = x;//当左键按下时记录鼠标坐标  
			oldy = y;
			cout << "left" << endl;
		}

	}
	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			roate += 1.0f;
			cout << "right" << endl;
		}

	}

}
void motion(int x, int y)
{
	GLint deltax = oldx - x;
	GLint deltay = oldy - y;
	anglex += 360 * (GLfloat)deltax / (GLfloat)WinW;//根据屏幕上鼠标滑动的距离来设置旋转的角度  
	angley += 360 * (GLfloat)deltay / (GLfloat)WinH;
	anglez += 360 * (GLfloat)deltay / (GLfloat)WinH;
	oldx = x;//记录此时的鼠标坐标，更新鼠标坐标  
	oldy = y;//若是没有这两句语句，滑动是旋转会变得不可控  
	glutPostRedisplay();
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<GL/glut.h>
#include<stdio.h>
GLsizei winWidth = 500, winHeight = 500;
char sixel;
float thera = 0;
float x = 0, y = 0, z = 0;
void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
}


void displayWirePolyhedra(float x, float y, float z, float thera) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(1.0, 2.0, 0.0);//下一个图形坐标
	glutSolidTeapot(1.5);
	//glutWireTeapot(1.5);//放大倍数
	glScalef(1.0, 1.0, 1.0);//缩放比
	glTranslatef(-1.0, -5.0, 0.0);//下一个图形坐标

	glRotatef(thera, x, y, z);
	glutWireTeapot(1.5);
	//glutSolidTeapot(2.0);
	glFlush();
}

void display() {

	displayWirePolyhedra(x, y, z, thera);
}	

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("胡君20201060426");
	init();
	printf("请选择绕拿一个轴旋转x,y,z \n");
	scanf("%c", &sixel);
	getchar();
	if (sixel == 'x') {
		x = 1.0;
		y = 0.0;
		z = 0.0;
		printf("请输入旋转的角度\n");
		scanf("%f", &thera);
	}
	else if (sixel == 'y') {
		x = 0.0;
		y = 1.0;
		z = 0.0;
		printf("请输入旋转的角度\n");
		scanf("%f", &thera);
	}
	else if (sixel == 'z') {
		x = 0.0;
		y = 0.0;
		z = 1.0;
		printf("请输入旋转的角度\n");
		scanf("%f", &thera);
	}
	else {
		printf("输入有误\n");
	}
	glutDisplayFunc(display);
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();
}
