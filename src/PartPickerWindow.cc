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
   mbWindow = new MotherboardWindow();
   
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
   primaryLayout->addWidget(mbWindow);
   mbWindow->hide();
   
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
      {
         cpuWindow->show();
         mbWindow->hide();
      }
      else if (newTab == 1)
      {
         cpuWindow->hide();
         mbWindow->show();
      }
      else
      {
         cpuWindow->hide();
         mbWindow->hide();
      }
      currentTab = newTab;
   }
}
