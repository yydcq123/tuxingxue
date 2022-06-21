#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include <gl/glut.h>
#include <math.h>


const int n = 20;
const GLfloat R = 0.3f;
const GLfloat Pi = 3.1415926536f;

//控制变量说明
float parallelogram_X = 0.0, parallelogram_Y = 0.0; //蓝色四边形的坐标参数

//画圆
void MyDisplay()
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++)
		glVertex2f(R * cos(2 * Pi / n * i), R * sin(2 * Pi / n * i));
	glEnd();
	glFlush();
}

//画三角
void CALLBACK display(void)
{
	glBegin(GL_TRIANGLE_STRIP);//画连续填充的多个三角 
	glColor3f(1.0, 0.6, 0.0);
	glVertex3f(0.50, 0.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.50, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.50, 0.50);
	//第一个三角 

	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(0.30, 0.50, -0.50);
	//第二个三角 

	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.50, 0.0, 0.0);
	//第三个三角 

	glEnd();
	glFlush();
}
//三维平行四边形2绘制函数：中心位于坐标原点
void parallelogram2()
{
	glBegin(GL_QUADS);
	glVertex3f(-0.3, -0.2, -0.3);
	glVertex3f(0.3, -0.3, 0.3);
	glVertex3f(0.3, 0.3, 0.3);
	glVertex3f(-0.3, 0.4, -0.3);
	glEnd();
}

//图形绘制函数
void Display(void)
{
	//清除屏幕颜色及深度缓冲器
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//启用深度测试
	glEnable(GL_DEPTH_TEST);

	//绘制第一个红色平行四边形
	//glColor3f(1.0f,0.0f,1.0f);       //设置平行四边形绘制颜色
	glLoadIdentity();	            //设置当前矩阵为单位矩阵
	glTranslatef(0.0f, 0.0f, 0.0f); //平移绘制位置
	//parallelogram1();
	display();

	//绘制第二个蓝色平行四边形，同红色四边形交叉
	glColor3f(1.0f, 1.0f, 0.0f);        //设置平行四边形绘制颜色
	glLoadIdentity();	            //设置当前矩阵为单位矩阵
	glTranslatef(parallelogram_X, parallelogram_Y, 0.0); //平移绘制位置
	parallelogram2();
	//MyDisplay();//绘制四边形

	//交换缓冲器，完成物体绘制
	glutSwapBuffers();
}

//键盘响应函数,改变蓝色四边形的坐标位置
void key(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd':
		parallelogram_X += 0.05;//增加x
		glutPostRedisplay();
		break;
	case 'a':
		parallelogram_X -= 0.05;//减小x
		glutPostRedisplay();
		break;
	case 'w':
		parallelogram_Y += 0.05;//增加y
		glutPostRedisplay();
		break;
	case 's':
		parallelogram_Y -= 0.05;//减小y
		glutPostRedisplay();
		break;
	case '\033':
		break;
	default:
		break;
	}
}
void main(int argc, char* argv[])
{
	//glut初始化函数
	glutInit(&argc, argv);
	//设置初始显示模式
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	//初始化窗口起始位置
	glutInitWindowPosition(100, 100);
	//初始化窗口大小
	glutInitWindowSize(800, 800);
	//创建窗口
	glutCreateWindow("胡君20201060426");
	//调用键盘响应函数
	glutKeyboardFunc(key);
	//调用显示函数
	glutDisplayFunc(Display);

	glutMainLoop();

	return;
}

