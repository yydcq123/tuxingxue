#include <GL/glut.h>
#include <stdio.h>

static float rotAngle = 0.;

void init(void)
{
	GLfloat values[2];
	glGetFloatv(GL_LINE_WIDTH_GRANULARITY, values);
	printf("GL_LINE_WIDTH_GRANULARITY value is %3.1f\n", values[0]);

	glGetFloatv(GL_LINE_WIDTH_RANGE, values);
	printf("GL_LINE_WIDTH_RANGE values are %3.1f %3.1f\n", values[0], values[1]);

	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);

	glLineWidth(1.5);

	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(-rotAngle, 0.0, 0.0, 0.1);
	glBegin(GL_LINES);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glPopMatrix();

	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(rotAngle, 0.0, 0.0, 0.1);
	glBegin(GL_LINES);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();
	glPopMatrix();

	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluOrtho2D(-1.0, 1.0, -1.0 * (GLfloat)h / (GLfloat)w, 1.0 * (GLfloat)h / (GLfloat)w);
	else
		gluOrtho2D(-1.0 * (GLfloat)w / (GLfloat)h, 1.0 * (GLfloat)w / (GLfloat)h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'r': case 'R':
		rotAngle += 20.;
		if (rotAngle >= 360.0) rotAngle = 0.0;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 300);
	glutCreateWindow("胡君20201060426");
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
