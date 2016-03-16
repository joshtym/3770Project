#include <QtGui>
#include "PartPickerWindow.h"

PartPickerWindow::PartPickerWindow()
{
   // Central widget declaration
   QWidget* centralWidget = new QWidget;
   
   // Create a layout
   QVBoxLayout* primaryLayout = new QVBoxLayout;
   
   // Initialize our tab bar
   tabBar = new QTabBar();
   
   // Add in our tabs
   tabBar->addTab("CPU");
   tabBar->addTab("MotherBoard");
   tabBar->addTab("RAM");
   tabBar->addTab("HDD / SDD");
   
   // Add in our tab into the layout
   primaryLayout->addWidget(tabBar);
   
   // Central Widget assignment and Layout assignment
   setCentralWidget(centralWidget);
   centralWidget->setLayout(primaryLayout);
   
   // Update our window when the tab is changed
   connect(tabBar, SIGNAL(currentChanged(int)), this, SLOT(updateWindow(int)));
}

void PartPickerWindow::updateWindow(int currentTab)
{
   /// TODO: Add in logic to update the window
}
