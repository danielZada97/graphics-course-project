
/*
Daniel Zada 318223278
Shachar Dalal 205799976
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GL/glut.h"
#include <stdbool.h>
#include <time.h>

// macros
#define LOAD_TEXTURE(texture_id, filename) texture_id = generateTextures(filename)
#define DSBRICK_TEXTURE "dsbrick.bmp"
#define BRICK_TEXTURE "brick.bmp"
#define SKY_TEXTURE "sky3.bmp"
#define GRASS_TEXTURE "grass1.bmp"
#define NIGHT_SKY_TEXTURE "nightsky.bmp"
#define WELCOME_TEXTURE "welcome.bmp"
#define NAMETAG_TEXTURE "nametag.bmp"
#define METAL_TEXTURE "metal.bmp"
#define WOOD_TEXTURE "wood1.bmp"
#define PLASTIC_TEXTURE "plastic.bmp"
#define ROPE_TEXTURE "rope.bmp"
#define METAL2_TEXTURE "metal2.bmp"
#define SUN_TEXTURE "sun.bmp"
#define EARTH_TEXTURE "earth.bmp"
#define MOON_TEXTURE "moon.bmp"
#define TREE_TOP_TEXTURE "tree_top.bmp"
#define TREE_TRUNK_TEXTURE "tree_trunk.bmp"
#define SAND_TEXTURE "sand.bmp"
#define PLANK_TEXTURE "plank.bmp"
#define ROBERTO_TEXTURE "roberto.bmp"
#define PLANK2_TEXTURE "plank2.bmp"
#define DOOR_TEXTURE "door2.bmp"
#define DOOR2_TEXTURE "door3.bmp"
#define OAK_WOOD_TEXTURE "oak_wood.bmp"
#define BIRCH_WOOD_TEXTURE "birch_wood.bmp"
#define STONE_TEXTURE "stone.bmp"
#define BODY_BACK_TEXTURE "body_back.bmp"
#define BODY_FRONT_TEXTURE "body_front.bmp"
#define HEAD_BACK_TEXTURE "head_back.bmp"
#define HEAD_RIGHT_TEXTURE "head_right.bmp"
#define HEAD_LEFT_TEXTURE "head_left.bmp"
#define FACE_FRONT_TEXTURE "face_front.bmp"
#define LEGS_TEXTURE "legs.bmp"
#define HANDS_TEXTURE "hands.bmp"
#define HEAD_TOP_TEXTURE "head_top.bmp"
#define HANDS_UP_TEXTURE "hands_up.bmp"
#define HANDS_DOWN_TEXTURE "hands_down.bmp"
#define BALL_TEXTURE "ball_texture.bmp"
#define SKY4_TEXTURE "sky4.bmp"
#define SKY5_TEXTURE "sky5.bmp"
#define AZAF_ID "Azaf.bmp"
//global constants
#define LIGHT1 11
#define LIGHT2 22
#define LIGHT3 33
#define LIGHT4 44
#define LIGHT5 55
#define ALL_LIGHTS 102
#define TEXTURES_ON 66
#define TEXTURES_OFF 77
#define DAY 88
#define NIGHT 99
#define DAY_CYCLE 1111
#define ANIMATIONS_ON 100
#define ANIMATIONS_OFF 101
#define MENU_EXIT 999
#define RESET 1000
#define ANIMATION_DELAY 20
#define PI 3.14
#define MeshSize 200
#define VANE_HEIGHT 2
#define UP true
#define DOWN false
#define FORWARD 0
#define BACKWARD 180
#define LEFT 90
#define RIGHT -90
#define DEFAULT -1
#define SKY_RIGHT 0
#define SKY_LEFT  1
#define SKY_UP    2
#define SKY_DOWN  3
#define SKY_BACK  4
#define SKY_FRONT 5
#define ROBERTO 987
#define AZAF 456
// Define macro for loading textures
#define LOAD_TEXTURES() \
    LOAD_TEXTURE(SkyboxTextures[0][SKY_RIGHT], SKY_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[0][SKY_LEFT], SKY_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[0][SKY_UP], SKY_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[0][SKY_DOWN], GRASS_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[0][SKY_BACK], SKY_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[0][SKY_FRONT], SKY_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[3][SKY_RIGHT], NIGHT_SKY_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[3][SKY_LEFT], NIGHT_SKY_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[3][SKY_UP], NIGHT_SKY_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[3][SKY_DOWN], GRASS_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[3][SKY_BACK], NIGHT_SKY_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[3][SKY_FRONT], NIGHT_SKY_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[1][SKY_RIGHT], SKY5_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[1][SKY_LEFT], SKY5_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[1][SKY_UP], SKY5_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[1][SKY_DOWN], SKY5_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[1][SKY_BACK], SKY5_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[1][SKY_FRONT], SKY5_TEXTURE); \
   LOAD_TEXTURE(SkyboxTextures[2][SKY_RIGHT], SKY4_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[2][SKY_LEFT], SKY4_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[2][SKY_UP], SKY4_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[2][SKY_DOWN], SKY4_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[2][SKY_BACK], SKY4_TEXTURE); \
    LOAD_TEXTURE(SkyboxTextures[2][SKY_FRONT], SKY4_TEXTURE); \
    LOAD_TEXTURE(box_TexID, WELCOME_TEXTURE); \
    LOAD_TEXTURE(nametag_TexID, NAMETAG_TEXTURE); \
    LOAD_TEXTURE(metal_TexID, METAL_TEXTURE); \
    LOAD_TEXTURE(wood_texID, WOOD_TEXTURE); \
    LOAD_TEXTURE(seesaw_texID, PLASTIC_TEXTURE); \
    LOAD_TEXTURE(rope_TexID, ROPE_TEXTURE); \
    LOAD_TEXTURE(metal2_TexID, METAL2_TEXTURE); \
    LOAD_TEXTURE(SunTextureId, SUN_TEXTURE); \
    LOAD_TEXTURE(EarthTextureId, EARTH_TEXTURE); \
    LOAD_TEXTURE(MoonTextureId, MOON_TEXTURE); \
    LOAD_TEXTURE(tree_top_TexID, TREE_TOP_TEXTURE); \
    LOAD_TEXTURE(tree_trunk_TexID, TREE_TRUNK_TEXTURE); \
    LOAD_TEXTURE(sand_TexID, SAND_TEXTURE); \
    LOAD_TEXTURE(plank_TexID, PLANK_TEXTURE); \
    LOAD_TEXTURE(roberto_TexID, ROBERTO_TEXTURE); \
    LOAD_TEXTURE(plank2_TexID, PLANK2_TEXTURE); \
    LOAD_TEXTURE(door_TexID, DOOR_TEXTURE); \
	LOAD_TEXTURE(door2_TexID, DOOR2_TEXTURE); \
    LOAD_TEXTURE(oak_wood, OAK_WOOD_TEXTURE); \
    LOAD_TEXTURE(birch_wood, BIRCH_WOOD_TEXTURE); \
    LOAD_TEXTURE(stone_TexID, STONE_TEXTURE); \
    LOAD_TEXTURE(body_back, BODY_BACK_TEXTURE); \
    LOAD_TEXTURE(body_front, BODY_FRONT_TEXTURE); \
    LOAD_TEXTURE(head_back, HEAD_BACK_TEXTURE); \
    LOAD_TEXTURE(head_right, HEAD_RIGHT_TEXTURE); \
    LOAD_TEXTURE(head_left, HEAD_LEFT_TEXTURE); \
    LOAD_TEXTURE(face_front, FACE_FRONT_TEXTURE); \
    LOAD_TEXTURE(legs, LEGS_TEXTURE); \
    LOAD_TEXTURE(hands, HANDS_TEXTURE); \
    LOAD_TEXTURE(head_top, HEAD_TOP_TEXTURE); \
    LOAD_TEXTURE(hands_up, HANDS_UP_TEXTURE); \
    LOAD_TEXTURE(hands_down, HANDS_DOWN_TEXTURE); \
    LOAD_TEXTURE(ball_TexID, BALL_TEXTURE); \
	LOAD_TEXTURE(azaf_TexID,AZAF_ID);\
	LOAD_TEXTURE(dsbrick_texID, DSBRICK_TEXTURE);\
	LOAD_TEXTURE(brick_texID,BRICK_TEXTURE);\

//function declerations
void drawingCB(void);
void reshapeCB(int width, int height);
void keyboardCB(unsigned char key, int x, int y);
void keyboardSpecialCB(int key, int x, int y);
void timerCB(int value);
void menuCB(int value);

//utilities
GLubyte* readBMP(char* imagepath, int* width, int* height);
GLuint generateTextures(char* imagepath);
void TerminationErrorFunc(char* ErrorString);
//creating objects
void Draw_Plane(void);
void Draw_Cylinder(float radius, float height, int slices);
void Draw_Box(float width, float height, float depth);
void Draw_Cylinder_With_Box(float cylinderRadius, float cylinderHeight, int cylinderSlices, float boxWidth, float boxHeight, float boxDepth);
void Draw_Textured_Box_Side(float width, float height, float depth, float texWidth, float texHeight);
void Draw_Textured_Box(float width, float height, float depth, int texture_id);
void Draw_WindVane(float size);
void Draw_WindVane_Triangle();
void Draw_Seesaw();
void Draw_Arch(float radius);
void Draw_Person(float height);
void Draw_3D_Arch(float width);
void Draw_Slide(float height);
void Draw_Swing2(float height);
void Draw_Textured_Cylinder(float radius, float height, int slices, int TexID);
void Draw_Carousle();
void Draw_Carousle_Handle();
void Draw_Solid_Disc(float cx, float cy, float r, int num_segments);
void solid_Cylinder(float radius, float height, float slices, float r, float g, float b);
void Draw_Solar_System();
void Draw_Tree(float height);
void Draw_Forest(float h1, float h2, float h3, float h4);
float randomFloat(float min, float max);
void Draw_Sandbox(float height, float width, float length);
void Draw_Person_sitting(float height, int name);
void Draw_Fence();
void Draw_Long_Fence(int length);
void Draw_Bench(int name);
void oak_Wood(int length, int height);
void birch_Wood(int length, int height);
void door();
void door2();
void brick(int length, int height);
void dsbrick(int length, int height);
void stone(int length, int height);
void Draw_Steve();
void Draw_Head(float width, float height, float depth);
void Draw_Body(float width, float height, float depth);
void Draw_Hands(float width, float height, float depth);
void Draw_Legs(float width, float height, float depth);
void Draw_Bouncing_Ball(float top_boundary, float ball_radius);
void Draw_Steve_Bouncing();
void Draw_Skybox(double D, double d);
void Draw_House();
void Draw_Birch_Wall(int width, int height);
void Draw_Stone_Wall(int width, int height);
void Draw_Roof();
void Draw_Brick_Wall(int width, int height);
void Draw_DSBrick_wall(int width, int height);
//materials
void set_Material_to_silver();
void set_Material_to_gold();
void set_Material_to_silver();
void set_Material_to_gold();
void set_Material_to_jade();
void set_Material_to_obsidian();
void set_Material_to_turquoise();
void set_Material_to_brass();
void set_Material_to_ruby();
//globals
GLfloat rotation_angle = 0;
GLfloat swing_angle = 0.1;
GLfloat swing_rotate1, carousle_rotate = 0;
bool OnOff = false;
bool swing_dir = UP;
bool swing2_dir = UP;
bool ball_dir = UP;
bool steve_dir = UP;
bool steve_forward = true;
bool steve_right = true;
bool steve_backwards = false;
bool steve_left = false; \
bool enable_cycle = false;
bool  light1 = true, light2 = true, light3 = true, light4 = true, light0 = true;
bool enable_textures = true, enable_lighting = true;
int daytime = 0;
int lightingEnabled = 1;
int viewMode = 4;
int steve_x = 0, steve_y = 0, steve_z = 0;
int pov_mode = 0;
int SkyboxTextures[4][6];
int box_TexID;
int night_TexID;
int nametag_TexID;
int metal_TexID;
int seesaw_texID;
int wood_texID;
int rope_TexID;
int metal2_TexID;
int SunTextureId;
int EarthTextureId;
int MoonTextureId;
int tree_top_TexID;
int tree_trunk_TexID;
int sand_TexID;
int plank_TexID;
int roberto_TexID;
int plank2_TexID;
int door_TexID, door2_TexID, oak_wood, birch_wood, stone_TexID;
int body_back, body_front, head_back, head_right, head_left, face_front, legs, hands, head_top, hands_up, hands_down;
int ball_TexID;
int sky4id, sky5id;
int azaf_TexID;
int brick_texID, dsbrick_texID;
int rotate_steve = 0;
int total_time = 0;
int tod = 0;
int ObjectRotatingAngle = 0;
int ViewPointAngle1 = 0, ViewPointAngle2 = 10;
int FOVy = 60;
int flag = 0;
int dir = 1;
int thres_angle = 30;
int cylinderSlices = 20;
float speed = 1.0;
float angle = 0.0f;
float cylinderRadius = 0.1;
float cylinderHeight = 1;
float sunX = 5.7, sunY = 6.5, sunZ = -4.0;
float sunR = 0.7;
float earthR = 0.4;
float moonR = 0.25;
float ball_height = 3, ball_boundary, ball_rad, ball_scale_factor = 0;
float ball_scale_factor_x = 1, ball_scale_factor_y = 1, ball_scale_factor_z = 1;
float MIN_Y_SCALE = 0.5f;
float MAX_XZ_SCALE = 1.25f;
float X = 0;
float Y = 0;
float Z = 0;
float XX = 0;
float ZZ = 0;
float R1 = 0;
float R2 = 0;
float R3 = 0;
float hh1, hh2, hh3, hh4, steve_h = 0, steve_l = 0, solar_rotate, boxWidth = 3.0, boxHeight = 1.0, boxDepth = 1.0, boxRotationAngle = 0.0, sphere_offset = 2.25, coneAngle = 0;


int main(int argc, char** argv)
{
	int light_sub_menu, textures_sub_menu, day_night_sub_menu, animations_sub_menu;
	//initizlizing GLUT
	glutInit(&argc, argv);
	srand(time(NULL));

	hh1 = randomFloat(1, 1.4);
	hh2 = randomFloat(0.9, 1.3);
	hh3 = randomFloat(0.8, 1.1);
	hh4 = randomFloat(1, 1.2);
	//initializing window
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(900, 100);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow("3D world");

	//enable depth testing
	glEnable(GL_DEPTH_TEST);

	//init_lighting();
	//registering callbacks
	glutDisplayFunc(drawingCB);
	glutReshapeFunc(reshapeCB);
	glutKeyboardFunc(keyboardCB);
	glutSpecialFunc(keyboardSpecialCB);
	//glutMouseFunc(MouseCB);

	glutTimerFunc(ANIMATION_DELAY, timerCB, 0);


	LOAD_TEXTURES();
	//setting menu:

	light_sub_menu = glutCreateMenu(menuCB);
	glutAddMenuEntry("switch light 1", LIGHT1);
	glutAddMenuEntry("switch light 2", LIGHT2);
	glutAddMenuEntry("switch light 3", LIGHT3);
	glutAddMenuEntry("switch light 4", LIGHT4);
	glutAddMenuEntry("switch light 5", LIGHT5);
	glutAddMenuEntry("turn all lights off/on", ALL_LIGHTS);


	textures_sub_menu = glutCreateMenu(menuCB);
	glutAddMenuEntry("turn on Textures", TEXTURES_ON);
	glutAddMenuEntry("turn off Textures", TEXTURES_OFF);

	day_night_sub_menu = glutCreateMenu(menuCB);
	glutAddMenuEntry("daytime", DAY);
	glutAddMenuEntry("nighttime", NIGHT);
	glutAddMenuEntry("enable day-night cycle", DAY_CYCLE);

	animations_sub_menu = glutCreateMenu(menuCB);
	glutAddMenuEntry("turn animations on", ANIMATIONS_ON);
	glutAddMenuEntry("turn animations off", ANIMATIONS_OFF);


	glutCreateMenu(menuCB);
	glutAddSubMenu("Lights", light_sub_menu);
	glutAddSubMenu("day/night", day_night_sub_menu);
	glutAddSubMenu("animations", animations_sub_menu);
	glutAddSubMenu("textures", textures_sub_menu);
	glutAddMenuEntry("reset all", RESET);
	glutAddMenuEntry("Exit", MENU_EXIT);



	glutAttachMenu(GLUT_RIGHT_BUTTON);



	//setting Global texture parameters
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); //determine how texture mapping interacts   
	//with shading modes. Can be: GL_MODULATE or GL_REPLACE 
	glEnable(GL_TEXTURE_2D);

	//starting main loop
	glutMainLoop();
}
GLuint generateTextures(char* imagepath)
{
	GLubyte* ImageData;
	int width, height;
	GLuint TextureID;

	//reading the image
	ImageData = readBMP(imagepath, &width, &height);

	//Giving a texture ID
	glGenTextures(1, &TextureID);
	glBindTexture(GL_TEXTURE_2D, TextureID);

	//Assign Image as a texture 
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, ImageData);

	//freeing image memory
	free(ImageData);

	//setting Specific texture parameters 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // GL_REPEAT or GL_CLAMP
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL_LINEAR or GL_NEAREST
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return TextureID;
}

void menuCB(int value) {
	//we want to enable animations
	///enable to choose which lighting to turn on/off
	//enable/disable textures
	printf("%d", value);
	switch (value) {
		// switching llights off and on 
	case LIGHT1:
		light1 = !light1;
		break;
	case LIGHT2:
		light2 = !light2;
		break;
	case LIGHT3:
		light3 = !light3;
		break;
	case LIGHT4:
		light4 = !light4;
		break;
	case LIGHT5:
		light0 = !light0;
		break;
	case ALL_LIGHTS:
		if (enable_lighting) {//if they are turned one
			light1 = false;
			light2 = false;
			light3 = false;
			light4 = false;
			light0 = false;
			
		}
		else {
			light1 = true;
			light2 = true;
			light3 = true;
			light4 = true;
			light0 = true;
		}
		enable_lighting = !enable_lighting;
		//switching textures onn and off 
		break;
	case TEXTURES_ON:
		enable_textures = true;
		break;
	case TEXTURES_OFF:
		enable_textures = false;
		break;
		//day night switch
	case DAY:
		enable_cycle = false;
		tod = 0;
		break;
	case NIGHT:
		enable_cycle = false;
		tod = 3;
		break;
	case DAY_CYCLE:
		enable_cycle = true;;
		break;
		//animations
	case ANIMATIONS_ON:
		OnOff = true;
		break;
	case ANIMATIONS_OFF:
		OnOff = false;
		break;
		//reset all
	case RESET:
		light1 = true;
		light2 = true;
		light3 = true;
		light4 = true;
		light0 = true;
		OnOff = true;
		daytime = true;
		enable_textures = true;
		enable_lighting = true;
		break;
	case MENU_EXIT:
		exit(1);
		break;

	}

}
void drawingCB(void)
{
	GLenum er;
	double D = 20;
	double d = 0.02;
	double R = 12.5;

	if (enable_lighting)
	{
		glEnable(GL_LIGHTING);
	}
	else {
		glDisable(GL_LIGHTING);
	}
	if (enable_textures) { glEnable(GL_TEXTURE_2D); }
	else { glDisable(GL_TEXTURE_2D); }


	//clearing the background
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//initializing modelview transformation matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	switch (viewMode)
	{
	case 1: // X view
		gluLookAt(20, 2, 0, 0, 0, 0, 0, 1, 0);
		break;
	case 2: // Y view
		gluLookAt(0, 20, 0, 0, 0, 0, 0, 0, 1);
		break;
	case 3: // Z view
		gluLookAt(0, 2, 20, 0, 0, 0, 0, 1, 0);
		break;

	case 4:
		//setting viewing angle
		gluLookAt(R * cos((double)ViewPointAngle1 * PI / 180), R * sin((double)ViewPointAngle2 * PI / 180), R * sin((double)ViewPointAngle1 * PI / 180), 0, 0, 0, 0, 1, 0);
		break;

		// pov 
	case 5://going forwardk
		pov_mode ? gluLookAt(XX, 7, -8.0 + ZZ, XX, 0, 3.0 + ZZ, 0, 1, 0) : gluLookAt(R * cos((double)ViewPointAngle1 * PI / 180), R * sin((double)ViewPointAngle2 * PI / 180), R * sin((double)ViewPointAngle1 * PI / 180), 0, 0, 0, 0, 1, 0);

		glutPostRedisplay();
		break;
	case 6://going backwards
		pov_mode ? gluLookAt(XX, 7, 8.0 + ZZ, XX, 0, ZZ - 3.0, 0, 1, 0) : gluLookAt(R * cos((double)ViewPointAngle1 * PI / 180), R * sin((double)ViewPointAngle2 * PI / 180), R * sin((double)ViewPointAngle1 * PI / 180), 0, 0, 0, 0, 1, 0);
		glutPostRedisplay();
		break;
	case 7:
		pov_mode ? gluLookAt(-8.0 + XX, 7, ZZ, 3.0 + XX, 0, ZZ, 0, 1, 0) : gluLookAt(R * cos((double)ViewPointAngle1 * PI / 180), R * sin((double)ViewPointAngle2 * PI / 180), R * sin((double)ViewPointAngle1 * PI / 180), 0, 0, 0, 0, 1, 0);
		glutPostRedisplay();
		break;
	case 8:
		pov_mode ? gluLookAt(8.0 + XX, 7, ZZ, XX - 3.0, 0, ZZ, 0, 1, 0) : gluLookAt(R * cos((double)ViewPointAngle1 * PI / 180), R * sin((double)ViewPointAngle2 * PI / 180), R * sin((double)ViewPointAngle1 * PI / 180), 0, 0, 0, 0, 1, 0);
		glutPostRedisplay();
		break;


	}

	//drawing elements 


	glPushMatrix();
	glTranslatef(0, 0, 2);
	glTranslatef(XX, 0, ZZ);
	glRotatef(rotate_steve, 0, 1, 0);
	glScalef(0.8, 0.8, 0.8);
	Draw_Steve();
	//drawing fences
	glPopMatrix();
	glPushMatrix();
	Draw_Skybox(D, d);
	Draw_Plane();
	glPopMatrix();
	glEnable(GL_LIGHTING); // Enable lighting calculations
	glEnable(GL_LIGHT0);  // Enable light source 0


	
	// Set light source parameters
	
	glPushMatrix();
	glTranslatef(-17, 0, 16.6);
	glRotatef(90, 0, 1, 0);
	Draw_House();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-19.0, 0, -19);
	Draw_Long_Fence(12);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-19.2, 0, 17.2);
	glRotatef(90, 0, 1, 0);
	Draw_Long_Fence(13);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(14.1, 0, -18.8);
	glRotatef(-90, 0, 1, 0);
	Draw_Long_Fence(13);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(13.9, 0, 17.4);
	glRotatef(180, 0, 1, 0);
	Draw_Long_Fence(8);
	glPopMatrix();
	//drawing the trees
	glPushMatrix();
	set_Material_to_gold();
	glTranslatef(15.8, 0, -9.8);
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	Draw_Forest(hh1, hh2, hh3, hh4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2, 0, 0);
	glRotatef(180, 0, 1, 0);
	Draw_Forest(hh1, hh2, hh3, hh4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-6, 0, 0);
	glRotatef(180, 0, 1, 0);
	Draw_Forest(hh1, hh2, hh3, hh4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-10, 0, 0);
	glRotatef(180, 0, 1, 0);
	Draw_Forest(hh1, hh2, hh3, hh4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-14, 0, 0);
	glRotatef(180, 0, 1, 0);
	Draw_Forest(hh1, hh2, hh3, hh4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-18, 0, 0);
	glRotatef(180, 0, 1, 0);
	Draw_Forest(hh1, hh2, hh3, hh4);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();

	glTranslatef(0, 0, 0);
	Draw_Cylinder_With_Box(0.1, 5, 70, 4, 2, 1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0, 0, -6);
	Draw_Seesaw();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-6.1, 0, 12.4);
	Draw_Sandbox(0.5, 6, 6);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-11.8, 0, 10.2);
	glRotatef(180, 0, 1, 0);
	Draw_WindVane(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-16.8, 0, 10.2);
	glRotatef(180, 0, 1, 0);
	Draw_WindVane(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-13.4, 0, -14.8);
	Draw_Seesaw();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-13.4, 0, -12.8);
	glRotatef(90, 0, 1, 0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(8.8, 0, -15.8);
	glScalef(2, 1.5, 2);
	Draw_Slide(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(8.8, 0.3, -4.6);
	Draw_Person_sitting(0.75, ROBERTO);
	glPopMatrix();
	glPushMatrix();
	glRotatef(solar_rotate, 0, 1, 0);
	glTranslatef(sunX, sunY + 2, sunZ);
	Draw_Solar_System();
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(6.8, 0, -15.6);
	Draw_Swing2(1);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(-0.2, 0, -15.6);
	Draw_Swing2(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.9, 0, 10.3);
	Draw_Carousle();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.4, 0, -12.5);
	Draw_Bench(ROBERTO);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4, 0, -12.5);
	Draw_Bench(AZAF);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(1.3, 0, 11.1);
	glRotatef(180, 0, 1, 0);
	glScalef(0.75, 0.75, 0.75);
	Draw_Steve_Bouncing();
	glPopMatrix();
	
	//swapping buffers and displaying
	glutSwapBuffers();

	//check for errors
	er = glGetError();  //get errors. 0 for no error, find the error codes in: https://www.opengl.org/wiki/OpenGL_Error
	if (er) printf("error: %d\n", er);
}
void reshapeCB(int width, int height)
{
	float zNear, zFar;

	//define our ortho
	zNear = 1; zFar = 40;

	//update viewport
	glViewport(0, 0, width, height);

	//clear the transformation matrices (load identity)
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//projection
	gluPerspective(FOVy, 1, zNear, zFar);
}
void keyboardCB(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	case ']':
		pov_mode = pov_mode == 1 ? 0 : 1;
		printf("%d", pov_mode);
		break;

	case '+':
		FOVy = FOVy - 1;
		reshapeCB(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		glutPostRedisplay();
		break;
	case '-':
		FOVy = FOVy + 1;
		reshapeCB(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		glutPostRedisplay();
		break;

	case 'a':
		X -= 0.1;
		printf("(%f, %f, %f)\n", X, Y, Z);
		break;
	case 'w':
		Z -= 0.1;
		printf("(%f, %f, %f)\n", X, Y, Z);
		break;
	case 's':
		Z += 0.1;
		printf("(%f, %f, %f)\n", X, Y, Z);
		break;
	case 'd':
		X += 0.1;
		printf("(%f, %f, %f)\n", X, Y, Z);
		break;
	case 'q':
		Y += 0.1;
		printf("(%f, %f, %f)\n", X, Y, Z);
		break;
	case 'e':
		Y -= 0.1;
		printf("(%f, %f, %f)\n", X, Y, Z);
		break;
	case '1':
		R1 += 1;
		if (R1 == 360) R1 = 0;
		printf("(%f, %f, %f)\n", R1, R2, R3);
		break;
	case '2':
		R2 += 1;
		if (R2 == 360) R2 = 0;
		printf("(%f, %f, %f)\n", R1, R2, R3);
		break;
	case '3':
		R3 += 1;
		if (R3 == 360) R3 = 0;
		printf("(%f, %f, %f)\n", R1, R2, R3);
		break;
	case '4':
		R1 -= 1;
		if (R1 == 360) R1 = 0;
		printf("(%f, %f, %f)\n", R1, R2, R3);
		break;
	case '5':
		R2 -= 1;
		if (R2 == 360) R2 = 0;
		printf("(%f, %f, %f)\n", R1, R2, R3);
		break;
	case '6':
		R3 -= 1;
		if (R3 == 360) R3 = 0;
		printf("(%f, %f, %f)\n", R1, R2, R3);
		break;
	case 'p':
		R1 = 0; R2 = 0; R3 = 0;
		break;
	case 'i': // Move steve forward
		steve_forward = true; // Update direction first
		rotate_steve = (steve_forward ? FORWARD : BACKWARD);  // Set rotation based on current direction
		steve_forward = !steve_forward;
		if (pov_mode) viewMode = 5;
		ZZ += 0.3;
		steve_z += 0.1;
		if (steve_dir) {
			steve_l += 2;
			if (steve_l >= 30) {
				steve_dir = !steve_dir; // Change direction
			}
		}
		else {
			steve_l -= 2;
			if (steve_l <= -30) {
				steve_dir = !steve_dir; // Change direction
			}
		}
		break;
	case 'k':
		if (pov_mode) viewMode = 6;
		steve_forward = false; // Update direction first
		rotate_steve = (steve_forward ? FORWARD : BACKWARD);  // Set rotation based on current direction
		steve_forward = !steve_forward;
		ZZ -= 0.3;
		if (steve_dir) {
			steve_l += 2;
			if (steve_l >= 30) {
				steve_dir = !steve_dir; // Change direction
			}
		}
		else {
			steve_l -= 2;
			if (steve_l <= -30) {
				steve_dir = !steve_dir; // Change direction
			}
		}
		break;
	case 'l'://right
		if (pov_mode) viewMode = 8;
		steve_right = true; // Update direction first
		rotate_steve = (steve_right ? RIGHT : LEFT);  // Set rotation based on current direction
		steve_forward = !steve_forward;
		XX -= 0.3;
		if (steve_dir) {
			steve_l += 2;
			if (steve_l >= 30) {
				steve_dir = !steve_dir; // Change direction
			}
		}
		else {
			steve_l -= 2;
			if (steve_l <= -30) {
				steve_dir = !steve_dir; // Change direction
			}
		}
		break;
	case 'j'://left
		if (pov_mode)viewMode = 7;
		steve_right = false; // Update direction first
		rotate_steve = (steve_right ? RIGHT : LEFT);  // Set rotation based on current direction
		steve_forward = !steve_forward;
		XX += 0.3;
		if (steve_dir) {
			steve_l += 2;
			if (steve_l >= 30) {
				steve_dir = !steve_dir; // Change direction
			}
		}
		else {
			steve_l -= 2;
			if (steve_l <= -30) {
				steve_dir = !steve_dir; // Change direction
			}
		}
		break;
	case '0':
		viewMode = 4;
		break;
	case '9':
		viewMode = 3;
		break;
	case '8':
		viewMode = 2;
		break;
	case '7':
		viewMode = 1;
		break;

	case '.':
		enable_textures = !enable_textures;
		break;

	default:
		printf("Unhandled key: %c\n", key);
		break;
	}
	glutPostRedisplay();
}
void keyboardSpecialCB(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT:
		ViewPointAngle1 = (ViewPointAngle1 + 360 - 1) % 360;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		ViewPointAngle1 = (ViewPointAngle1 + 360 + 1) % 360;
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		// Increase ViewPointAngle2, but limit it to be between 10 and 90 degrees
		if (ViewPointAngle2 < 90)
			ViewPointAngle2 = fmin(90, ViewPointAngle2 + 1.0);
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		// Decrease ViewPointAngle2, but limit it to be between 10 and 90 degrees
		if (ViewPointAngle2 > 10)
			ViewPointAngle2 = fmax(10, ViewPointAngle2 - 1.0);
		glutPostRedisplay();
		break;




	}

}
void timerCB(int value) {
	ObjectRotatingAngle = (ObjectRotatingAngle + 360 + 1) % 360;
	boxRotationAngle += 0.5f;
	rotation_angle += 1.0f;
	carousle_rotate += 1;
	solar_rotate += 0.2;
	total_time += 20;
	if (enable_cycle) {
		if (total_time % 6000 == 0) {
			tod++;
			tod = tod % 4;
		}
	}

	// Increment or decrement swing_angle based on its current value and direction

	if (swing_dir) {
		swing_angle += 0.3;
		if (swing_angle >= 12.9) {
			swing_dir = !swing_dir; // Change direction
		}
	}
	else {
		swing_angle -= 0.3;
		if (swing_angle <= -12.9) {
			swing_dir = !swing_dir; // Change direction
		}
	}

	if (swing2_dir) {
		swing_rotate1 += 0.6;
		if (swing_rotate1 >= 30) {
			swing2_dir = !swing2_dir; // Change direction
		}
	}
	else {
		swing_rotate1 -= 0.6;
		if (swing_rotate1 <= -30) {
			swing2_dir = !swing2_dir; // Change direction
		}
	}
	if (ball_dir) {
		ball_height += 0.1;
		if (ball_height >= ball_boundary) {
			ball_dir = !ball_dir; // Change direction
		}

	}
	else {
		ball_height -= 0.1;
		if (ball_height <= 0.25 * ball_rad) {
			ball_dir = !ball_dir; // Change direction
		}


	}
	// Maximum scale factor for x and z-axes

	if (ball_height <= ball_rad && !ball_dir && ball_height >= 0.5 * ball_rad) {
		ball_scale_factor_x = fminf(ball_scale_factor_x + 0.1f, MAX_XZ_SCALE * ball_rad);
		ball_scale_factor_z = fminf(ball_scale_factor_z + 0.1f, MAX_XZ_SCALE * ball_rad);
		ball_scale_factor_y = fmaxf(ball_scale_factor_y - 0.1f, MIN_Y_SCALE * ball_rad);
	}
	else if (ball_height >= 0.5 * ball_rad && ball_dir && ball_height <= ball_rad) {
		ball_scale_factor_x = fmaxf(ball_scale_factor_x - 0.1f, 1.0f);
		ball_scale_factor_z = fmaxf(ball_scale_factor_z - 0.1f, 1.0f);
		ball_scale_factor_y = fminf(ball_scale_factor_y + 0.1f, 1.0f);
	}
	if (ball_height >= (ball_boundary - 0.5 * ball_rad) && ball_dir && ball_height <= ball_boundary) {
		// Apply the same logic for scaling when the ball is at the top boundary
		ball_scale_factor_x = fminf(ball_scale_factor_x + 0.1f, MAX_XZ_SCALE * ball_rad);
		ball_scale_factor_z = fminf(ball_scale_factor_z + 0.1f, MAX_XZ_SCALE * ball_rad);
		ball_scale_factor_y = fmaxf(ball_scale_factor_y - 0.1f, MIN_Y_SCALE * ball_rad);
	}
	else if (ball_height <= ball_boundary && !ball_dir && ball_height >= ball_boundary - 0.5 * ball_rad) {
		ball_scale_factor_x = fmaxf(ball_scale_factor_x - 0.1f, 1.0f);
		ball_scale_factor_z = fmaxf(ball_scale_factor_z - 0.1f, 1.0f);
		ball_scale_factor_y = fminf(ball_scale_factor_y + 0.1f, 1.0f);
	}




	// Reassign to the timer event again		
	glutTimerFunc(ANIMATION_DELAY, timerCB, value);

	// Call redisplay 	
	glutPostRedisplay();



}
// Function to load bmp file
// buffer for the image is allocated in this function, you should free this buffer
GLubyte* readBMP(char* imagepath, int* width, int* height)
{
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int imageSize;   // = width*height*3
	unsigned char* data;
	unsigned char tmp;
	int i;

	// Open the file
	FILE* file = fopen(imagepath, "rb");
	if (!file) {
		TerminationErrorFunc("Image could not be opened\n");
	}

	if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
		TerminationErrorFunc("Not a correct BMP file\n");
	}

	if (header[0] != 'B' || header[1] != 'M') {
		TerminationErrorFunc("Not a correct BMP file\n");
	}

	// Read ints from the byte array
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	*width = *(int*)&(header[0x12]);
	*height = *(int*)&(header[0x16]);

	// Some BMP files are misformatted, guess missing information
	if (imageSize == 0)
		imageSize = *width * *height * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)
		dataPos = 54; // The BMP header is done that way

	// Create a buffer
	data = malloc(imageSize * sizeof(GLubyte));

	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);


	//swap the r and b values to get RGB (bitmap is BGR)
	for (i = 0; i < *width * *height; i++)
	{
		tmp = data[i * 3];
		data[i * 3] = data[i * 3 + 2];
		data[i * 3 + 2] = tmp;
	}


	//Everything is in memory now, the file can be closed
	fclose(file);

	return data;
}
void TerminationErrorFunc(char* ErrorString)
{
	char string[256];
	printf(ErrorString);
	fgets(string, 256, stdin);     // warning: unsafe (see fgets instead)

	exit(0);
}
void Draw_Plane() {

	float planeSize = MeshSize;
	float textureRepeat = 10.0f;


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, SkyboxTextures[0][SKY_DOWN]);


	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-planeSize, 0, -planeSize);
	glTexCoord2f(textureRepeat, 0);
	glVertex3f(planeSize, 0, -planeSize);
	glTexCoord2f(textureRepeat, textureRepeat);
	glVertex3f(planeSize, 0, planeSize);
	glTexCoord2f(0, textureRepeat); glVertex3f(-planeSize, 0, planeSize);
	glEnd();

	// Disable texture 2D and color material
	glDisable(GL_TEXTURE_2D);


}
void Draw_Cylinder(float radius, float height, int slices) {

	int i;


	// Draw the cylinder

	glBegin(GL_QUAD_STRIP);

	for (i = 0; i <= slices * 2; i++) {

		float angle = 2.0 * PI * i / slices;

		float x = radius * cos(angle);

		float z = radius * sin(angle);

		glNormal3f(x / radius, 0.0, z / radius);

		glVertex3f(x, 0.0, z);

		glVertex3f(x, height, z);

	}

	glEnd();

}
void Draw_Textured_Cylinder(float radius, float height, int slices, int TexID) {
	int i;

	// Set material properties for a metallic appearance

	// Enable texture mapping
	if (enable_textures) { glEnable(GL_TEXTURE_2D); }
	else { glDisable(GL_TEXTURE_2D); }

	glBindTexture(GL_TEXTURE_2D, TexID);

	// Draw the cylinder with texture coordinates
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= slices; i++) {
		float angle = 2.0f * PI * i / slices;
		float x = radius * cos(angle);
		float z = radius * sin(angle);

		glNormal3f(x / radius, 0.0, z / radius);

		// Texture coordinates
		float s = (float)i / slices;
		glTexCoord2f(s, 0.0f);
		glVertex3f(x, 0.0, z);
		glTexCoord2f(s, 1.0f);
		glVertex3f(x, height, z);
	}
	glEnd();

	// Disable texture mapping
	glDisable(GL_TEXTURE_2D);

}
void Draw_Box(float width, float height, float depth) {
	// Disable lighting for the box
	////gldisable(GL_LIGHTING);

	glBegin(GL_QUADS);
	// Front face
	glVertex3f(-width / 2, 0.0, depth / 2);
	glVertex3f(width / 2, 0.0, depth / 2);
	glVertex3f(width / 2, height, depth / 2);
	glVertex3f(-width / 2, height, depth / 2);
	// Back face
	glVertex3f(-width / 2, 0.0, -depth / 2);
	glVertex3f(-width / 2, height, -depth / 2);
	glVertex3f(width / 2, height, -depth / 2);
	glVertex3f(width / 2, 0.0, -depth / 2);
	// Left face
	glVertex3f(-width / 2, 0.0, -depth / 2);
	glVertex3f(-width / 2, 0.0, depth / 2);
	glVertex3f(-width / 2, height, depth / 2);
	glVertex3f(-width / 2, height, -depth / 2);
	// Right face
	glVertex3f(width / 2, 0.0, -depth / 2);
	glVertex3f(width / 2, height, -depth / 2);
	glVertex3f(width / 2, height, depth / 2);
	glVertex3f(width / 2, 0.0, depth / 2);
	// Top face
	glVertex3f(-width / 2, height, -depth / 2);
	glVertex3f(-width / 2, height, depth / 2);
	glVertex3f(width / 2, height, depth / 2);
	glVertex3f(width / 2, height, -depth / 2);
	// Bottom face
	glVertex3f(-width / 2, 0.0, -depth / 2);
	glVertex3f(width / 2, 0.0, -depth / 2);
	glVertex3f(width / 2, 0.0, depth / 2);
	glVertex3f(-width / 2, 0.0, depth / 2);
	glEnd();

	// Enable lighting again
//	//glEnable(GL_LIGHTING);
}
//light 3
void Draw_Cylinder_With_Box(float cylinderRadius, float cylinderHeight, int cylinderSlices, float boxWidth, float boxHeight, float boxDepth) {
	float totalHeight = cylinderHeight + boxHeight; // Calculate the combined height of the cylinder and the box

	if (enable_lighting)  glEnable(GL_LIGHTING) ;
	GLfloat mat_ambient[] = { 0.25, 0.25, 0.25, 1.0 };
	GLfloat mat_diffuse[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat mat_specular[] = { 0.774597, 0.774597, 0.774597, 1.0 };
	GLfloat shine[] = { 76.8 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shine);
	GLfloat light_position4[] = { 0.0, 1.0, 1.0, 0.0 };
	if (light3) glEnable(GL_LIGHT3); // Enable the first light (GL_LIGHT3)
	else glDisable(GL_LIGHT3);
	// Enable and configure the fourth light (GL_LIGHT4)

	glLightfv(GL_LIGHT3, GL_POSITION, light_position4);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.0);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.0);
	// Draw the cylinder first

	Draw_Textured_Cylinder(cylinderRadius, cylinderHeight, cylinderSlices, metal2_TexID);

	// Save the current transformation matrix
	glPushMatrix();

	// Apply rotation around the y-axis only to the box
	glTranslatef(0.0, cylinderHeight, 0.0); // Move to the top center position
	if (OnOff) {
		glRotatef(boxRotationAngle, 0.0f, 1.0f, 0.0f);
	}

	Draw_Textured_Box(boxWidth, boxHeight, boxDepth, box_TexID); // Draw the textured box instead of the regular box
	glPopMatrix();
}
void Draw_Textured_Box(float width, float height, float depth, int texture_id) {
	// Enable texture 2D
	if (enable_textures) { glEnable(GL_TEXTURE_2D); }
	else { glDisable(GL_TEXTURE_2D); }

	// Bind the texture for the box sides
	glBindTexture(GL_TEXTURE_2D, texture_id);
	// Draw the long box
	glBegin(GL_QUADS);

	// Front face
	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, depth / 2);

	// Back face
	glTexCoord2f(0, 0); glVertex3f(width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(-width / 2, height, -depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, height, -depth / 2);

	// Left face
	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(-width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, -depth / 2);

	// Right face
	glTexCoord2f(0, 0); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, -depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, height, depth / 2);

	// Top face
	glTexCoord2f(0, 0); glVertex3f(-width / 2, height, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, height, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, depth / 2);

	// Bottom face
	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, 0.0, -depth / 2);

	glEnd();

	// Disable texture 2D
	glDisable(GL_TEXTURE_2D);
}
void Draw_Textured_Box_Side(float width, float height, float depth, float texWidth, float texHeight) {
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-width / 2, -height / 2, depth / 2);
	glTexCoord2f(texWidth, 0.0); glVertex3f(width / 2, -height / 2, depth / 2);
	glTexCoord2f(texWidth, texHeight); glVertex3f(width / 2, height / 2, depth / 2);
	glTexCoord2f(0.0, texHeight); glVertex3f(-width / 2, height / 2, depth / 2);
	glEnd();
}
void Draw_WindVane(float size) {
	glDisable(GL_LIGHTING);

	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -0.15);
	Draw_Textured_Cylinder(0.1f, size * VANE_HEIGHT, 70, metal2_TexID);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glTranslatef(0, size * VANE_HEIGHT, 0);
	glutSolidSphere(0.25, 10, 15);
	if (OnOff) {
		glRotatef(rotation_angle, 0, 0, 1);
	}
	glScalef(size, size, size);
	glColor3f(1, 0, 0);

	////gldisable(GL_LIGHTING);
	glColor3f(1, 0, 0);
	Draw_WindVane_Triangle();
	glRotatef(90, 0, 0, 1);
	glColor3f(1, 0.11, 0.68);
	Draw_WindVane_Triangle();
	glRotatef(90, 0, 0, 1);
	glColor3f(0, 0, 1);
	Draw_WindVane_Triangle();
	glRotatef(90, 0, 0, 1);
	glColor3f(1, 1, 0);
	Draw_WindVane_Triangle();
	glEnable(GL_TEXTURE_2D);
	////glEnable(GL_LIGHTING);
	glPopMatrix();
	glEnable(GL_LIGHTING);


}
void Draw_WindVane_Triangle() {

	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glVertex3f(0, 0, 0);//A
	glVertex3f(0, 1, 0);//B
	glVertex3f(1, 1, 0);//C
	glVertex3f(0, 0, 0.1);//D
	glVertex3f(0, 1, 0.1);//E
	glVertex3f(1, 1, 0.1);//F
	glEnd();
	glBegin(GL_QUADS);
	//ABED
	glVertex3f(0, 0, 0);//A
	glVertex3f(0, 1, 0);//B
	glVertex3f(0, 1, 0.1);//E
	glVertex3f(0, 0, 0.1);//D
	//ADFC
	glVertex3f(0, 0, 0);//A
	glVertex3f(0, 0, 0.1);//D
	glVertex3f(1, 1, 0.1);//F
	glVertex3f(1, 1, 0);//C

	//BEFC
	glVertex3f(0, 1, 0);//B
	glVertex3f(0, 1, 0.1);//E
	glVertex3f(1, 1, 0.1);//F
	glVertex3f(1, 1, 0);//C
	glEnd();
	glPopMatrix();


}
void Draw_Seesaw() {
	glEnable(GL_LIGHTING);
	set_Material_to_obsidian();
	glDisable(GL_TEXTURE_2D);
	////gldisable(GL_LIGHTING);
	glPushMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);

	set_Material_to_obsidian();
	//swing base
	//glEnable(GL_LIGHTING);
	glBegin(GL_TRIANGLES);
	glVertex3f(0, 1, 0);//A
	glVertex3f(-0.5, 0, 0);//B
	glVertex3f(0.5, 0, 0);//C
	glVertex3f(0, 1, -1);//D
	glVertex3f(-0.5, 0, -1);//E
	glVertex3f(0.5, 0, -1);//F
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(0, 1, 0);//A
	glVertex3f(0, 1, -1);//D
	glVertex3f(-0.5, 0, -1);//E
	glVertex3f(-0.5, 0, 0);//B
	glVertex3f(0, 1, 0);//A
	glVertex3f(0, 1, -1);//D
	glVertex3f(0.5, 0, -1);//F
	glVertex3f(0.5, 0, 0);//C
	glVertex3f(-0.5, 0, -1);//E
	glVertex3f(-0.5, 0, 0);//B
	glVertex3f(0.5, 0, -1);//F
	glVertex3f(0.5, 0, 0);//C
	glEnd();
	glPopMatrix();
	//tires under the seats
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-3, 0, -0.5);
	glutSolidSphere(0.5, 10, 15);
	glTranslatef(6, 0, 0);
	glutSolidSphere(0.5, 10, 15);
	glPopMatrix();
	////gldisable(GL_LIGHTING);
	//swing seats
	if (OnOff) {
		glRotatef(swing_angle, 0, 0, 1);
	}
	glPushMatrix();
	glColor3f(0.435294, 0.258824, 0.258824);
	glTranslatef(0, 1, -0.5);
	Draw_Textured_Box(7, 0.2, 1, seesaw_texID);
	glPopMatrix();
	//tires under the swing

	//handles
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	glTranslatef(-2.4, 1.2, -0.5);
	Draw_Textured_Cylinder(0.1, 0.2, 50, metal2_TexID);
	glTranslatef(4.8, 0, 0);
	Draw_Textured_Cylinder(0.1, 0.2, 50, metal2_TexID);
	glEnable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	glTranslatef(2.4, 1.5, -1);
	glRotatef(90, 1, 0, 0);
	Draw_Textured_Cylinder(0.12, 1, 50, metal2_TexID);
	glTranslatef(-4.8, 0, 0);
	Draw_Textured_Cylinder(0.12, 1, 50, metal2_TexID);
	glEnable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	////glEnable(GL_LIGHTING);
}
void Draw_Person(float height) {
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glScalef(height, height, height);
	////glDisable(GL_LIGHTING);
	glDisable(GL_LIGHTING);


	//draw body and head
	glPushMatrix();
	glColor3f(1, 0, 1);
	glTranslatef(0, 4, 0);
	glutSolidSphere(1, 50, 50);
	glTranslatef(0, -4, 0);
	glTranslatef(0, 1, 0);
	glColor3f(0, 0, 0);
	Draw_Cylinder(1, 2, 200);
	glTranslatef(0, -1, 0);
	glPopMatrix();

	//draw hands
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(1.15, 1.5, 0);
	Draw_Cylinder(0.17, 1.5, 70);//right hand
	glTranslatef(-1.15, -1.5, 0);
	glTranslatef(-1.15, 1.5, 0);
	Draw_Cylinder(0.17, 1.5, 70);//left hand
	glTranslatef(1.15, -1.5, 0);
	glTranslatef(-0.4, 0, 0);
	Draw_Cylinder(0.17, 1, 70);//left leg
	glTranslatef(0.8, 0, 0);
	Draw_Cylinder(0.17, 1, 70);//right leg
	glPopMatrix();

	//draw face
	glPushMatrix();
	glTranslatef(-0.35, 4.4, 0.9);
	glRotatef(120, 0, 0, 1);
	Draw_Cylinder(0.05, 0.4, 70);//left eyebrow
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.35, 4.4, 0.9);
	glRotatef(-120, 0, 0, 1);
	Draw_Cylinder(0.05, 0.4, 70);//right eyebrow
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 1, 1);
	glTranslatef(-0.3, 4.01, 1);
	glutSolidSphere(0.1, 100, 100);//eye
	glTranslatef(0.6, 0, 0);
	glutSolidSphere(0.1, 100, 100);//eye
	glPopMatrix();

	//mouth
	glPushMatrix();
	glTranslatef(0, 3.7, -1.0);
	glRotatef(180, 0, 0, 1);
	glColor3f(1.0, 0.0, 0.1);
	glColor3f(1, 0, 0);
	Draw_Arch(0.2);
	glPopMatrix();

	//draw circle in the shirt
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0, 1.5, 0.9);
	glutSolidSphere(0.2, 100, 100);
	glTranslatef(0, 0.6, 0);
	glutSolidSphere(0.2, 100, 100);
	glTranslatef(0, 0.6, 0);
	glutSolidSphere(0.2, 100, 100);
	glTranslatef(0, 0.6, 0);
	glPopMatrix();

	//draw white part in the shirt
	glPushMatrix();
	glTranslatef(0, 1.15, 0.9);
	glColor3f(1, 1, 1);
	Draw_Box(0.6, 1.8, 0.2);
	glPopMatrix();

	//palms of the hand
	glPushMatrix();
	glColor3f(1, 0, 1);
	glTranslatef(1.15, 1.325, -1.85);
	Draw_3D_Arch(0.3);
	glTranslatef(-2.3, 0, 0);
	Draw_3D_Arch(0.3);
	glPopMatrix();

	//name tag
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glTranslatef(0, 5.2, 0);
	Draw_Textured_Box(2, 0.75, 0.1, nametag_TexID);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPopMatrix();
	glEnable(GL_LIGHTING);
}
void Draw_Person_sitting(float height, int name) {
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glScalef(height, height, height);
	////gldisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//draw body and head
	glPushMatrix();
	glColor3f(1, 0, 1);
	glTranslatef(0, 4, 0);
	glutSolidSphere(1, 50, 50);
	glTranslatef(0, -4, 0);
	glTranslatef(0, 1, 0);
	glColor3f(0, 0, 0);
	Draw_Cylinder(1, 2, 200);
	glTranslatef(0, -1, 0);
	glPopMatrix();

	//draw hands
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(1.15, 1.5, 0);
	Draw_Cylinder(0.17, 1.5, 70);//right hand
	glTranslatef(-1.15, -1.5, 0);
	glTranslatef(-1.15, 1.5, 0);
	Draw_Cylinder(0.17, 1.5, 70);//left hand
	glTranslatef(1.15, -1.5, 0);
	glTranslatef(-0.4, 0, 0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -0.9);
	Draw_Cylinder(0.17, 1.4, 70);//left leg
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0.8, 0, 0);
	glRotatef(90, 1, 0, 0);

	Draw_Cylinder(0.17, 1.4, 70);//right leg
	glPopMatrix();

	//draw face
	glPushMatrix();
	glTranslatef(-0.35, 4.4, 0.9);
	glRotatef(120, 0, 0, 1);
	Draw_Cylinder(0.05, 0.4, 70);//left eyebrow
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.35, 4.4, 0.9);
	glRotatef(-120, 0, 0, 1);
	Draw_Cylinder(0.05, 0.4, 70);//right eyebrow
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 1, 1);
	glTranslatef(-0.3, 4.01, 1);
	glutSolidSphere(0.1, 100, 100);//eye
	glTranslatef(0.6, 0, 0);
	glutSolidSphere(0.1, 100, 100);//eye
	glPopMatrix();

	//mouth
	glPushMatrix();
	glTranslatef(0, 3.7, -1.0);
	glRotatef(180, 0, 0, 1);
	glColor3f(1.0, 0.0, 0.1);
	glColor3f(1, 0, 0);
	Draw_Arch(0.2);
	glPopMatrix();

	//draw circle in the shirt
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0, 1.5, 0.9);
	glutSolidSphere(0.2, 100, 100);
	glTranslatef(0, 0.6, 0);
	glutSolidSphere(0.2, 100, 100);
	glTranslatef(0, 0.6, 0);
	glutSolidSphere(0.2, 100, 100);
	glTranslatef(0, 0.6, 0);
	glPopMatrix();

	//draw white part in the shirt
	glPushMatrix();
	glTranslatef(0, 1.15, 0.9);
	glColor3f(1, 1, 1);
	Draw_Box(0.6, 1.8, 0.2);
	glPopMatrix();

	//palms of the hand
	glPushMatrix();
	glColor3f(1, 0, 1);
	glTranslatef(1.15, 1.325, -1.85);
	Draw_3D_Arch(0.3);
	glTranslatef(-2.3, 0, 0);
	Draw_3D_Arch(0.3);
	glPopMatrix();

	//name tag
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glTranslatef(0, 5.2, 0);
	Draw_Textured_Box(2, 0.75, 0.1, name == ROBERTO ? roberto_TexID : azaf_TexID);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	////glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glPopMatrix();
	glEnable(GL_LIGHTING);


}
void Draw_Arch(float radius) {
	float theta;
	float angle = 0.0;
	float height = 2.0;
	int numSegments = 100;
	glPushMatrix();
	// Red color for the arch

	glLineWidth(2.0); // Set line width

	// Draw the arch
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= numSegments / 2; i++) {
		theta = angle * PI / 180; // convert to rad
		glVertex3f(radius * cos(theta), radius * sin(theta), height);
		angle += (360.0 / numSegments);
	}
	glEnd();
	glPopMatrix();
}
void Draw_3D_Arch(float width) {
	float delta = 0.01f;
	////gldisable(GL_LIGHTING);
	glPushMatrix();
	glColor3f(1, 0, 1);
	for (float i = 0; i < width; i += delta) {
		Draw_Arch(0.2f); // Adjust radius as needed
		glTranslatef(0, 0, -delta);
	}
	glPopMatrix();
	////glEnable(GL_LIGHTING);
}
void Draw_Slide(float height) {
	set_Material_to_jade();
	glPushMatrix();
	////gldisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	//draw the slide sliding part
	glPushMatrix();

	glTranslatef(0, 3.5, 0.65);
	glColor3f(1, 0, 0);
	Draw_Textured_Box(1, 0.1, 1.5, metal_TexID);
	//Draw_Box(1, 0.1, 1.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.4, 0, 1.3);
	glColor3f(0, 0, 0);
	Draw_Textured_Cylinder(0.1, 3.5, 70, metal2_TexID);
	glTranslatef(-0.8, 0, 0);
	Draw_Textured_Cylinder(0.1, 3.5, 70, metal2_TexID);
	glPopMatrix();
	glPushMatrix();
	glRotatef(45, 1, 0, 0);
	glTranslatef(0, 3.4, 0.6);
	glColor3f(1, 0, 0);
	Draw_Textured_Box(1, 0.1, 4.5, metal_TexID);
	//Draw_Box(1, 0.1, 4.5);
	glColor3f(1, 0, 0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0.4, 5.1);
	glColor3f(1, 0, 0);
	Draw_Textured_Box(1, 0.1, 1.5, metal_TexID);
	//	Draw_Box(1, 0.1, 1.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.4, 0, 4.4);
	glColor3f(0, 0, 0);
	Draw_Textured_Cylinder(0.1, 0.5, 70, metal2_TexID);
	glTranslated(-0.8, 0, 0);
	Draw_Textured_Cylinder(0.1, 0.5, 70, metal2_TexID);
	glTranslatef(0, 0, 1.3);
	Draw_Textured_Cylinder(0.1, 0.5, 70, metal2_TexID);
	glTranslatef(0.8, 0, 0);
	Draw_Textured_Cylinder(0.1, 0.5, 70, metal2_TexID);

	glPopMatrix();

	//draw handles

	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(-0.5, 3.6, 0.7);

	Draw_Textured_Box(0.1, 0.5, 1.5, wood_texID);
	glTranslatef(1, 0, 0);
	Draw_Textured_Box(0.1, 0.5, 1.5, wood_texID);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.5, 0.5, 5.1);
	Draw_Textured_Box(0.1, 0.5, 1.5, wood_texID);
	glTranslatef(1, 0, 0);
	Draw_Textured_Box(0.1, 0.5, 1.5, wood_texID);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.5, 2.1, 2.7);
	glRotatef(45, 1, 0, 0);
	Draw_Textured_Box(0.1, 0.5, 4.5, wood_texID);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.5, 2.1, 2.7);
	glRotatef(45, 1, 0, 0);
	Draw_Textured_Box(0.1, 0.5, 4.5, wood_texID);
	glPopMatrix();



	//draw ladder
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.5, 0, 0);
	Draw_Textured_Cylinder(0.1, 4.2, 70, metal2_TexID);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.5, 0, 0);
	Draw_Textured_Cylinder(0.1, 4.2, 70, metal2_TexID);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.5, 0.5, 0);
	glRotatef(90, 0, 0, 1);
	Draw_Textured_Cylinder(0.1, 1, 70, metal2_TexID);
	glTranslatef(0.5, 0, 0);
	Draw_Textured_Cylinder(0.1, 1, 70, metal2_TexID);
	glTranslatef(0.5, 0, 0);
	Draw_Textured_Cylinder(0.1, 1, 70, metal2_TexID);
	glTranslatef(0.5, 0, 0);
	Draw_Textured_Cylinder(0.1, 1, 70, metal2_TexID);
	glTranslatef(0.5, 0, 0);
	Draw_Textured_Cylinder(0.1, 1, 70, metal2_TexID);
	glTranslatef(0.5, 0, 0);
	Draw_Textured_Cylinder(0.1, 1, 70, metal2_TexID);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 5.7);
	Draw_Sandbox(0.2, 3, 4);
	glPopMatrix();


	glEnable(GL_TEXTURE_2D);
	////glEnable(GL_LIGHTING);

	glPopMatrix();

}
//light4
void Draw_Swing2(float height) {

	GLfloat light_position[] = { 0.0, height + 2.0, 0.0, 1.0 }; // Position of the light above the swing


	glDisable(GL_TEXTURE_2D);


	// Lighting setup
	if(enable_lighting) glEnable(GL_LIGHTING);

	// Enable light 5
	if (light4) glEnable(GL_LIGHT4);
	else glDisable(GL_LIGHT4);
	glLightfv(GL_LIGHT4, GL_POSITION, light_position);
	glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 0.0);
	glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0.0);
	// Define copper material
	GLfloat mat_ambient_copper[] = { 0.19125, 0.0735, 0.0225, 1.0 };
	GLfloat mat_diffuse_copper[] = { 0.7038, 0.27048, 0.0828, 1.0 };
	GLfloat mat_specular_copper[] = { 0.256777, 0.137622, 0.086014, 1.0 };
	GLfloat shine_copper[] = { 12.8 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_copper);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_copper);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_copper);
	glMaterialfv(GL_FRONT, GL_SHININESS, shine_copper);
	glPushMatrix();
	//frame
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0, 0, -0.7);
	glTranslatef(3, 0, 0);
	glRotatef(15, 1, 0, 0);
	Draw_Textured_Box(0.2, 5.2, 0.2, metal_TexID);
	glTranslatef(-6, 0, 0);
	Draw_Textured_Box(0.2, 5.2, 0.2, metal_TexID);
	glPopMatrix();
	//top bar
	glPushMatrix();
	glTranslatef(3, 0, 2);
	glRotatef(-15, 1, 0, 0);
	Draw_Textured_Box(0.2, 5.2, 0.2, metal_TexID);
	glTranslatef(-6, 0, 0);
	Draw_Textured_Box(0.2, 5.2, 0.2, metal_TexID);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3, 5, 0.65);
	glRotatef(-90, 0, 0, 1);
	Draw_Textured_Box(0.2, 6, 0.2, metal_TexID);
	glPopMatrix();
	glPopMatrix();
	//ropes and seats
	glPushMatrix();
	glTranslatef(0, 5, 0.6);
	//right swing
	glPushMatrix();
	if (OnOff) {
		glRotatef(-swing_rotate1, 1, 0, 0);
	}
	glPushMatrix();
	//right ropes
	glTranslatef(2, -3.5, 0);
	Draw_Textured_Cylinder(0.05, 3.5, 70, rope_TexID);
	glTranslatef(-1, 0, 0);
	Draw_Textured_Cylinder(0.05, 3.5, 70, rope_TexID);
	glPopMatrix();
	glPushMatrix();
	//right seat
	glPushMatrix();
	glTranslatef(1.5, -3.6, -0.10);
	Draw_Textured_Box(1.2, 0.1, 1, seesaw_texID);
	glPopMatrix();
	glPopMatrix();
	if (OnOff) {
		glRotatef(swing_rotate1, 1, 0, 0);
	}
	glPushMatrix();
	//left swing
	if (OnOff) {
		glRotatef(swing_rotate1, 1, 0, 0);
	}
	glPushMatrix();
	glPushMatrix();
	glTranslatef(-2, -3.5, 0);
	Draw_Textured_Cylinder(0.05, 3.5, 70, rope_TexID);
	glTranslatef(1, 0, 0);
	Draw_Textured_Cylinder(0.05, 3.5, 70, rope_TexID);
	glPopMatrix();
	//left seat
	glPushMatrix();
	glTranslatef(-1.5, -3.6, -0.10);
	Draw_Textured_Box(1.2, 0.1, 1, seesaw_texID);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	////glEnable(GL_LIGHTING);
	glPopMatrix();



}

void Draw_Carousle() {

	glPushMatrix();
	if (OnOff)
	{
		glRotatef(carousle_rotate, 0, 1, 0);
	}
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	//gldisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(0.8, 1.2, 1.7);
	Draw_Person(0.5);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 0, 1);
	solid_Cylinder(2, 1, 100, 0, 0, 1);
	glTranslatef(0, 0.8, 0);
	solid_Cylinder(3, 0.3, 100, 1, 0, 0);
	glPopMatrix();


	glPushMatrix();
	Draw_Textured_Box(0.095, 3, 0.095, metal_TexID);
	//Draw_Textured_Cylinder(0.1, 3, 100, metal_TexID);
	glPopMatrix();
	glPushMatrix();

	Draw_Carousle_Handle();
	for (int i = 0; i < 8; i++) {
		glRotatef(45, 0, 1, 0);
		Draw_Carousle_Handle();
	}
	glPopMatrix();


	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);
	glPopMatrix();
	glPopMatrix();


}
void Draw_Solid_Disc(float cx, float cy, float r, int num_segments) {
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(cx, cy); // Center of disk
	for (int i = 0; i <= num_segments + 2; i++) {
		float angle = 2.0f * PI * (float)i / (float)num_segments;
		float x = r * cosf(angle);
		float y = r * sinf(angle);
		glVertex2f(cx + x, cy + y);
	}
	glEnd();
}
void solid_Cylinder(float radius, float height, float slices, float r, float g, float b) {
	glPushMatrix();
	glPushMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslatef(0, height, 0);
	glRotatef(90, 1, 0, 0);
	Draw_Solid_Disc(0, 0, radius, 100);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	Draw_Cylinder(radius, height, slices);
	glPopMatrix();

	glPushMatrix();

	glPushMatrix();

	glRotatef(90, 1, 0, 0);
	Draw_Solid_Disc(0, 0, radius, 100);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();


}
void Draw_Carousle_Handle() {

	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	//gldisable(GL_LIGHTING);


	glPushMatrix();
	glTranslatef(1.9, 0, 0);
	Draw_Textured_Box(0.095, 3, 0.095, metal_TexID);
	//Draw_Textured_Cylinder(0.1, 3, 100, metal_TexID);
	glPopMatrix();

	glPushMatrix();

	glTranslatef(1.95, 2.95, 0);
	glRotatef(90, 0, 0, 1);
	Draw_Textured_Box(0.095, 2, 0.095, metal_TexID);
	//Draw_Textured_Cylinder(0.1, 2, 100, metal_TexID);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);
	glPopMatrix();





}
//light0
void Draw_Solar_System() {
	if (enable_lighting) glEnable(GL_LIGHTING);
	if (light0) glEnable(GL_LIGHT0);
	else glDisable(GL_LIGHT0);
	GLfloat light_position1[] = { sunX, sunY, sunZ, 1.0 };
	GLfloat light_diffuse_sphere1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_specular_sphere1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse_sphere1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular_sphere1);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, SunTextureId);
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);//GL_OBJECT_LINEAR GL_EYE_LINEAR GL_SPHERE_MAP
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	if (OnOff)
	glRotated(ObjectRotatingAngle, 0.0, 1, 0.0);
	glutSolidSphere(sunR, 100, 100);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);

	//The earth
	glBindTexture(GL_TEXTURE_2D, EarthTextureId);
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);//GL_OBJECT_LINEAR GL_EYE_LINEAR GL_SPHERE_MAP
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glColor3f(0.4901, 0.8117, 0.6705);
	if (OnOff)
	glRotated(ObjectRotatingAngle, 0.0, 1, 0.0);
	glTranslatef(2.5, 0, 0);
	glutSolidSphere(earthR, 100, 100);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);

	//Rotating the moon around the earth
	glBindTexture(GL_TEXTURE_2D, MoonTextureId);
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);//GL_OBJECT_LINEAR GL_EYE_LINEAR GL_SPHERE_MAP
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	if(OnOff)
	glRotated(ObjectRotatingAngle * 2.0, 0, 1, 0.0);
	glPushMatrix();
	glTranslatef(0.8, 0, 0);
	glutSolidSphere(moonR, 100, 100);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();

	glPopMatrix();

	//setup sun lighting





}
void Draw_Tree(float height) {



	glPushMatrix();
	glScalef(height, height, height);
	if (enable_textures) glEnable(GL_TEXTURE_2D);
	else glDisable(GL_TEXTURE_2D);
	set_Material_to_gold();

	//treetop
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, tree_top_TexID);
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);//GL_OBJECT_LINEAR GL_EYE_LINEAR GL_SPHERE_MAP
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glPushMatrix();
	glTranslatef(0, 4, 0);
	glRotatef(-90, 1, 0, 0);
	set_Material_to_gold();
	glutSolidCone(1, 1.5, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 3, 0);
	glRotatef(-90, 1, 0, 0);
	set_Material_to_gold();
	glutSolidCone(1.25, 1.5, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 2, 0);
	glRotatef(-90, 1, 0, 0);
	set_Material_to_gold();
	glutSolidCone(1.5, 1.5, 100, 100);
	glPopMatrix();
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();

	//tree trunk
	set_Material_to_jade();
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	//gldisable(GL_LIGHTING);
	Draw_Textured_Cylinder(0.5, 3, 100, tree_trunk_TexID);
	glEnable(GL_TEXTURE_2D);
	////glEnable(GL_LIGHTING);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	////gldisable(GL_LIGHTING);
	glPopMatrix();





}
float randomFloat(float min, float max) {
	return min + ((float)rand() / RAND_MAX) * (max - min);
}
//light1
void Draw_Forest(float h1, float h2, float h3, float h4) {//light1
	if (enable_lighting) glEnable(GL_LIGHTING);
	if (light1) glEnable(GL_LIGHT1);
	else glDisable(GL_LIGHT1);
	GLfloat light_position[] = { 0,0, 0, 1.0 };
	GLfloat light_diffuse_sphere[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_specular_sphere[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse_sphere);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular_sphere);
	set_Material_to_gold();
	if (enable_textures) { glEnable(GL_TEXTURE_2D); }
	else { glDisable(GL_TEXTURE_2D); }
	////glEnable(GL_LIGHTING);
	set_Material_to_gold();
	glPushMatrix();
	Draw_Tree(h1);
	glTranslatef(2, 0, 0);
	Draw_Tree(h2);
	glTranslatef(2, 0, 0);
	Draw_Tree(h3);
	glTranslatef(2, 0, 0);
	Draw_Tree(h4);
	glTranslatef(2, 0, 0);
	glPopMatrix();
}
void Draw_Sandbox(float height, float width, float length) {

	glPushMatrix();


	glDisable(GL_TEXTURE_2D);
	//gldisable(GL_LIGHTING);
	Draw_Textured_Box(width, height, length, sand_TexID);
	glTranslatef(width / 2 + 0.05, 0, 0);
	Draw_Textured_Box(0.2, height + 0.5, length, wood_texID);
	glTranslatef(-2 * (width / 2 + 0.05), 0, 0);
	Draw_Textured_Box(0.2, height + 0.5, length, wood_texID);
	glTranslatef(width / 2 + 0.15, 0, 0);
	glTranslatef(-0.1, 0, length / 2 + 0.1);
	Draw_Textured_Box(width + 0.3, height + 0.5, 0.2, wood_texID);
	glTranslatef(0, 0, -2 * (length / 2 + 0.1));
	Draw_Textured_Box(width + 0.3, height + 0.5, 0.2, wood_texID);
	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);


	glPopMatrix();







}
void Draw_Bench(int name) {
	glEnable(GL_LIGHTING);
	set_Material_to_turquoise();
	// Assuming you're using light 0

	   // Set up the position and properties of light 0
	glPushMatrix();
	//draw bench frame
	glPushMatrix();

	Draw_Textured_Box(0.1, 1, 0.1, metal_TexID);
	glTranslatef(2, 0, 0);
	Draw_Textured_Box(0.1, 1, 0.1, metal_TexID);
	glTranslatef(0, 0, -1);
	Draw_Textured_Box(0.1, 1, 0.1, metal_TexID);
	glTranslatef(-2, 0, 0);
	Draw_Textured_Box(0.1, 1, 0.1, metal_TexID);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 1, 0);
	glRotatef(90, 0, 0, 1);
	Draw_Textured_Box(0.1, 2, 0.1, metal_TexID);
	glTranslatef(0, 0, -1);
	Draw_Textured_Box(0.1, 2, 0.1, metal_TexID);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 1, -1);
	glRotatef(90, 1, 0, 0);
	Draw_Textured_Box(0.1, 1, 0.1, metal_TexID);
	glTranslatef(-2, 0, 0);
	Draw_Textured_Box(0.1, 1, 0.1, metal_TexID);
	glPopMatrix();

	glPushMatrix();

	glTranslatef(0, 1, -1);
	glRotatef(-20, 1, 0, 0);
	Draw_Textured_Box(0.1, 1, 0.1, metal_TexID);
	glRotatef(20, 1, 0, 0);
	glTranslatef(2, 0, 0);
	glRotatef(-20, 1, 0, 0);
	Draw_Textured_Box(0.1, 1, 0.1, metal_TexID);
	glPopMatrix();

	//draw planks
	glPushMatrix();
	glTranslatef(1, 1, 0);
	Draw_Textured_Box(2.7, 0.1, 0.25, plank_TexID);
	glTranslatef(0, 0, -0.3);
	Draw_Textured_Box(2.7, 0.1, 0.25, plank_TexID);
	glTranslatef(0, 0, -0.3);
	Draw_Textured_Box(2.7, 0.1, 0.25, plank_TexID);
	glTranslatef(0, 0, -0.3);
	Draw_Textured_Box(2.7, 0.1, 0.25, plank_TexID);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 1.3, -1.05);
	glRotatef(70, 1, 0, 0);
	Draw_Textured_Box(2.7, 0.1, 0.25, plank_TexID);
	glTranslatef(0, 0, -0.3);
	Draw_Textured_Box(2.7, 0.1, 0.25, plank_TexID);
	glTranslatef(0, 0, -0.3);
	Draw_Textured_Box(2.7, 0.1, 0.25, plank_TexID);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0.6, -0.1);
	Draw_Person_sitting(0.5, name);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);

	glPopMatrix();

}
void Draw_Fence() {
	glEnable(GL_LIGHTING);
	set_Material_to_ruby();
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	//gldisable(GL_LIGHTING);


	glPushMatrix();

	Draw_Textured_Box(0.3, 2.5, 0.1, plank2_TexID);
	glTranslatef(0.4, 0, 0);
	Draw_Textured_Box(0.3, 2.5, 0.1, plank2_TexID);
	glTranslatef(0.4, 0, 0);
	Draw_Textured_Box(0.3, 2.5, 0.1, plank2_TexID);
	glTranslatef(0.4, 0, 0);
	Draw_Textured_Box(0.3, 2.5, 0.1, plank2_TexID);
	Draw_Textured_Box(0.3, 2.5, 0.1, plank2_TexID);
	glTranslatef(0.4, 0, 0);
	Draw_Textured_Box(0.3, 2.5, 0.1, plank2_TexID);
	glTranslatef(0.4, 0, 0);
	Draw_Textured_Box(0.3, 2.5, 0.1, plank2_TexID);
	glTranslatef(0.4, 0, 0);
	Draw_Textured_Box(0.3, 2.5, 0.1, plank2_TexID);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.7, 0.7, -0.1);
	glRotatef(90, 0, 0, 1);
	Draw_Textured_Box(0.3, 3, 0.1, plank2_TexID);
	glTranslatef(0.5, 0, 0);
	Draw_Textured_Box(0.3, 3, 0.1, plank2_TexID);
	glTranslatef(0.5, 0, 0);
	Draw_Textured_Box(0.3, 3, 0.1, plank2_TexID);
	glTranslatef(0.5, 0, 0);
	Draw_Textured_Box(0.3, 3, 0.1, plank2_TexID);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);
	glPopMatrix();
	glDisable(GL_LIGHTING);
}
void Draw_Long_Fence(int lenght) {

	for (int i = 0; i < lenght; i++) {
		Draw_Fence();
		glTranslatef(2.8, 0, 0);
	}

}
void oak_Wood(int length, int height) {
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	//gldisable(GL_LIGHTING);

	Draw_Textured_Box(1, 1, 1, oak_wood);


	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);
	glPopMatrix();
}
void birch_Wood(int length, int height) {
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	//gldisable(GL_LIGHTING);

	Draw_Textured_Box(1, 1, 1, birch_wood);


	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);
	glPopMatrix();
}
void brick(int length, int height) {
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	//gldisable(GL_LIGHTING);

	Draw_Textured_Box(1, 1, 1, brick_texID);


	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);
	glPopMatrix();
}
void dsbrick(int length, int height) {
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	//gldisable(GL_LIGHTING);

	Draw_Textured_Box(1, 1, 1, dsbrick_texID);


	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);
	glPopMatrix();
}
void door() {
	glPushMatrix();
	Draw_Textured_Box(1, 3, 0.1, door_TexID);
	glPopMatrix();
}
void door2() {
	glPushMatrix();
	Draw_Textured_Box(1, 3, 0.1, door2_TexID);
	glPopMatrix();
}
void stone(int length, int height) {
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	//gldisable(GL_LIGHTING);

	Draw_Textured_Box(1, 1, 1, stone_TexID);


	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);
	glPopMatrix();
}
//light2
void Draw_Steve() {

	if (enable_lighting) glEnable(GL_LIGHTING);
	if (light2) glEnable(GL_LIGHT2);
	else glDisable(GL_LIGHT2);
	GLfloat light_position[] = { XX, 0, ZZ, 1.0 };
	GLfloat light_diffuse_sphere[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_specular_sphere[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT2, GL_POSITION, light_position);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse_sphere);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular_sphere);


	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	////gldisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	Draw_Body(1, 1.5, 0.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.25, 1.5, 0);
	glRotatef(steve_l, 1, 0, 0);
	glTranslatef(0, -1.5, 0);
	Draw_Legs(0.5, 1.5, 0.5);//right leg

	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.25, 1.5, 0);
	glRotatef(-steve_l, 1, 0, 0);
	glTranslatef(0, -1.5, 0);
	Draw_Legs(0.5, 1.5, 0.5);//left leg
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.7, 3, 0);
	glRotatef(-steve_l, 1, 0, 0);
	glTranslatef(0, -1.5, 0);
	Draw_Hands(0.5, 1.5, 0.5);//left hand
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.7, 3, 0);
	glRotatef(steve_l, 1, 0, 0);
	glTranslatef(0, -1.5, 0);
	Draw_Hands(0.5, 1.5, 0.5);//right hand
	glPopMatrix();

	glPushMatrix();

	glTranslatef(0, 3, 0);
	Draw_Head(1, 1, 1);
	glPopMatrix();
	//

	//Draw_Hands(0.5, 1.5, 0.5);
	glEnable(GL_TEXTURE_2D);
	////glEnable(GL_LIGHTING);
	glPopMatrix();
	//glDisable(GL_LIGHTING);
}
void Draw_Head(float width, float height, float depth) {
	// Enable texture 2D
	glEnable(GL_TEXTURE_2D);

	// Bind the texture for the box sides
	glBindTexture(GL_TEXTURE_2D, face_front);

	// Draw the long box
	glBegin(GL_QUADS);

	// Front face
	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, depth / 2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, head_back);

	// Draw the long box
	glBegin(GL_QUADS);
	// Back face
	glTexCoord2f(0, 0); glVertex3f(width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(-width / 2, height, -depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, height, -depth / 2);
	glEnd();
	// Left face
	glBindTexture(GL_TEXTURE_2D, head_left);

	// Draw the long box
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(-width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, -depth / 2);
	glEnd();

	// Right face
	glBindTexture(GL_TEXTURE_2D, head_right);

	// Draw the long box
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, -depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, height, depth / 2);
	glEnd();
	// Top face
	glBindTexture(GL_TEXTURE_2D, head_top);

	// Draw the long box
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-width / 2, height, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, height, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, depth / 2);

	// Bottom face
	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, 0.0, -depth / 2);

	glEnd();

	// Disable texture 2D
	glDisable(GL_TEXTURE_2D);
}
void Draw_Body(float width, float height, float depth) {	// Enable texture 2D
	glEnable(GL_TEXTURE_2D);

	// Bind the texture for the box sides
	glBindTexture(GL_TEXTURE_2D, body_front);

	// Draw the long box
	glBegin(GL_QUADS);

	// Front face
	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, depth / 2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, body_back);

	// Draw the long box
	glBegin(GL_QUADS);
	// Back face
	glTexCoord2f(0, 0); glVertex3f(width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(-width / 2, height, -depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, height, -depth / 2);

	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(-width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, -depth / 2);

	glTexCoord2f(0, 0); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, -depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, height, depth / 2);

	glTexCoord2f(0, 0); glVertex3f(-width / 2, height, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, height, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, depth / 2);

	// Bottom face
	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, 0.0, -depth / 2);

	glEnd();

	// Disable texture 2D
	glDisable(GL_TEXTURE_2D);
}
void Draw_Hands(float width, float height, float depth) {	// Enable texture 2D
	glEnable(GL_TEXTURE_2D);

	// Bind the texture for the box sides
	glBindTexture(GL_TEXTURE_2D, hands);

	// Draw the long box
	glBegin(GL_QUADS);

	// Front face
	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, depth / 2);


	// Back face
	glTexCoord2f(0, 0); glVertex3f(width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(-width / 2, height, -depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, height, -depth / 2);

	// Left face

	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(-width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, -depth / 2);

	glTexCoord2f(0, 0); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, -depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, height, depth / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, hands_up);

	// Draw the long box
	glBegin(GL_QUADS);
	//top
	glTexCoord2f(0, 0); glVertex3f(-width / 2, height, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, height, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, depth / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, hands_down);

	// Draw the long box
	glBegin(GL_QUADS);

	// Bottom face
	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, 0.0, -depth / 2);

	glEnd();

	// Disable texture 2D
	glDisable(GL_TEXTURE_2D);
}
void Draw_Legs(float width, float height, float depth) {	// Enable texture 2D
	glEnable(GL_TEXTURE_2D);

	// Bind the texture for the box sides
	glBindTexture(GL_TEXTURE_2D, legs);

	// Draw the long box
	glBegin(GL_QUADS);

	// Front face
	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, depth / 2);





	// Back face
	glTexCoord2f(0, 0); glVertex3f(width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(-width / 2, height, -depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, height, -depth / 2);

	// Left face

	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(-width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, -depth / 2);

	glTexCoord2f(0, 0); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, -depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, height, depth / 2);

	glTexCoord2f(0, 0); glVertex3f(-width / 2, height, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(width / 2, height, -depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, height, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(-width / 2, height, depth / 2);

	// Bottom face
	glTexCoord2f(0, 0); glVertex3f(-width / 2, 0.0, -depth / 2);
	glTexCoord2f(1, 0); glVertex3f(-width / 2, 0.0, depth / 2);
	glTexCoord2f(1, 1); glVertex3f(width / 2, 0.0, depth / 2);
	glTexCoord2f(0, 1); glVertex3f(width / 2, 0.0, -depth / 2);

	glEnd();

	// Disable texture 2D
	glDisable(GL_TEXTURE_2D);
}
void Draw_Bouncing_Ball(float top_boundary, float ball_radius) {
	//set globals
	ball_boundary = top_boundary;
	ball_rad = ball_radius;

	glPushMatrix();


	//draw bouncing ball

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, ball_TexID);
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);//GL_OBJECT_LINEAR GL_EYE_LINEAR GL_SPHERE_MAP
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	if (OnOff) {
		glTranslatef(0, ball_height, 0);

		glScalef(ball_scale_factor_x, ball_scale_factor_y, ball_scale_factor_z);
	}
	glutSolidSphere(ball_radius, 100, 100);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);

	glPopMatrix();



	glPopMatrix();

}
void Draw_Steve_Bouncing() {
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	//gldisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	Draw_Body(1, 1.5, 0.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.25, 1.5, 0);

	glTranslatef(0, -1.5, 0);
	Draw_Legs(0.5, 1.5, 0.5);//right leg

	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.25, 1.5, 0);

	glTranslatef(0, -1.5, 0);
	Draw_Legs(0.5, 1.5, 0.5);//left leg
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.7, 3, 0);

	glTranslatef(0, -1.5, 0);
	Draw_Hands(0.5, 1.5, 0.5);//left hand
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.7, 3, 0);
	glRotatef(-30, 1, 0, 0);
	glTranslatef(0, -1.5, 0);
	Draw_Hands(0.5, 1.5, 0.5);//right hand
	glPopMatrix();

	glPushMatrix();

	glTranslatef(0, 3, 0);
	Draw_Head(1, 1, 1);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);
	glTranslatef(-0.7, 0, 1);
	glScalef(0.5, 0.5, 0.5);
	Draw_Bouncing_Ball(3, 1);
	glDisable(GL_TEXTURE_2D);
	//gldisable(GL_LIGHTING);
	glPushMatrix();

	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);
	glPopMatrix();
}
void Draw_Skybox(double D, double d)
{
	if (enable_textures) glEnable(GL_TEXTURE_2D);
	else glDisable(GL_TEXTURE_2D);


	if (enable_textures) glBindTexture(GL_TEXTURE_2D, SkyboxTextures[tod][SKY_RIGHT]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(+D - d, -D, -D);
	glTexCoord2f(1, 0); glVertex3f(+D - d, -D, +D);
	glTexCoord2f(1, 1); glVertex3f(+D - d, +D, +D);
	glTexCoord2f(0, 1); glVertex3f(+D - d, +D, -D);
	glEnd();
	//left
	if (enable_textures)glBindTexture(GL_TEXTURE_2D, SkyboxTextures[tod][SKY_LEFT]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-D + d, -D, +D);
	glTexCoord2f(1, 0); glVertex3f(-D + d, -D, -D);
	glTexCoord2f(1, 1); glVertex3f(-D + d, +D, -D);
	glTexCoord2f(0, 1); glVertex3f(-D + d, +D, +D);
	glEnd();
	//up
	if (enable_textures)glBindTexture(GL_TEXTURE_2D, SkyboxTextures[tod][SKY_UP]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-D, +D - d, -D);
	glTexCoord2f(1, 0); glVertex3f(+D, +D - d, -D);
	glTexCoord2f(1, 1); glVertex3f(+D, +D - d, +D);
	glTexCoord2f(0, 1); glVertex3f(-D, +D - d, +D);
	glEnd();
	//down
	if (enable_textures)glBindTexture(GL_TEXTURE_2D, SkyboxTextures[tod][SKY_DOWN]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-D, -D + d, +D);
	glTexCoord2f(1, 0); glVertex3f(+D, -D + d, +D);
	glTexCoord2f(1, 1); glVertex3f(+D, -D + d, -D);
	glTexCoord2f(0, 1); glVertex3f(-D, -D + d, -D);
	glEnd();
	//back
	if (enable_textures)glBindTexture(GL_TEXTURE_2D, SkyboxTextures[tod][SKY_BACK]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-D, -D, -D + d);
	glTexCoord2f(1, 0); glVertex3f(+D, -D, -D + d);
	glTexCoord2f(1, 1); glVertex3f(+D, +D, -D + d);
	glTexCoord2f(0, 1); glVertex3f(-D, +D, -D + d);
	glEnd();
	//front
	if (enable_textures)glBindTexture(GL_TEXTURE_2D, SkyboxTextures[tod][SKY_FRONT]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(+D, -D, +D - d);
	glTexCoord2f(1, 0); glVertex3f(-D, -D, +D - d);
	glTexCoord2f(1, 1); glVertex3f(-D, +D, +D - d);
	glTexCoord2f(0, 1); glVertex3f(+D, +D, +D - d);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
void Draw_House() {
	glPushMatrix();
	Draw_Birch_Wall(4, 4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, 5);
	Draw_Birch_Wall(4, 4);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(-6, 0, 0);
	Draw_Birch_Wall(6, 4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1, 4.5, -0.5);
	glRotatef(90, 1, 0, 0);
	Draw_Birch_Wall(5, 6);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(4, 0, 5);
	glRotatef(90, 0, 1, 0);
	Draw_Birch_Wall(1, 4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(4, 3, 4);
	glRotatef(90, 0, 1, 0);
	Draw_Stone_Wall(2, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(4.45, 0, 3);
	glRotatef(90, 0, 1, 0);
	door();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(4.45, 0, 2);
	glRotatef(270, 0, 1, 0);
	door2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3, 0, 1);
	Draw_Birch_Wall(1, 4);
	glPopMatrix();
	glPushMatrix();
	Draw_Roof();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2, 0, -1);
	Draw_Stone_Wall(1, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(4, 0, -1);
	Draw_Stone_Wall(1, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2, 0, 6);
	Draw_Stone_Wall(1, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(4, 0, 6);
	Draw_Stone_Wall(1, 5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, 0, -1);
	Draw_Brick_Wall(5, 1);
	glTranslatef(0, 4, 0);
	Draw_Brick_Wall(5, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1, 1, -1);
	Draw_DSBrick_wall(1, 3);
	glTranslatef(4, 0, 0);
	Draw_DSBrick_wall(1, 3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 7);
	glPushMatrix();
	glTranslatef(-1, 0, -1);
	Draw_Brick_Wall(5, 1);
	glTranslatef(0, 4, 0);
	Draw_Brick_Wall(5, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1, 1, -1);
	Draw_DSBrick_wall(1, 3);
	glTranslatef(4, 0, 0);
	Draw_DSBrick_wall(1, 3);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 5);
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glTranslatef(-1, 0, -1);
	Draw_Brick_Wall(6, 1);
	glTranslatef(0, 4, 0);
	Draw_Brick_Wall(6, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1, 1, -1);
	Draw_DSBrick_wall(1, 3);
	glTranslatef(5, 0, 0);
	Draw_DSBrick_wall(1, 3);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();


	glTranslatef(5, 0, 6);
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0, 4, 0);
	Draw_Brick_Wall(6, 1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, 0);
	Draw_DSBrick_wall(1, 4);
	glTranslatef(5, 0, 0);
	Draw_DSBrick_wall(1, 4);
	glPopMatrix();
	glPopMatrix();

}
void Draw_Birch_Wall(int width, int height) {

	glPushMatrix();
	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {
			glTranslatef(1, 0, 0);
			birch_Wood(1, 1);
		}
		glTranslatef(-width, 1, 0);
	}
	glPopMatrix();
}
void Draw_Stone_Wall(int width, int height) {

	glPushMatrix();
	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {
			glTranslatef(1, 0, 0);
			stone(1, 1);
		}
		glTranslatef(-width, 1, 0);
	}
	glPopMatrix();
}
void Draw_Brick_Wall(int width, int height) {

	glPushMatrix();
	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {
			glTranslatef(1, 0, 0);
			brick(1, 1);
		}
		glTranslatef(-width, 1, 0);
	}
	glPopMatrix();
}
void Draw_DSBrick_wall(int width, int height) {

	glPushMatrix();
	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {
			glTranslatef(1, 0, 0);
			dsbrick(1, 1);
		}
		glTranslatef(-width, 1, 0);
	}
	glPopMatrix();
}
void Draw_Roof() {

	glPushMatrix();
	glTranslatef(-2, 5.5, -1.5);
	glRotatef(90, 1, 0, 0);
	Draw_Stone_Wall(7, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1, 6.5, -0.5);
	glRotatef(90, 1, 0, 0);
	Draw_Stone_Wall(5, 6);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 7.5, 0.5);
	glRotatef(90, 1, 0, 0);
	Draw_Stone_Wall(3, 4);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1, 8.5, 1.5);
	glRotatef(90, 1, 0, 0);
	Draw_Stone_Wall(1, 2);
	glPopMatrix();






}
//set meterials
void set_Material_to_silver() {

	// Define silver material properties
	GLfloat silverAmbient[] = { 0.19225f, 0.19225f, 0.19225f, 1.0f };
	GLfloat silverDiffuse[] = { 0.50754f, 0.50754f, 0.50754f, 1.0f };
	GLfloat silverSpecular[] = { 0.508273f, 0.508273f, 0.508273f, 1.0f };
	GLfloat silverShininess = 51.2f;

	// Set the material properties
	glMaterialfv(GL_FRONT, GL_AMBIENT, silverAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, silverDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, silverSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, silverShininess);
}
void set_Material_to_gold() {

	// Define gold material properties
	GLfloat goldAmbient[] = { 0.24725f, 0.1995f, 0.0745f, 1.0f };
	GLfloat goldDiffuse[] = { 0.75164f, 0.60648f, 0.22648f, 1.0f };
	GLfloat goldSpecular[] = { 0.628281f, 0.555802f, 0.366065f, 1.0f };
	GLfloat goldShininess = 80.2f;

	// Set the material properties
	glMaterialfv(GL_FRONT, GL_AMBIENT, goldAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, goldDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, goldSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, goldShininess);
}
void set_Material_to_jade() {
	GLfloat mat_ambient[] = { 0.135, 0.2225, 0.1575, 0.95 };
	GLfloat mat_diffuse[] = { 0.54, 0.89, 0.63, 0.95 };
	GLfloat mat_specular[] = { 0.316228, 0.316228, 0.316228, 0.95 };
	GLfloat shine[] = { 0.1 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shine);
}
void set_Material_to_obsidian() {
	GLfloat mat_ambient[] = { 0.05375, 0.05, 0.06625, 0.82 };
	GLfloat mat_diffuse[] = { 0.18275, 0.17, 0.22525, 0.82 };
	GLfloat mat_specular[] = { 0.332741, 0.328634, 0.346435, 0.82 };
	GLfloat shine[] = { 0.3 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shine);
}
void set_Material_to_turquoise() {
	GLfloat mat_ambient[] = { 0.1, 0.18725, 0.1745, 0.8 };
	GLfloat mat_diffuse[] = { 0.396, 0.74151, 0.69102, 0.8 };
	GLfloat mat_specular[] = { 0.297254, 0.30829, 0.306678, 0.8 };
	GLfloat shine[] = { 0.1 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shine);
}
void set_Material_to_brass() {
	GLfloat mat_ambient[] = { 0.329412, 0.223529, 0.027451, 1.0 };
	GLfloat mat_diffuse[] = { 0.780392, 0.568627, 0.113725, 1.0 };
	GLfloat mat_specular[] = { 0.992157, 0.941176, 0.807843, 1.0 };
	GLfloat shine[] = { 27.8974 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shine);
}
void set_Material_to_ruby() {
	GLfloat mat_ambient[] = { 0.1745, 0.01175, 0.01175, 0.55 };
	GLfloat mat_diffuse[] = { 0.61424, 0.04136, 0.04136, 0.55 };
	GLfloat mat_specular[] = { 0.727811, 0.626959, 0.626959, 0.55 };
	GLfloat shine[] = { 0.6 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shine);
}
