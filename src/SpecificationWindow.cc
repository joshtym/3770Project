#include <QtGui>
#include "SpecificationWindow.h"

SpecificationWindow::SpecificationWindow(QWidget* parent) : QDialog(parent)
{
   // Assign the layout and ensure that each window opens to the same size
   mainLayout = new QVBoxLayout;
   this->setLayout(mainLayout);
   this->resize(500, 400);
}

SpecificationWindow::~SpecificationWindow()
{
}

void SpecificationWindow::addWidget(QWidget* widgetToAdd)
{
   // Add the widget
   mainLayout->addWidget(widgetToAdd);
}
