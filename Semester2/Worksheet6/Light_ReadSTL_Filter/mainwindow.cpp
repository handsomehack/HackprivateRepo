
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // standard call to setup Qt UI (same as previously)
    ui->setupUi( this );
	
	// Now need to create a VTK render window and link it to the QtVTK widget
	vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
	ui->qvtkWidget->SetRenderWindow( renderWindow );			// note that vtkWidget is the name I gave to my QtVTKOpenGLWidget in Qt creator
	
	// Now use the VTK libraries to render something. To start with you can copy-paste the cube example code, there are comments to show where the code must be modified.
	//--------------------------------------------- Code From Example 1 --------------------------------------------------------------------------
	
	// Open File
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open STL File"), "./", tr("STL Files(*.stl)"));
	std::string str = fileName.toUtf8().constData();
	reader = vtkSmartPointer<vtkSTLReader>::New();
	reader->SetFileName(str.data());
	reader->Update();

	mapper = vtkSmartPointer<vtkDataSetMapper>::New();
	mapper->SetInputConnection(reader->GetOutputPort());

	// Create an actor that is used to set the cube's properties for rendering and place it in the window
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();

	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
	actor->GetProperty()->SetColor( 255,0,0 );

	// Create a renderer, and render window
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	//vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();		// ###### We've already created the renderWindow this time ######
	ui->qvtkWidget->GetRenderWindow()->AddRenderer( renderer );									// ###### ask the QtVTKOpenGLWidget for its renderWindow ######

	// Link a renderWindowInteractor to the renderer (this allows you to capture mouse movements etc)  ###### Not needed with Qt ######
	//vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	//renderWindowInteractor->SetRenderWindow( ui->vtkWidget->GetRenderWindow() );				

	//Add light
	light = vtkSmartPointer<vtkLight>::New();
    light->SetLightTypeToHeadlight();
    light->SetIntensity( 1 );

	// add the light to the renderer after Render was called
	renderer->AddLight(light);

	// Add the actor to the scene
	renderer->AddActor(actor);
	renderer->SetBackground( 100,100,100 );

	// Setup the renderers's camera
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();

	// Render and interact
	//renderWindow->Render();					// ###### Not needed with Qt ######
	//renderWindowInteractor->Start();			// ###### Not needed with Qt ######
	//--------------------------------------------- /Code From Example 1 -------------------------------------------------------------------------*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionFileOpen_triggered() {
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open STL File"), "./", tr("STL Files(*.stl)"));
	std::string str = fileName.toUtf8().constData();
	reader->SetFileName(str.data());
	reader->Update();
	renderer->ResetCamera();
	ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
	if (ui->checkBox->isChecked()) {
		light->SetIntensity((float)(100 - position) / 100);
	}
	ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::on_checkBox_clicked(bool checked)
{
	if (checked) {
		light->SetIntensity((float)(100 - ui->Slider->value()) / 100);
	}
	else {
		light->SetIntensity(1);
	}
	ui->qvtkWidget->GetRenderWindow()->Render();
}


// Clip Filter --------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_ClipBox_clicked(bool checked) {
        if (checked) {

			planeLeft->SetOrigin(0.0, 0.0, 0.0);
			planeLeft->SetNormal(-1.0, 0.0, 0.0);
			clipfilter->SetInputConnection(reader->GetOutputPort());
			clipfilter->SetClipFunction(planeLeft.Get());
			mapper->SetInputConnection(clipfilter->GetOutputPort());

        }
		else {
			shrinkfilter->SetInputConnection(reader->GetOutputPort());
			shrinkfilter->SetShrinkFactor(1);
			shrinkfilter->Update();
			mapper->SetInputConnection(shrinkfilter->GetOutputPort());
		}

	ui->qvtkWidget->GetRenderWindow()->Render();
}

// Shrink filter --------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_ShrinkBox_clicked(bool checked) {
	if (checked) {

		shrinkfilter->SetInputConnection(reader->GetOutputPort());
		shrinkfilter->SetShrinkFactor(.8);
		shrinkfilter->Update();
		mapper->SetInputConnection(shrinkfilter->GetOutputPort());
	}
	else {
		shrinkfilter->SetInputConnection(reader->GetOutputPort());
		shrinkfilter->SetShrinkFactor(1);
		shrinkfilter->Update();
		mapper->SetInputConnection(shrinkfilter->GetOutputPort());
	}

	ui->qvtkWidget->GetRenderWindow()->Render();
}