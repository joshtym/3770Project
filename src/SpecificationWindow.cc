#include <QtGui>
#include "SpecificationWindow.h"

SpecificationWindow::SpecificationWindow(QWidget* parent) : QDialog(parent)
{
   mainLayout = new QVBoxLayout;
   this->setLayout(mainLayout);
   this->resize(500, 400);
}

SpecificationWindow::~SpecificationWindow()
{
}

void SpecificationWindow::addWidget(QWidget* widgetToAdd)
{
   mainLayout->addWidget(widgetToAdd);
}
