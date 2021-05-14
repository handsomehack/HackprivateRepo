#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkPolyData.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkLight.h>
#include <vtkPlane.h>
#include <vtkShrinkFilter.h>
#include <vtkClipDataSet.h>
#include <vtkSTLReader.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_actionFileOpen_triggered();
    void on_horizontalSlider_sliderMoved(int position);
    void on_checkBox_clicked(bool checked);
    void on_ClipBox_clicked(bool checked);
    void on_ShrinkBox_clicked(bool checked);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    vtkSmartPointer<vtkLight> light = vtkSmartPointer<vtkLight>::New();
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkCubeSource> cubeSource;
    vtkSmartPointer<vtkDataSetMapper> mapper;
    vtkSmartPointer<vtkActor> actor;
    vtkSmartPointer<vtkNamedColors> colors;
    vtkSmartPointer<vtkSTLReader>reader;
    vtkSmartPointer<vtkPlane> planeLeft = vtkSmartPointer<vtkPlane>::New();
    vtkSmartPointer<vtkClipDataSet> clipfilter = vtkSmartPointer<vtkClipDataSet>::New();
    vtkSmartPointer<vtkShrinkFilter> shrinkfilter = vtkSmartPointer<vtkShrinkFilter>::New();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
