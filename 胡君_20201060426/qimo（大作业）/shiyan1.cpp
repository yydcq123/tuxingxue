#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glaux.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>
#define PI 3.14159265358979323846
GLfloat  corner=0.0;
GLUquadricObj* qobj;
GLuint texName;
GLuint flag=1;
GLfloat bracket_diffuseCoeff[]={0.53, 0.37, 0.10, 1.0};
GLfloat bracket_specularCoeff[]={0.53, 0.37, 0.10, 1.0};
GLfloat bracket_surfEmissionCoeff[]={0.2, 0.2, 0.2, 1.0};
GLfloat underpan_diffuseCoeff[]={0.5, 0.5, 0.0, 1.0};
GLfloat underpan_specularCoeff[]={0.5, 0.5, 0.0, 1.0};
GLfloat underpan_surfEmissionCoeff[]={0.2, 0.2, 0.2, 1.0};
    GLfloat shininess[]={50.0};
    void draw_semi_circle(float r)             //中心在(x,y,0)，半径为r的圆
{
   float angle;
   glBegin(GL_LINE_STRIP);
   for(angle = 2*PI; angle >= PI; angle -= PI/360)
   {
      glVertex3f(r*cos(angle),r*sin(angle),0);
   }
   glEnd();   
}
   void  draw_salver(float x, float y, float a, float b)   //中心在(x,y,0)，长半轴为a，短半轴为b的椭圆
{
   float angle;
   glTranslatef(x,y,0);
   glBegin(GL_TRIANGLE_FAN);
   glVertex3f(0,0,0);   
   for(angle = 2*PI; angle >= 0; angle -= PI/360)
   {
      glVertex3f(a*cos(angle),b*sin(angle),0);
   }
   glEnd();   
}
    void draw_tellurion()    //地球仪
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
    glLoadIdentity();
    glPushMatrix();//保存当前位置
	GLfloat light0_ambient[] = { 0.3, 0.4, 0.6, 0};
    GLfloat light0_diffuse[] = { 0.5, 0.4, 0.4, 0 };
    GLfloat light0_specular[] = { 0.5, 0.5, 0.5, 0 };
    GLfloat light0_position[] = { 1, 1, 1, 0 };   
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);   
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);   
    glPopMatrix();	//恢复保存的位置和角度
	glPushMatrix();
    GLfloat light1_diffuse[] = { 0.3, 1, 0, 0 };
    GLfloat light1_position[] = {0.8, 1, 0.4, 0 };   
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);  
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);   
    glPopMatrix();	
	glPushMatrix();
    GLfloat light2_diffuse[] = { 1, 0.2, 0, 1 };
    GLfloat light2_position[] = {0.5, 0.2, 1, 1 };   
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);  
    glLightfv(GL_LIGHT2, GL_POSITION, light2_position);   
    glPopMatrix();	
	glPushMatrix();
    GLfloat light3_diffuse[] = { 0.1, 0.8, 0, 1 };
    GLfloat light3_position[] = {0.5, 0.2, 1, 1 };   
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT3);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, light3_diffuse);  
    glLightfv(GL_LIGHT3, GL_POSITION, light3_position);   
    glPopMatrix();	
	glPushMatrix();
    GLfloat light4_diffuse[] = { 0, 1, 0, 1 };
    GLfloat light4_position[] = {-0.5, -0.2, -1, 1 };   
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT4);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, light4_diffuse);  
    glLightfv(GL_LIGHT4, GL_POSITION, light4_position);   
    glPopMatrix();	
	glPushMatrix();
    GLfloat light5_diffuse[] = { 0.4, 0.8, 1, 0 };
    GLfloat light5_position[] = {-0.5, 0.2, 1, 0 };   
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT5);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, light5_diffuse);  
    glLightfv(GL_LIGHT5, GL_POSITION, light5_position);   
    glPopMatrix();	
	glPushMatrix();
    GLfloat light6_diffuse[] = { 1, 0.3,1, 1 };
    GLfloat light6_position[] = {-0.5, 0.2, 1, 0 };   
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT6);
    glLightfv(GL_LIGHT6, GL_DIFFUSE, light6_diffuse);  
    glLightfv(GL_LIGHT6, GL_POSITION, light6_position);   
    glPopMatrix();	
	glPushMatrix();
    GLfloat light7_diffuse[] = { 0.6, 0,0, 0 };
    GLfloat light7_position[] = {0.5, -0.2, -1, 0 };   
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT7);
    glLightfv(GL_LIGHT7, GL_DIFFUSE, light7_diffuse);  
    glLightfv(GL_LIGHT7, GL_POSITION, light7_position);   
    glPopMatrix();	
    //画球体
	glPushMatrix();  //保存当前位置
	glTranslatef(0,-0.14,0);
    glBindTexture(GL_TEXTURE_2D,texName);   //绑定纹理
	glEnable(GL_TEXTURE_2D);//打开纹理映射开关
	gluQuadricTexture(qobj,GL_TRUE);  //启用该二次曲面的纹理
    glRotatef(-90.0f,1.0f,0.0f,0.0f);
	glRotatef(66.3f,0.0f,0.0f,1.0f);
	glRotatef(-corner,0.0,-0.261,0.595);
	gluSphere(qobj,0.45,60,60);   //绘制球体
	glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    //画地球仪下方的托盘
	//材质属性的设置
	glPushMatrix();
	glTranslatef(0,-0.14,0);
	glScalef(0.8f, 0.8f, 0.8f);
glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,underpan_diffuseCoeff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, underpan_specularCoeff);
	glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,underpan_surfEmissionCoeff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glLineWidth(2.5);
    draw_salver(-0.322,-0.733,0.45,0.1);
    glPopMatrix();
    //画地球仪的支架——两部分：中轴、半园支架
    //画穿地球的轴
	//材质属性的设置
    glPushMatrix();
	glTranslatef(0,-0.14,0);
	glScalef(0.8f, 0.8f, 0.8f);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,bracket_diffuseCoeff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, bracket_specularCoeff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, bracket_surfEmissionCoeff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    glLineWidth(4.5);
	glBegin(GL_LINES);
	glVertex3f(-0.322,-0.733,0.0);
	glVertex3f(0.261,0.595,0.0);
	glEnd();
	//画地球仪外边的半园支架
	glRotatef(66.3f,0.0f,0.0f,1.0f);
	glLineWidth(6.5);
	draw_semi_circle(0.65);
	glPopMatrix();
	glutSwapBuffers();  //绘图时使用双缓存
}
void init()
{  
   AUX_RGBImageRec *TextureImage[1];//创建纹理储存空间
   glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);//用于控制多边形的显示方式,显示模式将适用于物体的所有面,多边形采用填充形式
   glGenTextures(1,&texName);   //生成纹理对象名
   //创建nearest滤波贴图
   glBindTexture(GL_TEXTURE_2D,texName);//将对象名赋给二维纹理图案
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);//线性插值得到纹理数据，当屏幕像素分辨率高于纹理图案像素分辨率时要放大纹理图案
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);//线性插值得到纹理数据，当屏幕像素分辨率低于纹理图案像素分辨率时要缩减纹理图案
   memset(TextureImage,0,sizeof(void *)*1);  
   //加载BMP纹理图，首先用OpenGL辅助库获得位图信息，然后建立纹理
   if(TextureImage[0]=auxDIBImageLoad("worldmap.bmp"))   //map41.bmp
   {
	glTexImage2D(GL_TEXTURE_2D,0,3,TextureImage[0]->sizeX,TextureImage[0]->sizeY,0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
   }
   qobj=gluNewQuadric();   //qobj指定一个二次曲面,创建二次曲面对象 
   glClearDepth(1.0f);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);//指定用于深度缓冲比较值。如果输入的深度值小于或等于参考值，则通过
   glClearColor(1, 1, 1, 1);     //设置背景色
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity(); 
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 
}
void Moving()      //地球旋转
{
	if(flag==1)
	{
		corner+=0.25f;
	    glutPostRedisplay();    //在图像绘制的所有操作之后，要加入 glutPostRedisplay()来重绘图像
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);//对glut进行初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//设定窗口的缓存和颜色模型
    glutInitWindowSize(600,600);//设定显示窗口的宽度和高度的像素数
    glutInitWindowPosition(100,100);//初始化窗口显示位置，显示窗口左上角的位置
    glutCreateWindow("胡君20201060426");//创建窗口
    glutDisplayFunc(draw_tellurion);//调用draw_tellurion函数显示图像
	glutIdleFunc(Moving);//设置空闲回调函数，当CPU空闲时调用该函数
    init(); 
	glutMainLoop();//使程序进入事件处理循环，进行一个消息循环
	return 0;
}
