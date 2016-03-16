#include <QtGui>
#include "PartPickerWindow.h"

PartPickerWindow::PartPickerWindow()
{
   // Central widget declaration
   QWidget* centralWidget = new QWidget();
   
   // Create a layout
   QVBoxLayout* primaryLayout = new QVBoxLayout();
   
   // Default our current tab to 0
   currentTab = 0;
   
   cpuWindow = new ProcessorWindow();
   
   // Initialize our tab bar
   tabBar = new QTabBar();
   
   // Add in our tabs
   tabBar->addTab("CPU");
   tabBar->addTab("MotherBoard");
   tabBar->addTab("RAM");
   tabBar->addTab("HDD / SDD");
   
   // Add in our tab into the layout
   primaryLayout->addWidget(tabBar);
   primaryLayout->addWidget(cpuWindow);
   
   // Central Widget assignment and Layout assignment
   setCentralWidget(centralWidget);
   centralWidget->setLayout(primaryLayout);
   
   // Update our window when the tab is changed
   connect(tabBar, SIGNAL(currentChanged(int)), this, SLOT(updateWindow(int)));
}

void PartPickerWindow::updateWindow(int newTab)
{
   /// TODO: Add in logic to update the window
   if (currentTab != newTab)
   {
      if (newTab == 0)
         cpuWindow->show();
      else
         cpuWindow->hide();
         
      currentTab = newTab;
   }
   
}
