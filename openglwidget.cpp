#include "openglwidget.h"

#include <QDebug>


/*************************************/
/*                                   */
/*         OpenGLWidget              */
/*                                   */
/*************************************/

OpenGLWidget::OpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent), shader(nullptr)
{

}

OpenGLWidget::~OpenGLWidget()
{
    glDeleteVertexArrays(1, &vertex_array_object);
    glDeleteBuffers(1, &vertex_buffer_object);
}

/**********************************************/
/*                                            */
/*       Override QOpenGLWidget               */
/*                                            */
/**********************************************/

void OpenGLWidget::initializeGL() {
    // ��ʼ��glad
    if (gladLoadGL() == 0) {
        qDebug("Failed to initialize GLAD");
    }
    shader = new Shader();
    shader->create("resources/shaders/triangle.vs", "resources/shaders/triangle.fs");

    static const GLfloat triangle[] = {
             //-0.5f, -0.5f, 0.0f,   // ����
             // 0.5f, -0.5f, 0.0f,   // ����
             // 0.0f,  0.5f, 0.0f    // ����
            // ��һ��������
    0.5f, 0.5f, 0.0f,     // ����
    0.5f, -0.5f, 0.0f,    // ����
    -0.5f, -0.5f, 0.0f,   // ����
    // �ڶ���������
    -0.5f, -0.5f, 0.0f,   // ����
    0.5f, 0.5f, 0.0f,     // ����
    -0.5f, 0.5f, 0.0f     // ����
    };
    // ��������(ע�������Ǵ�0��ʼ��)
    unsigned int indices[] = {
        0, 1, 5,              // ��һ��������
        1, 2, 5               // �ڶ���������
    };

    glGenVertexArrays(1, &vertex_array_object);
    glBindVertexArray(vertex_array_object);

    glGenBuffers(1, &vertex_buffer_object);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
    // ���������ݰ�����ǰĬ�ϵĻ�����
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

    glGenBuffers(1, &element_buffer_object);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_object);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    // ���VAO��VBO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void OpenGLWidget::resizeGL(int w, int h) {
    Q_UNUSED(w);
    Q_UNUSED(h);
}

void OpenGLWidget::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    shader->use();
    glBindVertexArray(vertex_array_object);

    //glDrawArrays(GL_POINTS, 0, 1);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindVertexArray(0);
}
