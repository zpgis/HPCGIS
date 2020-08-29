
///****************************************************************************
/// @Author        : 
/// @Create time   :   2020-08-28                                                    
/// @Last modified :   2020-08-28                                                              
/// @Filename      :   shader.h                                                              
/// @Description   :   对着色器的使用进行封装                                                              
///****************************************************************************

#pragma once

#ifndef __SHADER_H__
#define __SHADER_H__

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
class Shader
{
public:
	GLuint rendererId;
	Shader();
	~Shader();

	void use();
	void create(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath);
private:
	int getShaderFromFile(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath, std::string* vertexShaderCode, std::string* fragmentShaderCode
	);
	int linkShader(const char* vertexShaderCode, const char* fragmentShaderCode);
	//int getUniform(const std::string& name) const;
	void checkCompileErrors(GLuint shader, std::string type);
	
};


#endif // __SHADER_H__
