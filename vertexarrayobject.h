
///****************************************************************************
/// @Author        : 
/// @Create time   :   2020-08-30                                                    
/// @Last modified :                                                                 
/// @Filename      :    vertexarrayobject.h                                                             
/// @Description   :   �����������                                                              
///****************************************************************************

#pragma once
#ifndef _VERTEXARRAYOBJECT_H__
#define _VERTEXARRAYOBJECT_H__

#include <glad/glad.h>
class VertexArrayObject {
public:
	VertexArrayObject();
	~VertexArrayObject();
	void bind() const;  // ��
	void unBind() const;// ���
	void specifyVertexAttribute(); // ָ�������������Ϣ������ν���VBO���ݻ���˵����ʲô���ĸ�ʽ����
private:
	unsigned int vertexarrayobject;
};

#endif // !_VERTEXARRAYOBJECT_H__

