#ifndef DEF_GAMESETUP_HPP
#define DEF_GAMESETUP_HPP
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <assert.h>
#include"common/objloader.hpp"
#include"common/skybox.h"
#include"common/car.h"
#include"common/camera.h"
#include<GL/gl.h>
#include<GL/glu.h>
#include"common/texture.hpp"
#include<C:\library\freeglut\include\GL\freeglut.h>

class setup
{
	public:
		
	setup();
	~setup();
	void init();
	void keyboard(unsigned char key, int x, int y);
	void mouseMove(int mx,int my);
	void specialKey(int key, int x, int y);
	void mouseState(int button, int state, int x, int y);
	void update();
	void draw();
	int loadHeightmap(const char * name,int width, int height);
	void renderHeightMap(float size,float h);
	BYTE hHeightField[512][512];
	
	private:
		
	skybox *sky;
	vehicule * car;
	camera * cam;
	int width_,height_;
	textures* tex;
	GLuint texture;




	
	
	
};

#endif

