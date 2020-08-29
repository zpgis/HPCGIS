#include "shader.h"

#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader() {
}

void Shader::create(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath) {
	std::string vertexShaderCode;
	std::string fragmentShaderCode;

	if (getShaderFromFile(vertexShaderPath, fragmentShaderPath, &vertexShaderCode, &fragmentShaderCode)) {
		return;
	}
	if (linkShader(vertexShaderCode.c_str(), fragmentShaderCode.c_str())) {
		return;
	}
}

Shader::~Shader()
{

}

void Shader::use() {
	glUseProgram(rendererId);
}

int Shader::getShaderFromFile(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath, std::string* vertexShaderCode, std::string* fragmentShaderCode
) 
{
	std::ifstream vertexShaderFile;
	std::ifstream fragmentShaderFile;

	// 当下问读入文件出错，流的状态转换成现编所设置的状态时，会抛出异常，如果不设置，则不会主动抛出异常
	vertexShaderFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	fragmentShaderFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	try
	{
		vertexShaderFile.open(vertexShaderPath);
		fragmentShaderFile.open(fragmentShaderPath);

		std::stringstream vertexShaderStream, fragmentShaderStream;
		vertexShaderStream << vertexShaderFile.rdbuf();
		fragmentShaderStream << fragmentShaderFile.rdbuf();

		vertexShaderFile.close();
		fragmentShaderFile.close();

		*vertexShaderCode = vertexShaderStream.str();
		*fragmentShaderCode = fragmentShaderStream.str();
	}
	catch (const std::ifstream::failure e)
	{
		std::cout << "Load Shader File Error!" << std::endl;
		return -1;
	}

	return 0;
}

int Shader::linkShader(const char* vertexShaderCode, const char* fragmentShaderCode) {
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderCode, nullptr);
	glCompileShader(vertexShader);
	checkCompileErrors(vertexShader, "VERTEX");

	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderCode, nullptr);
	glCompileShader(fragmentShader);
	checkCompileErrors(fragmentShader, "FRAGMENT");

	this->rendererId = glCreateProgram();
	glAttachShader(rendererId, vertexShader);
	glAttachShader(rendererId, fragmentShader);
	glLinkProgram(rendererId);
	checkCompileErrors(rendererId, "PROGRAM");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	return 0;
}

void Shader::checkCompileErrors(GLuint shader, std::string type) {
	GLint success;
	GLchar infoLog[512];

	if (type == "PROGRAM") {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 512, nullptr, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR!\n" << infoLog << std::endl;
		}
	}
	else {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::" << type << "::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}
}