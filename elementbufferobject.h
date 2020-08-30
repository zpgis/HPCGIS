
///****************************************************************************
/// @Author        : 
/// @Create time   :  2020-08-30                                                     
/// @Last modified :                                                                 
/// @Filename      :  elementbufferobject.h                                                               
/// @Description   :  Ԫ�ػ������ebo��Ҳ�������������Index buffer object���û�������Ҫ�����洢�����������Ϣ                                                               
///****************************************************************************

#pragma once
#ifndef __ELEMENTBUFFEROBJECT_H__
#define __ELEMENTBUFFEROBJECT_H__

#include <glad/glad.h>

class ElementBufferObject {
public:
	ElementBufferObject(unsigned int size, const void* data, GLenum usage = 0x88e4 /*GL_STATIC_DRAW*/);
	~ElementBufferObject();

private:
	unsigned int elementbufferobject;
};

#endif // !__ELEMENTBUFFEROBJECT_H__
