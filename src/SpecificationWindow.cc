#include <QtGui>
#include "SpecificationWindow.h"

SpecificationWindow::SpecificationWindow(QWidget* parent) : QDialog(parent)
{
   mainLayout = new QVBoxLayout;
   this->setLayout(mainLayout);
   //this->setWidgetResizable(true);
}

SpecificationWindow::~SpecificationWindow()
{
}

void SpecificationWindow::addWidget(QWidget* widgetToAdd)
{
   mainLayout->addWidget(widgetToAdd);
}
