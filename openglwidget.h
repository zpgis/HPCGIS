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
#include "vertexbufferobject.h"
#include "vertexarrayobject.h"
#include "elementbufferobject.h"

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
	VertexArrayObject* vao;
	VertexBufferObject* vbo;
	ElementBufferObject* ebo;
	Shader *shader;
};

#endif // !__OPENGLWIDGET_H__
