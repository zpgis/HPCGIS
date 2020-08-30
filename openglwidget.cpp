#include "openglwidget.h"
#include "vertexbufferobject.h"
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
    //glDeleteVertexArrays(1, &vertex_array_object);
    //glDeleteBuffers(1, &vertex_buffer_object);
    delete vao;
    delete vbo;
    delete ebo;
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
    //-0.5f, -0.5f, 0.0f,   // ����
    //0.5f, 0.5f, 0.0f,     // ����
    -0.5f, 0.5f, 0.0f     // ����
    };
    // ��������(ע�������Ǵ�0��ʼ��)
    unsigned int indices[] = {
        0, 1,              // ��һ��������
        1, 2,               // �ڶ���������
        2,3,
        3,0
    };

    //// ���������ݰ�����ǰĬ�ϵĻ�����
    vbo = new VertexBufferObject(sizeof(triangle), triangle,  GL_STATIC_DRAW);

    vao = new VertexArrayObject();
    vao->specifyVertexAttribute();

    ebo = new ElementBufferObject(sizeof(indices), indices, GL_STATIC_DRAW);

    // ���VAO��VBO
    vao->unBind();
    vbo->unBind();
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void OpenGLWidget::resizeGL(int w, int h) {
    Q_UNUSED(w);
    Q_UNUSED(h);
}

void OpenGLWidget::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    shader->use();
    vao->bind();

    glDrawElements(GL_LINES, 8, GL_UNSIGNED_INT, 0);// ʹ��eboʱ����Ӧ��ʹ��glDrawElements.������ʹ�õ�ǰ��Ҫ����VAO�İ�����

    vao->unBind();
}
