#include <QtGui>
#include "ProcessorWindow.h"

ProcessorWindow::ProcessorWindow()
{
   // Layout declarations
   QHBoxLayout* mainWidgetLayout = new QHBoxLayout();
   QVBoxLayout* leftSideLayout = new QVBoxLayout();
   QVBoxLayout* rightSideLayout = new QVBoxLayout();
   
   // Ensure a starting empty vector
   boxOptions.clear();
   boxNames.clear();
   
   // Instantiate our vectors
   for (int i = 0; i < 4; ++i)
   {
      boxOptions.push_back(new QCheckBox());
      boxNames.push_back(new QLabel());
      leftSideLayout->addWidget(boxNames[i]);
      rightSideLayout->addWidget(boxOptions[i]);
   }
   
   boxNames[0]->setText("CPU 1");
   boxNames[1]->setText("CPU 2");
   boxNames[2]->setText("CPU 3");
   boxNames[3]->setText("CPU 4");
   
   boxNames[0]->setToolTip("<html><img src=https://raw.githubusercontent.com/plu/JPSimulatorHacks/master/Data/test.png/></html>");
   
   mainWidgetLayout->addLayout(leftSideLayout);
   mainWidgetLayout->addLayout(rightSideLayout);
   
   this->setLayout(mainWidgetLayout);
   
   // Connect our check boxes to ensure that only one check box can be checked at a time
   connect(boxOptions[0], SIGNAL(stateChanged(int)), this, SLOT(updateBoxOne(int)));
   connect(boxOptions[1], SIGNAL(stateChanged(int)), this, SLOT(updateBoxTwo(int)));
   connect(boxOptions[2], SIGNAL(stateChanged(int)), this, SLOT(updateBoxThree(int)));
   connect(boxOptions[3], SIGNAL(stateChanged(int)), this, SLOT(updateBoxFour(int)));
}

ProcessorWindow::~ProcessorWindow()
{
}

void ProcessorWindow::updateBoxOne(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[1]->setCheckState(Qt::Unchecked);
      boxOptions[2]->setCheckState(Qt::Unchecked);
      boxOptions[3]->setCheckState(Qt::Unchecked);
   }
}

void ProcessorWindow::updateBoxTwo(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[0]->setCheckState(Qt::Unchecked);
      boxOptions[2]->setCheckState(Qt::Unchecked);
      boxOptions[3]->setCheckState(Qt::Unchecked);
   }
}

void ProcessorWindow::updateBoxThree(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[0]->setCheckState(Qt::Unchecked);
      boxOptions[1]->setCheckState(Qt::Unchecked);
      boxOptions[3]->setCheckState(Qt::Unchecked);
   }
}

void ProcessorWindow::updateBoxFour(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[0]->setCheckState(Qt::Unchecked);
      boxOptions[1]->setCheckState(Qt::Unchecked);
      boxOptions[2]->setCheckState(Qt::Unchecked);
   }
}
