#include <GL/glut.h>

#define TORSO_HEIGHT 5.0
#define UPPER_ARM_HEIGHT 1.8
#define LOWER_ARM_HEIGHT 2.0
#define UPPER_LEG_RADIUS  0.5
#define LOWER_LEG_RADIUS  0.5
#define LOWER_LEG_HEIGHT 2.0
#define UPPER_LEG_HEIGHT 3.0
#define UPPER_LEG_RADIUS  0.5
#define TORSO_RADIUS 1.0
#define UPPER_ARM_RADIUS  0.2
#define LOWER_ARM_RADIUS  0.5
#define HEAD_HEIGHT 1.5
#define HEAD_RADIUS 1.0

typedef float point[3];

static GLfloat theta[12] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0,180.0,0.0,180.0,0.0,0.0 }; /* initial joint angles */
static GLint angle = 2;

GLUquadric *t, *h, *lua, *lla, *rua, *rla, *lll, *rll, *rul, *lul;
GLUquadric *joints, *armL_middle_joint, *armR_joint, *armR_middle_joint, *legL_joint, *legL_middle_joint, *legR_joint, *legR_middle_joint;
double size = 1.0;

void torso()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(t, TORSO_RADIUS, TORSO_RADIUS, TORSO_HEIGHT, 10, 10);
	glPopMatrix();

}

void Torso(GLfloat a, GLfloat b, GLfloat c)
{
	glPushMatrix();

	//	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glScalef(0.4, 1.0, 0.5);
	glutSolidCube(TORSO_HEIGHT);
	glPopMatrix();
}

void head()
{
	glPushMatrix();
	glTranslatef(0.0, 0.5*HEAD_HEIGHT, 0.0);
	glScalef(HEAD_RADIUS, HEAD_HEIGHT, HEAD_RADIUS);
	gluSphere(h, 1.0, 10, 10);
	glPopMatrix();
}

void joint()
{
	glPushMatrix();
	gluSphere(joints, 0.5, 10, 10);
	glPopMatrix();
}

void left_upper_arm()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);

	gluCylinder(lua, UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT, 10, 10);

	glPopMatrix();
}

void left_lower_arm()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(lla, LOWER_ARM_RADIUS - 0.1, LOWER_ARM_RADIUS - 0.1, LOWER_ARM_HEIGHT, 10, 10);
	glPopMatrix();
}

void right_upper_arm()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(rua, UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT, 10, 10);
	glPopMatrix();
}

void right_lower_arm()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(rla, LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT, 10, 10);
	glPopMatrix();
}

void left_upper_leg()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(lul, UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT, 10, 10);
	glPopMatrix();
}

void left_lower_leg()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(lll, LOWER_LEG_RADIUS - 0.1, LOWER_LEG_RADIUS - 0.1, LOWER_LEG_HEIGHT, 10, 10);
	glPopMatrix();
}

void right_upper_leg()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(rul, UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT, 10, 10);
	glPopMatrix();
}

void right_lower_leg()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(rll, LOWER_LEG_RADIUS - 0.1, LOWER_LEG_RADIUS - 0.1, LOWER_LEG_HEIGHT, 10, 10);
	glPopMatrix();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.0, 0.0, 0.0);


	glRotatef(theta[0], 0.0, 1.0, 0.0);

	glPushMatrix();


	glRotatef(theta[11], 2.0, 0.0, 0.0);


	{
		glPushMatrix();
		glTranslatef(0.0, 2.0, 0.0);
		Torso(TORSO_RADIUS * 2, TORSO_HEIGHT, TORSO_RADIUS * 2);
		glTranslatef(0.0, -2.0, 0.0);
		glPushMatrix();
	}

	{
		glPushMatrix();
		glTranslatef(0.0, 0.5 + TORSO_HEIGHT + 0.5*HEAD_HEIGHT, 0.0);
		glRotatef(theta[1], 1.0, 0.0, 0.0);
		glRotatef(theta[2], 0.0, 1.0, 0.0);
		glTranslatef(0.0, -0.5*HEAD_HEIGHT, 0.0);
		head();
		glPopMatrix();
	}

	{
		glPushMatrix();

		glTranslatef(-(TORSO_RADIUS + 0.45), TORSO_HEIGHT - 0.8, 0.0);
		joint();
		glTranslatef(TORSO_RADIUS + 0.45, -TORSO_HEIGHT + 0.8, 0.0);

		glTranslatef(TORSO_RADIUS + 0.45, TORSO_HEIGHT - 0.8, 0.0);
		joint();
		glTranslatef(-(TORSO_RADIUS + 0.45), -(TORSO_HEIGHT - 0.8), 0.0);

		glTranslatef(-TORSO_RADIUS - 0.45, 0.0 + 0.3, 0.0);
		joint();
		glTranslatef(TORSO_RADIUS + 0.45, 0.0 - 0.3, 0.0);

		glTranslatef(TORSO_RADIUS + 0.45, 0.0 + 0.3, 0.0);
		joint();

		glPopMatrix();
	}



	{
		glPushMatrix();
		glTranslatef(-(TORSO_RADIUS + 0.45), TORSO_HEIGHT - 0.8, 0.0);
		glRotatef(theta[3], 1.0, 0.0, 0.0);
		left_upper_arm();

	}

	{
		glTranslatef(0.0, UPPER_ARM_HEIGHT, 0.0);
		glRotatef(theta[4], 1.0, 0.0, 0.0);
		left_lower_arm();
		joint();
		glPopMatrix();
	}

	{
		glPushMatrix();
		glTranslatef((TORSO_RADIUS + 0.45), TORSO_HEIGHT - 0.8, 0.0);
		glRotatef(theta[5], 1.0, 0.0, 0.0);
		right_upper_arm();
	}

	{
		glTranslatef(0.0, UPPER_ARM_HEIGHT, 0.0);
		glRotatef(theta[6], 1.0, 0.0, 0.0);
		right_lower_arm();
		joint();
		glPopMatrix();
	}


	glPopMatrix();


	{
		glPushMatrix();
		glTranslatef(-(TORSO_RADIUS + UPPER_LEG_RADIUS), 0.1*UPPER_LEG_HEIGHT, 0.0);
		glRotatef(theta[7], 1.0, 0.0, 0.0);

		left_upper_leg();
	}

	{
		glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
		glRotatef(theta[8], 1.0, 0.0, 0.0);
		joint();
		left_lower_leg();
		glPopMatrix();
	}
	{
		glPushMatrix();
		glTranslatef(TORSO_RADIUS + UPPER_LEG_RADIUS, 0.1*UPPER_LEG_HEIGHT, 0.0);
		glRotatef(theta[9], 1.0, 0.0, 0.0);
		right_upper_leg();
	}

	{
		glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
		glRotatef(theta[10], 1.0, 0.0, 0.0);
		joint();
		right_lower_leg();
		glPopMatrix();
	}



	glFlush();
	glutSwapBuffers();
}



