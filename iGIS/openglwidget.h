#pragma once

/**************************************************************************
** class name:  OpenGLWidget
**
** description: OpenGL widget, public inherited from QOpengGLWidget
				�����������ڣ�չʾ�����õ�
**
** last change: 2020-08-25
**************************************************************************/

#ifndef __OPENGLWIDGET_H__
#define __OPENGLWIDGET_H__

#include <glad/glad.h>
#include <QOpenGLWidget>
#include "shader.h"

class OpenGLWidget :public QOpenGLWidget
{
	Q_OBJECT
public:
	explicit OpenGLWidget(QWidget* parent = nullptr);
	~OpenGLWidget();
protected:
	void initializeGL() override;
	void resizeGL(int w, int h) override;
	void paintGL() override;
private:

	Shader *shader;
public:
	GLuint vertex_array_object;
	GLuint vertex_buffer_object;
	GLuint element_buffer_object;
};

#endif // !__OPENGLWIDGET_H__
