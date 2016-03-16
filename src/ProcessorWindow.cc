#include <QtGui>
#include "ProcessorWindow.h"

ProcessorWindow::ProcessorWindow()
{
   // Ensure a starting empty vector
   boxOptions.clear();
   boxNames.clear();
   
   // Instantiate our vectors
   for (int i = 0; i < 4; ++i)
   {
      boxOptions.push_back(new QCheckBox());
      boxNames.push_back(new QLabel());
   }
   
   boxNames[0]->setText("Selection 1");
   boxNames[1]->setText("Selection 2");
   boxNames[2]->setText("Selection 3");
   boxNames[3]->setText("Selection 4");
   
   QHBoxLayout* mainWidgetLayout = new QHBoxLayout();
   QVBoxLayout* leftSideLayout = new QVBoxLayout();
   QVBoxLayout* rightSideLayout = new QVBoxLayout();
   
   for (int i = 0; i < 4; ++i)
   {
      leftSideLayout->addWidget(boxNames[i]);
      rightSideLayout->addWidget(boxOptions[i]);
   }
   
   mainWidgetLayout->addLayout(leftSideLayout);
   mainWidgetLayout->addLayout(rightSideLayout);
   
   this->setLayout(mainWidgetLayout);
}

ProcessorWindow::~ProcessorWindow()
{
}
