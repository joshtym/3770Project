#include <QtGui>
#include "MotherboardWindow.h"

MotherboardWindow::MotherboardWindow()
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
   
   boxNames[0]->setText("Motherboard 1");
   boxNames[1]->setText("Motherboard 2");
   boxNames[2]->setText("Motherboard 3");
   boxNames[3]->setText("Motherboard 4");
   
   mainWidgetLayout->addLayout(leftSideLayout);
   mainWidgetLayout->addLayout(rightSideLayout);
   
   this->setLayout(mainWidgetLayout);
   
   // Connect our check boxes
   connect(boxOptions[0], SIGNAL(stateChanged(int)), this, SLOT(updateBoxOne(int)));
   connect(boxOptions[1], SIGNAL(stateChanged(int)), this, SLOT(updateBoxTwo(int)));
   connect(boxOptions[2], SIGNAL(stateChanged(int)), this, SLOT(updateBoxThree(int)));
   connect(boxOptions[3], SIGNAL(stateChanged(int)), this, SLOT(updateBoxFour(int)));
}

MotherboardWindow::~MotherboardWindow()
{
}

void MotherboardWindow::updateBoxOne(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[1]->setCheckState(Qt::Unchecked);
      boxOptions[2]->setCheckState(Qt::Unchecked);
      boxOptions[3]->setCheckState(Qt::Unchecked);
   }
}

void MotherboardWindow::updateBoxTwo(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[0]->setCheckState(Qt::Unchecked);
      boxOptions[2]->setCheckState(Qt::Unchecked);
      boxOptions[3]->setCheckState(Qt::Unchecked);
   }
}

void MotherboardWindow::updateBoxThree(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[0]->setCheckState(Qt::Unchecked);
      boxOptions[1]->setCheckState(Qt::Unchecked);
      boxOptions[3]->setCheckState(Qt::Unchecked);
   }
}

void MotherboardWindow::updateBoxFour(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[0]->setCheckState(Qt::Unchecked);
      boxOptions[1]->setCheckState(Qt::Unchecked);
      boxOptions[2]->setCheckState(Qt::Unchecked);
   }
}
