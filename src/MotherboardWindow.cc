#include <QtGui>
#include <iostream>
#include "MotherboardWindow.h"

MotherboardWindow::MotherboardWindow()
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
   
   itemPrices[0]->setText("$209.99");
   itemPrices[1]->setText("$144.99");
   itemPrices[2]->setText("$84.99");
   itemPrices[3]->setText("$219.99");
   itemPrices[4]->setText("$149.99");
   itemPrices[5]->setText("$99.99");
   
   boxOptions[0]->setText("High End AMD Motherboard");
   boxOptions[1]->setText("Middle Range AMD Motherboard");
   boxOptions[2]->setText("Low End AMD Motherboard");
   boxOptions[3]->setText("High End Intel Motherboard");
   boxOptions[4]->setText("Mid Range Intel Motherboard");
   boxOptions[5]->setText("Low End Intel Motherboard");
   
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
      boxOptions[4]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
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
      boxOptions[4]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
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
      boxOptions[4]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
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
      boxOptions[4]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
   }
}

void MotherboardWindow::updateBoxFive(int newState)
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

void MotherboardWindow::updateBoxSix(int newState)
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
