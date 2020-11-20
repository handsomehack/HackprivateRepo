#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stockitem.h"
#include "edititemdialog.h"
#include "stockitemlistmodel.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QAction>
#include <QFile>
#include <QTextStream>
#include <QDataStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	// Link the ListModel to the ListView
	ui->listView->setModel( &stockList );
	// Tell this list view to only accept single selections
	ui->listView->setSelectionBehavior( QAbstractItemView::SelectItems );

	connect( ui->addButton, &QPushButton::released, this, &MainWindow::handleAddButton );
	connect( ui->editButton, &QPushButton::released, this, &MainWindow::handleEditButton );
	connect( ui->removeButton, &QPushButton::released, this, &MainWindow::handleRemoveButton );
	connect( this, &MainWindow::statusUpdateMessage, ui->statusBar, &QStatusBar::showMessage );

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::handleAddButton() {

	StockItem item;
	QModelIndexList selectedList;
	selectedList = ui->listView->selectionModel()->selectedIndexes();
	if( selectedList.length() == 1 ) {
		stockList.insertItem( item,selectedList[0] );

	} else {
		stockList.addItem( item );
	}
	emit statusUpdateMessage( QString("Add button was clicked"), 0 );

}


void MainWindow::handleEditButton() {

	EditItemDialog dialog( this );
	emit statusUpdateMessage( QString("Edit button was clicked"), 0 );
	QModelIndexList selectedList;
	selectedList = ui->listView->selectionModel()->selectedIndexes();

	if( selectedList.length() == 1 ) {
		// selectedList is a list of all selected items in the listView. Since we set its
		// behaviour to single selection, were only interested in the first selecteded item.
		StockItem item = stockList.getItem( selectedList[0] );
		if( dialog.runDialog( item ) ) {
			// user clicked ok, need to update item in list...
			stockList.setItem( item, selectedList[0] );
		}
	} else {
		emit statusUpdateMessage( QString("No item selected to edit!"), 0 );
	}
}

void MainWindow::handleRemoveButton() {

	QModelIndexList selectedList;
	selectedList = ui->listView->selectionModel()->selectedIndexes();
	emit statusUpdateMessage( QString("Remove button was clicked"), 0 );
	if( selectedList.length() == 1 ) {
		stockList.removeItem(selectedList[0] );
	}else {
		emit statusUpdateMessage( QString("No item selected to remove!"), 0 );
	}
}

void MainWindow::on_actionSave_triggered(){
	QString item;
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                           "/home/jana/untitled.png",
                           tr("Text File (*.txt)"));
	QFile file(fileName);
	file.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream out(&file);
	for (int i = 0; i < stockList.rowCount(); i++){
		out <<"Item:" << i+1 << " : " << stockList.getItemName(i) << " Cost: " << stockList.getItemCost(i) << " StockLevel: " << stockList.getItemStock(i)<< "\n";
	}
	file.close();
}




