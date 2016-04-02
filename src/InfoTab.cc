#include <QtGui>
#include "InfoTab.h"

InfoTab::InfoTab()
{
   // The main layout
   QVBoxLayout* mainLayout = new QVBoxLayout();
   
   // Variable instantiations
   
   // Ensure a starting empty vector
   layouts.clear();
   information.clear();

   information.push_back(new QLabel());
   information.push_back(new QLabel());
   information.push_back(new QLabel());
   
   
   

   
   information[0]->setText("Budget is shown in the bottom left corner as well as the current amount spent is shown in the bottom right. Individual part selections will be limited based on the budget set and those products whose selection will exceed the set budget will not be dislpayed in the selection tabs");

   information[1]->setText("Displayed parts will be limited based on compatibility with parts selected prior.This particularly concerns the CPU and Mother board components of the selection ");

   information[2] ->setText("When all parts have been selected they may be confirmed within the confirmation tab. This clears the selected components within each of the tabs and resets the program to its initial state.");
   // set word wrap for the labels
   information[0]->setWordWrap(true);
   information[1]->setWordWrap(true);
   information[2]->setWordWrap(true);
   // add boxes to layouts and set 
   layouts.push_back(new QHBoxLayout());
   layouts.push_back(new QHBoxLayout());
   layouts.push_back(new QHBoxLayout());
   layouts[0]->addWidget(information[0]);
   layouts[1]->addWidget(information[1]);
   layouts[2]->addWidget(information[2]);

   mainLayout->addLayout(layouts[0]);
   mainLayout->addLayout(layouts[1]);
   mainLayout->addLayout(layouts[2]);
      
   
   this->setLayout(mainLayout);
}

InfoTab::~InfoTab()
{
   
}


void InfoTab::resizeEvent(QResizeEvent* resizeEvent)
{
   // Handle the resize of the window for the assets
  
}

void InfoTab::budgetupdated(double budget)
{
}