void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		theta[angle] += 5.0;
		if (theta[angle] > 360.0) theta[angle] -= 360.0;
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		theta[angle] -= 5.0;
		if (theta[angle] < 360.0) theta[angle] += 360.0;
	}
	display();
}

void menu(int id)
{
	if (id < 12) angle = id;
	if (id == 12) exit(0);
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-10.0, 10.0, -10.0 * (GLfloat)h / (GLfloat)w,
			10.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-10.0 * (GLfloat)w / (GLfloat)h,
			10.0 * (GLfloat)w / (GLfloat)h, 0.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myinit()
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess = { 100.0 };
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 10.0, 10.0, 10.0, 0.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GLUT_MULTISAMPLE);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);

	/* allocate quadrics with filled drawing style */

	joints = gluNewQuadric();
	gluQuadricDrawStyle(joints, GLU_FILL);
	armL_middle_joint = gluNewQuadric();
	gluQuadricDrawStyle(armL_middle_joint, GLU_FILL);

	h = gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	t = gluNewQuadric();
	gluQuadricDrawStyle(t, GLU_FILL);
	lua = gluNewQuadric();
	gluQuadricDrawStyle(lua, GLU_FILL);
	lla = gluNewQuadric();
	gluQuadricDrawStyle(lla, GLU_FILL);
	rua = gluNewQuadric();
	gluQuadricDrawStyle(rua, GLU_FILL);
	rla = gluNewQuadric();
	gluQuadricDrawStyle(rla, GLU_FILL);
	lul = gluNewQuadric();
	gluQuadricDrawStyle(lul, GLU_FILL);
	lll = gluNewQuadric();
	gluQuadricDrawStyle(lll, GLU_FILL);
	rul = gluNewQuadric();
	gluQuadricDrawStyle(rul, GLU_FILL);
	rll = gluNewQuadric();
	gluQuadricDrawStyle(rll, GLU_FILL);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case ' ':
		theta[0] += 5.0;
		display();
		break;
	case '7':
		theta[1] += 5.0;
		display();
		break;
	case '9':
		theta[2] -= 5.0;
		display();
		break;
	case '4':
		theta[3] -= 5.0;
		display();
		break;
	case '6':
		theta[4] += 5.0;
		display();
		break;
	case '1':
		theta[5] -= 5.0;
		display();
		break;
	case '3':
		theta[6] += 5.0;
		display();
		break;
	case 'q':
		theta[7] -= 5.0;
		display();
		break;
	case 'Q': 
		theta[9] += 5.0;
		display();
		break;
	case 'e':
		theta[10] += 5.0;
		display();
		break;
	default:

		break;
	}
}


void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("robot");


	myinit();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);

	glutKeyboardFunc(keyboard);



	glutCreateMenu(menu);
	glutAddMenuEntry("overview", 0);
	glutAddMenuEntry("head1", 1);
	glutAddMenuEntry("head2", 2);
	glutAddMenuEntry("right_upper_arm", 3);
	glutAddMenuEntry("right_lower_arm", 4);
	glutAddMenuEntry("left_upper_arm", 5);
	glutAddMenuEntry("left_lower_arm", 6);
	glutAddMenuEntry("right_upper_leg", 7);
	glutAddMenuEntry("right_lower_leg", 8);
	glutAddMenuEntry("left_upper_leg", 9);
	glutAddMenuEntry("left_lower_leg", 10);
	glutAddMenuEntry("torso", 11);
	glutAddMenuEntry("quit", 12);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);

	glutMainLoop();
}