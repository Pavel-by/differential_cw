#pragma once

#include "figure.h"
#include "figurewrapper.h"
#include "shaderprogramwrapper.h"
#include "viewmatrixwrapper.h"

#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>

class Drawer : public QOpenGLWidget
{
    Q_OBJECT

public:
    Drawer(QWidget *parent = nullptr);
    ~Drawer() override;

    QMatrix4x4 proj;

private slots:
    void depenceChanged();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    ShaderProgramWrapper _programWrapper = ShaderProgramWrapper(":/res/base.vert", ":/res/base.frag");
    QVector<Figure> _figures;
    ViewMatrixWrapper _viewWrapper;
    FigureWrapper _figureWrapper;
};

