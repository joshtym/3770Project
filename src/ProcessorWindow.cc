#include <QtGui>
#include <iostream>
#include "ProcessorWindow.h"

ProcessorWindow::ProcessorWindow()
{
   // Layout declarations
   QHBoxLayout* mainWidgetLayout = new QHBoxLayout();
   QVBoxLayout* leftSideLayout = new QVBoxLayout();
   QVBoxLayout* middleLayout = new QVBoxLayout();
   QVBoxLayout* rightSideLayout = new QVBoxLayout();
   
   // Ensure a starting empty vector
   boxOptions.clear();
   boxNames.clear();
   itemPrices.clear();
   
   // Instantiate our vectors
   for (int i = 0; i < 6; ++i)
   {
      boxOptions.push_back(new QCheckBox());
      boxNames.push_back(new QLabel());
      itemPrices.push_back(new QLabel());
      
      leftSideLayout->addWidget(boxOptions[i]);
      rightSideLayout->addWidget(boxNames[i]);
      middleLayout->addWidget(itemPrices[i]);
      
      boxNames[i]->setText("View Now");
      
      boxNames[i]->setAlignment(Qt::AlignRight);
      itemPrices[i]->setAlignment(Qt::AlignRight);
   }
   
   itemPrices[0]->setText("$259.99");
   itemPrices[1]->setText("$159.99");
   itemPrices[2]->setText("$109.99");
   itemPrices[3]->setText("$499.99");
   itemPrices[4]->setText("$339.99");
   itemPrices[5]->setText("$179.99");
   
   boxOptions[0]->setText("High End AMD CPU");
   boxOptions[1]->setText("Middle Range AMD CPU");
   boxOptions[2]->setText("Low End AMD CPU");
   boxOptions[3]->setText("High End Intel CPU");
   boxOptions[4]->setText("Mid Range Intel CPU");
   boxOptions[5]->setText("Low End Intel CPU");
   
   mainWidgetLayout->addLayout(leftSideLayout);
   mainWidgetLayout->addLayout(middleLayout);
   mainWidgetLayout->addLayout(rightSideLayout);
   
   this->setLayout(mainWidgetLayout);
   
   // Connect our check boxes
   connect(boxOptions[0], SIGNAL(stateChanged(int)), this, SLOT(updateBoxOne(int)));
   connect(boxOptions[1], SIGNAL(stateChanged(int)), this, SLOT(updateBoxTwo(int)));
   connect(boxOptions[2], SIGNAL(stateChanged(int)), this, SLOT(updateBoxThree(int)));
   connect(boxOptions[3], SIGNAL(stateChanged(int)), this, SLOT(updateBoxFour(int)));
   connect(boxOptions[4], SIGNAL(stateChanged(int)), this, SLOT(updateBoxFive(int)));
   connect(boxOptions[5], SIGNAL(stateChanged(int)), this, SLOT(updateBoxSix(int)));
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
      boxOptions[4]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
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
      boxOptions[4]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
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
      boxOptions[4]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
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
      boxOptions[4]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
   }
}

void ProcessorWindow::updateBoxFive(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[0]->setCheckState(Qt::Unchecked);
      boxOptions[1]->setCheckState(Qt::Unchecked);
      boxOptions[2]->setCheckState(Qt::Unchecked);
      boxOptions[3]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
   }
}

void ProcessorWindow::updateBoxSix(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[0]->setCheckState(Qt::Unchecked);
      boxOptions[1]->setCheckState(Qt::Unchecked);
      boxOptions[2]->setCheckState(Qt::Unchecked);
      boxOptions[3]->setCheckState(Qt::Unchecked);
      boxOptions[4]->setCheckState(Qt::Unchecked);
   }
}
